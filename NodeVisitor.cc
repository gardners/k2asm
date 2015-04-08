
#include "NodeTypes.h"
#include "NodeVisitor.h"

bool NodeVisitor::visitChilds(Node* n) {
  
  for(int k=0;k<n->childCount();k++) {
    if (n->getChild(k)->receive(this)) return true; 
  }
  return false;
}
  
bool NodeVisitor::visitNode(Node* n) {
  return n->receive(this);
}
  
bool NodeVisitor::visitTopDown(Node* n) {
  
  if(n->receive(this)) return true;
    
  for(int k=0;k<n->childCount();k++) {
    visitTopDown(n->getChild(k));
  }
  
  return false;
}
  
bool NodeVisitor::visitBottomUp(Node* n) {
  for(int k=0;k<n->childCount();k++) {
    if(visitBottomUp(n->getChild(k))) return true; 
  }

  return n->receive(this);
}

/*
bool NodeVisitor::visitBackwards(Node* n) {
  for(int k=0;k<n->childCount();k++) {
    if(visitBottomUp(n->getChild(k))) return true; 
  }

  return n->receive(this);
}
*/
  
bool NodeVisitor::visitUpwards(Node *n) {

  if(n == 0) return false;

  for(int k=0;k<n->childCount();k++) {
    if(n->getChild(k)->receive(this)) return true; 
  }
  return visitUpwards(n->getParent());

}



bool NodeVisitor::procScope(Scope* n) { return procNode(n); }
bool NodeVisitor::procRootScope(RootScope* n) { return procScope(n); }
bool NodeVisitor::procNamedScope(NamedScope* n) { return procScope(n); }
bool NodeVisitor::procOpcode(Opcode* n) { return procNode(n); }
bool NodeVisitor::procLabel(Label* n) { return procValue(n); }
bool NodeVisitor::procValue(Value* n) { return procNode(n); }
bool NodeVisitor::procExpr(Expr* n) { return procNode(n); }
bool NodeVisitor::procLookup(Lookup* n) { return procValue(n); }
bool NodeVisitor::procDefinition(Definition* n) { return procValue(n); }
bool NodeVisitor::procByteValue(ByteValue* n) { return procValue(n); }
bool NodeVisitor::procWordValue(WordValue* n) { return procValue(n); }
bool NodeVisitor::procValueList(ValueList* n) { return procNode(n); }
bool NodeVisitor::procByteBuffer(ByteBuffer* n) { return procNode(n); }
