
#include <fstream>
#ifdef HAVE_POPT
#include <popt.h>

#else

#include <unistd.h>
#define POPT_ARG_NONE		0	
#define POPT_ARG_STRING		1	
#define POPT_ARG_INT		2	
#define POPT_ARG_LONG		3	
#define POPT_ARG_INCLUDE_TABLE	4	
#define POPT_ARG_CALLBACK	5	

#define RELEASE_NAME "CAULDRON"

struct poptOption {
  const char * longName;
  char shortName;
  int argInfo;
  void * arg;
  int val;
  const char * descrip;
  const char * argDescrip;
};
#endif

#include <iostream>

#include "RootScope.h"
#include "Value.h" 

#include "StdTreeBuilder.h"

#include "SymResolver.h"
#include "ValueResolver.h"
#include "PrettyPrinter.h"
#include "CodeGen.h"

using namespace std;

StdTreeBuilder* builder;
extern FILE* yyin;

int yyparse();

char* outfile = 0;
char* expfile = 0;
char* dncfile = 0;
const char* infilename=NULL;
bool k2pp = false;
bool verbose = false;
bool version = false;
bool object = false;  
bool debug = false;  

#ifndef BINDIR
#define BINDIR "/usr/local/bin"
#endif

void opt_verbose(bool v) {
  verbose = v;
}

#ifdef YYDEBUG
extern int yydebug;
#endif

void opt_debug(bool v) {
  debug = v;
#ifdef YYDEBUG
  yydebug = v;
#endif
}


struct poptOption optionsTable[] = {
  { "outfile", 'o', POPT_ARG_STRING, &outfile, 0, "output file name" },
  { "export",  'x', POPT_ARG_STRING, &expfile, 0, "target file for exported symbols" },
  { "dnc",     'c', POPT_ARG_STRING, &dncfile, 0, "target file for DNC information" },
  { "object",  'O', 0, 0, 'O',"write as object (without leading adress bytes)" },
  { "version", 'v', 0, 0, 'v',"show version information" },
  { "debug",   'd', 0, 0, 'd',"very verbose output" },
  { "verbose", 'V', 0, 0, 'V',"give some more info" },
  { "k2pp",    'k', 0, 0, 'k',"use k2pp for preprocessing" },
#ifdef HAVE_POPT
  POPT_AUTOHELP
#endif
  { NULL, 0, 0, NULL, 0 }
};

// alle Optionen, die keinen String als Argument haben
#define OPT_HANDLING				\
  case 'O': object = true; break;		\
  case 'v': version = true; break;		\
  case 'V': opt_verbose(true); break;		\
  case 'k': k2pp = true;break;			\
  case 'd': opt_debug(true); break;		\

#ifdef HAVE_POPT
bool setParams(int argc, char** argv_nc) {
  const char** argv = (const char**) argv_nc;
  poptContext optCon; 
  
  optCon = poptGetContext(NULL, argc, argv, optionsTable, 0);
  poptSetOtherOptionHelp(optCon, "infile");

  char c;
  while ((c = poptGetNextOpt(optCon)) >= 0) {
    switch (c) {
      OPT_HANDLING
    }
  }
  
  infilename = poptGetArg(optCon);
  
  if (c < -1) {
    cerr << poptBadOption(optCon, POPT_BADOPTION_NOALIAS) << ": " << poptStrerror(c) << "\n";
    return false;
  } 

  if (version) return true;

  if (infilename == 0) { 
    poptPrintUsage(optCon, stderr, 0);
    return false;
  }
  
  return true;
    
}

#else
// ohne popt auskommen muessen

void usage() {
  cerr << "Usage: " << PACKAGE << " infile" << endl;
  for (int i=0; optionsTable[i].shortName; i++) {
    cerr << "\t-" << optionsTable[i].shortName ;
    if (optionsTable[i].argInfo == POPT_ARG_STRING) 
      cerr << " STRING";
    cerr << "\t" << optionsTable[i].descrip << endl;
  }
  exit(1);
}

