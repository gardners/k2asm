
#include <iomanip>
#include "ValueList.h"
#include "ConstValue.h"

ValueList::ValueList(int ty, size_t s, Value** v) : type(ty), size(s), vals(v)  {
}

Node* ValueList::getChild(int idx) const {
  return vals[idx];
}

bool ValueList::hasChilds() {
  return true;
}

int ValueList::childCount() const {
  return (int) size;
}

void ValueList::resolve() {
  
  for(size_t k = 0; k<size; k++) {
    vals[k]->resolve();
    vals[k] = replaceEval(vals[k]);
  }
  
}

int ValueList::localName() {
  return type;
}

int ValueList::minCodeLen() {
  return size;
}

int ValueList::maxCodeLen() {
  return size*2;
}

int ValueList::codeLen() {
  if(type == SymTable::PO_BYTE) return size; 
  else if(type == SymTable::PO_WORD) return size*2;
  else INT_ERR << " unsupported pseudo opcode\n";
  return -1;
}

bool ValueList::receive(NodeVisitor* vis) {
  return vis->procValueList(this);
}
  
int ValueList::valueLen() {
  return (type == SymTable::PO_BYTE) ? 1 : 2;
}
