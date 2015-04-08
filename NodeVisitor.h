
#ifndef _NODE_VISITOR_HEADER
#define _NODE_VISITOR_HEADER

class Node;
class Value;
class Scope;
class RootScope;
class NamedScope;
class Label;
class Lookup;
class Expr;
class Opcode;
class Definition;
class ByteValue;
class WordValue;
class ValueList;
class ByteBuffer;
class FileInfo;

class NodeVisitor {

 protected:
  
  bool visitChilds(Node* n);  
  bool visitNode(Node* n);
  bool visitTopDown(Node* n);
  bool visitBottomUp(Node* n);
  bool visitUpwards(Node *n);
  
 public:

  virtual bool visit(Node* n) = 0;
  
  virtual bool procNode(Node* n) = 0;
  virtual bool procScope(Scope* n);
  virtual bool procRootScope(RootScope* n);
  virtual bool procNamedScope(NamedScope* n);
  virtual bool procOpcode(Opcode* n);
  virtual bool procLabel(Label* n);
  virtual bool procValue(Value* n);
  virtual bool procExpr(Expr* n);
  virtual bool procLookup(Lookup* n);
  virtual bool procDefinition(Definition* n);
  virtual bool procByteValue(ByteValue* n);
  virtual bool procWordValue(WordValue* n);
  virtual bool procValueList(ValueList* n);
  virtual bool procByteBuffer(ByteBuffer* n);
  
};

#endif