bool setParams(int argc, char** argv) {
  char ch;
  char optstring[128];
  int optstring_len = sizeof(optstring)/sizeof(char);

  int i=0, opt_idx=0;

  // len-2, um auch beim einfuegen von zwei zeichen noch platz
  // fuer terminierende 0 zu haben
  while (opt_idx < optstring_len-2) {
    if (optionsTable[i].shortName == 0) break;
    optstring[opt_idx++] = optionsTable[i].shortName;
    if (optionsTable[i].argInfo != POPT_ARG_NONE) 
      optstring[opt_idx++] = ':';
    i++;
  }

  optstring[opt_idx] = 0;

  while ((ch = getopt(argc, argv, optstring)) != -1)
    switch (ch) {
      OPT_HANDLING
	default:
      
      for (i=0; optionsTable[i].shortName; i++) 
	if (optionsTable[i].shortName == ch) break;
      
      // keine passende Option gefunden
      if (!optionsTable[i].shortName) usage();
      
      if (optionsTable[i].argInfo == POPT_ARG_STRING) {
	if (optionsTable[i].arg)
	  (*((char**) optionsTable[i].arg)) = optarg;
      } else {
	cerr << "Only string arguments handled so far" << endl;
	usage();
      }
    }
  argc -= optind;
  argv += optind;
  
  if (version) return true;
  if (!argc) usage();

  infilename = *argv;
  return true;
}

#endif // HAVE_POPT


int parseFile(FILE* inFile, StdTreeBuilder *thebuilder, const char* filename="<input>") {
  // erst mal die haesslichen globals setzen...
  yyin = inFile;
  if (!yyin) {
    cerr << "input not readable" << endl;
    exit(1);
  }
  builder = thebuilder;
  if (!builder) { 
    cerr << "no builder available" << endl;
    return 2;
  }

  SymTable::init();
  SymTable::currFile(filename);

  builder->parse();
  yyparse();

  if(SymTable::errCount()) return EXIT_FAILURE;

  if(verbose) cout << "parse success\n";
  SymTable::lex_line = -1;

  return 0;
}


int main(int argc, char** argv) {
  int result_code = 0;
  FILE *inFile;

  if(! setParams(argc,argv) ) exit (-1);

  if(version) {
    cout << PACKAGE << " version " << VERSION << " (c) Boerje Sieling 2003" << endl;
    exit(1);
  }
  
  if (k2pp) {
    string cmd;
    char *k2pp_env = getenv("K2PP");
    if (k2pp_env) 
      cmd = k2pp_env;
    else
      cmd = BINDIR "/k2pp";

    cmd += " -l ";
    cmd += infilename;
    inFile = popen(cmd.c_str(),"r");
  } else {
    inFile = fopen(infilename,"r");
  }

  builder = new StdTreeBuilder();
  result_code = parseFile(inFile, builder, infilename);
  if (result_code) exit(result_code);

  if (k2pp) {
    if (pclose(inFile)) {
      result_code = EXIT_FAILURE;
    } 
  } else {
      if (fclose(inFile)) {
	cerr << "close file failed !?!" << endl;
	exit(EXIT_FAILURE);
      }
  }

  if(verbose) cerr << "resolving names\n";
  SymResolver sr;
  sr.visit(builder->getRootScope());
  if(SymTable::errCount() > 0) exit(EXIT_FAILURE);

  if(verbose) cerr << "resolving values\n";
  ValueResolver vr;
  vr.visit(builder->getRootScope());
  if(SymTable::errCount() > 0) exit(EXIT_FAILURE);

  if(verbose) cerr << "pass 2\n";
  vr.visit(builder->getRootScope());
  if(SymTable::errCount() > 0) exit(EXIT_FAILURE);

  if(verbose) cerr << "pass 3\n";
  vr.visit(builder->getRootScope());
  if(SymTable::errCount() > 0) exit(EXIT_FAILURE);

  if(debug) {
    PrettyPrinter pp(cout);
    pp.visit(builder->getRootScope());
  }

  ofstream dnc(dncfile);
  
  if(expfile && outfile) {

    ofstream out(outfile);
    ofstream oexp(expfile);
    CodeGen cg(out,oexp);
    if (dncfile) {
      cg.setDncStream(dnc);
    }

    cg.visit(builder->getRootScope());
    if(SymTable::errCount() > 0) {
      out.close();
      oexp.close();
      remove(outfile);
      remove(expfile);
      exit(EXIT_FAILURE);
    }

  } else if(outfile) {

    ofstream out(outfile);

    CodeGen cg(out);
    if (dncfile) {
      cg.setDncStream(dnc);
    }

    cg.setObj(object);
    cg.visit(builder->getRootScope());
    if(SymTable::errCount() > 0) {
      out.close();
      remove(outfile);
      exit(EXIT_FAILURE);
    }

  }

  return result_code;
}
