
#ifndef _SYM_TABLE_HEADER
#define _SYM_TABLE_HEADER

#include <vector>
#include <string>
#include <map>

using namespace std;

class Node;

class SymTable {

  static map<string,int> table;
  static vector<string> names;
  static int current;

  static int numVal(char c);
  static int errCnt;

  static string currentFile;

public:

  static int lex_line;
  static int line;
  
  static int NO_NAME;
  static int CONT;
  static int BREAK;
  static int END;
  static int RETURN;
  static int RTS;
  static int PO_ORG;
  static int PO_BYTE;
  static int PO_WORD;
  static int PO_ENC;
  static int PO_STRING;
  static int PO_ALIGN;
  static int PO_BUF;
  static int PO_ENCODING;

  static int mkLabel(const string& symbol);
  static int lookup(const string& symbol);
  static int makeGlobal(int scope, int local);
  static const string& revLookup(int id);
  static void init();

  static int str2Num(const string& str, int base);

  static void parseError(const char* s);
  static void err();
  static int errCount();
  
  static const string& currFile();
  static void currFile(const string& name);
  static int currLine();
};

#endif // _SYM_TABLE_HEADER
