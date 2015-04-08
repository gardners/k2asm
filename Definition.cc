
#include "Definition.h"

Definition::Definition(int name, Value* v) : NamedValue(name), val(v) {
  val->setParent(this);
}

void Definition::setParent(Node* par, int ipos) {
  if(!getParent()) Node::setParent(par,ipos);
}

bool Definition::isResolved() {
  return val->isResolved();
}

Number Definition::getValue() {
  return val->getValue();
}

int Definition::childCount() const {
  return 1;
}

Node* Definition::getChild(int idx) const {
  return val;
}

Value* Definition::eval() {
  val = replaceEval(val);
  return val;
}

bool Definition::resolve() {
  eval();
  return val->isResolved();
}

int Definition::valueLen() {
  return val->valueLen();
}

int Definition::localName() { 
  return vName; 
}

int Definition::lookupName() { 
  return vName; 
}

int Definition::globalName() { 
  return vName; 
}

bool Definition::receive(NodeVisitor* vis) {
  return vis->procDefinition(this);
}

Definition::~Definition() {
  INT_ERR << "Definition deleted\n";
}
