
#ifndef _PRETTY_PRINTER_HEADER
#define _PRETTY_PRINTER_HEADER

#include <iostream>
#include "NodeVisitor.h"

using namespace std;

class PrettyPrinter : public NodeVisitor {

  ostream& out;
  bool doindent;
  int indent;
  int pc;
  
 public:

  PrettyPrinter(ostream& output=cout);

  bool visit(Node* n);
  
  void spaces(int count);
  
  virtual bool procNode(Node* n);
  virtual bool procScope(Scope* n);
  virtual bool procRootScope(RootScope* n);
  virtual bool procNamedScope(NamedScope* n);
  virtual bool procOpcode(Opcode* n);
  virtual bool procLabel(Label* n);
  virtual bool procLookup(Lookup* n);
  virtual bool procDefinition(Definition* n);
  virtual bool procValue(Value* n);
  virtual bool procByteValue(ByteValue* n);
  virtual bool procWordValue(WordValue* n);
  virtual bool procValueList(ValueList* n);
  virtual bool procByteBuffer(ByteBuffer* n); 

};

#endif
