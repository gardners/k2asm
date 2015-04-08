
#include "Lookup.h"

Lookup::Lookup(int ref) : Value(), rName(ref), val(0) {
}

Lookup::Lookup(Value* v) : Value(), rName(SymTable::NO_NAME), val(v) {
}

int Lookup::localName() { 
  return rName; 
}

int Lookup::lookupName() { 
  return SymTable::NO_NAME; 
}

int Lookup::childCount() const {
  return (val != 0 ? 1 : 0);
}

Node* Lookup::getChild(int idx) const {
  return val;
}

bool Lookup::isResolved() {
  return (val != 0) && val->isResolved();
}

Number Lookup::getValue() {
  if(!val || !val->isResolved()) INT_ERR << "accessing unresolved value\n";
  return val != 0 ? val->getValue() : Number(0);
}

bool Lookup::resolve() {
  return isResolved();
}

bool Lookup::resolveName() {
  if(!val) 
    val = dynamic_cast<Value*>(getParent()->find(rName));
  
  return val != 0;

}

Value* Lookup::eval() {
  if(val) {
    val->resolve();
    Value* res = replaceEval(val);
    delete this;
    return res;
  }
  return this;
}

int Lookup::valueLen() {
  if(val) return val->valueLen();
  else return -1;
}

bool Lookup::receive(NodeVisitor* vis) {
  return vis->procLookup(this);
}

Lookup::~Lookup() {
  //cerr << "destroy lup: " << strName() << " " << (void*) this << "\n";
}
