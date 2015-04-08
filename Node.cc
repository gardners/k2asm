
#include "Node.h"
#include "Value.h"

Node::Node() : parent(0) {
  pos = SymTable::currLine();
}

void Node::setParent(Node* par, int ipos) {

  parent = par;
  
  if( (pos < 0) && (ipos < 0) ) INT_ERR << "fileposition error\n";
  else if(ipos > -1) pos = ipos;

}

Node* Node::getParent() {
  return parent;
}

bool Node::hasChilds() {
  return childCount() == 0;
}

Node* Node::find(int name, bool local) {
  if(parent && !local) { return parent->find(name); }
  return 0;  
}

Value* Node::replaceEval(Value* v) {
  if(v) {
    Value* res = v->eval();
    res->setParent(this,getPos());
    return res;
  }
  return v;
}

int Node::lookupName() {
  return SymTable::NO_NAME;
}

int Node::localName() {
  return SymTable::NO_NAME;
}

int Node::globalName() {
  return localName();
}

string Node::strName() {
  return SymTable::revLookup(localName());
}

bool Node::receive(NodeVisitor* vis) {
  return vis->procNode(this);
}

int Node::minCodeLen() { 
  return 0; 
}

int Node::maxCodeLen() { 
  return 0; 
}

int Node::codeLen() { 
  return 0; 
}

Node::~Node() {
  //DBG << "destroy " << typeid(*this).name() << " " << strName() << " " << (void*) this << "\n";
}
