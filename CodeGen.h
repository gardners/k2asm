

#ifndef _CODE_GEN_HEADER
#define _CODE_GEN_HEADER

#include <iostream>
#include "NodeVisitor.h"

using namespace std;

class CodeGen : public NodeVisitor {

  ostream& out;
  ostream& oexp;
  ostream* odnc;
  bool doexp;
  bool doobj;
  bool dodnc;

  int pc;
  int sizeContext;
  Node* root;

  void writeDNCData(const Number&, const Node* node);

 public:

  CodeGen(ostream& output);
  CodeGen(ostream& output, ostream& expout);

  void setDncStream(ostream& d);

  CodeGen* setObj(bool);

  bool visit(Node* n);
  
  virtual bool procNode(Node* n);
  //virtual bool procScope(Scope* n);
  virtual bool procRootScope(RootScope* n);
  //virtual bool procNamedScope(NamedScope* n);
  virtual bool procOpcode(Opcode* n);
  virtual bool procLabel(Label* n);
  virtual bool procLookup(Lookup* n);
  virtual bool procDefinition(Definition* n);
  virtual bool procByteValue(ByteValue* n);
  virtual bool procWordValue(WordValue* n);
  virtual bool procValueList(ValueList* n);
  virtual bool procByteBuffer(ByteBuffer* n); 
  
};

#endif
