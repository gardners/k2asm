
#ifndef _VALUE_RESOLVER_HEADER
#define _VALUE_RESOLVER_HEADER

#include "NodeVisitor.h"

class ValueResolver : public NodeVisitor {

  int minpc;
  int maxpc;
  int pc;

  void updatePC(Node* n);

 public:

  ValueResolver();

  virtual bool visit(Node* n);
  
  virtual bool procNode(Node* n);
  //virtual bool procScope(Scope* n);
  virtual bool procRootScope(RootScope* n);
  //virtual bool procNamedScope(NamedScope* n);
  virtual bool procOpcode(Opcode* n);
  virtual bool procLabel(Label* n);
  //virtual bool procValue(Value* n);
  //virtual bool procExpr(Expr* n);
  //virtual bool procLookup(Lookup* n);
  virtual bool procDefinition(Definition* n);
  //virtual bool procByteValue(ByteValue* n);
  //virtual bool procWordValue(WordValue* n);
  virtual bool procValueList(ValueList* n);
  virtual bool procByteBuffer(ByteBuffer* n);
  
};

#endif
