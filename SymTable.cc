
#include <iostream>
#include "SymTable.h"
#include "Opcode.h"

using namespace std;

extern OpcodeEntry OP_LIST[];

map<string,int> SymTable::table;
vector<string> SymTable::names;
int SymTable::current;

string SymTable::currentFile;

int SymTable::lex_line = 1;
int SymTable::line = 0;
int SymTable::errCnt;

int SymTable::NO_NAME;
int SymTable::CONT;
int SymTable::BREAK;
int SymTable::END;
int SymTable::RTS;
int SymTable::RETURN;
int SymTable::PO_ORG;
int SymTable::PO_BYTE;
int SymTable::PO_WORD;
int SymTable::PO_ENC;
int SymTable::PO_STRING;
int SymTable::PO_ALIGN;
int SymTable::PO_BUF;
int SymTable::PO_ENCODING;



int SymTable::lookup(const string& symbol) {

  if(table.find(symbol) != table.end()) { 
    return table[symbol];
  } else {
    int next = current++;
    table[symbol] = next;
    names.push_back(symbol);
    return next;
  }

}

int SymTable::mkLabel(const string& symbol) {
  return lookup(symbol.substr(0,symbol.size()-1));
}

int SymTable::makeGlobal(int scope, int local) {
    
  string sc = names[scope];
  string lo = names[local];
    
  string name = sc + "." + lo;
  return lookup(name);

}

const string& SymTable::revLookup(int id) {
  return names[id];
}

void SymTable::init() {

  lex_line = 1;
  line = 0;

  for(int k=0;Opcode::OP_LIST[k].mnomic;k++) {
    lookup(Opcode::OP_LIST[k].mnomic);
  }

  NO_NAME = lookup("");
  BREAK = lookup("_break");
  CONT = lookup("_cont");
  END = lookup("_end");
  RTS = lookup("rts");
  RETURN = lookup("_return");
  PO_ORG = lookup(".org");
  PO_BYTE = lookup(".byte");
  PO_WORD = lookup(".word");
  PO_ENC = lookup(".enc");
  PO_STRING = lookup(".str");
  PO_ALIGN = lookup(".align");
  PO_BUF = lookup(".buf");
  PO_ENCODING = lookup(".encoding");
  
}


int SymTable::numVal (char c) {

  switch(c) {

  case '0' : return 0;
  case '1' : return 1;
  case '2' : return 2;
  case '3' : return 3;
  case '4' : return 4;
  case '5' : return 5;
  case '6' : return 6;
  case '7' : return 7;
  case '8' : return 8;
  case '9' : return 9;
  case 'a' : return 10;
  case 'b' : return 11;
  case 'c' : return 12;
  case 'd' : return 13;
  case 'e' : return 14;
  case 'f' : return 15;
  case 'A' : return 10;
  case 'B' : return 11;
  case 'C' : return 12;
  case 'D' : return 13;
  case 'E' : return 14;
  case 'F' : return 15;
  case '?' : return 0;

  default : return -1;
  }

}
  
int SymTable::str2Num(const string& str, int base) {
  int l = str.length();
  int pot = 1;
  int res = 0;

  int prefix = base == 10 ? -1 : 0;

  for(int k = l - 1; k>prefix ;k--) {
    res += numVal(str[k]) * pot;
    pot *= base;
  }
  return res;
}

void SymTable::parseError(const char* s) {
  cerr << currentFile << ":" << currLine() << ":" << s << "\n";
  errCnt++;
}

void SymTable::err() {
  errCnt++;
}

int SymTable::errCount() {
  int res = errCnt;
  errCnt = 0;
  return res;
}

const string& SymTable::currFile() { 
  return currentFile; 
}

void SymTable::currFile(const string& name) { 
  currentFile = name; 
}

int SymTable::currLine() {
  if (line != 0) return line;
  return lex_line;
}
