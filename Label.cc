
#include "Label.h"

Label::Label (int name) : NamedValue(name), pc(-1), minpc(-1), maxpc(-1) {
}

void Label::setPC(int pc, int minpc, int maxpc) {
  this->pc = pc;
  if(minpc >= 0) this->minpc = minpc;
  if(maxpc >= 0) this->maxpc = maxpc;
}

int Label::childCount() const {
  return 0;
}

Node* Label::getChild(int idx) const {
  return 0;
}

bool Label::isResolved() {
  return pc >= 0;
}

bool Label::resolve() {
  return pc >= 0;
}

Number Label::getValue() {
  return pc;
}

bool Label::isLabel() {
  return true;
}

Value* Label::eval() {
  if(pc < 0) return this;
  else {
    return Value::constValue(pc);
  }
}

bool Label::pcAwareResolving() {
  return true;
}

int Label::valueLen() {
  if(pc >= 0) return Value::calcLen(pc);
  else if( (minpc < 0) || (maxpc < 0) ) return -1;
  else if(minpc > 0xff) return 2;
  else if(maxpc < 0x100) return 1;
  else return -1;
}

bool Label::receive(NodeVisitor* vis) {
  return vis->procLabel(this);
}

string Label::strName() {
  return SymTable::revLookup(vName);
}
  
int Label::lookupName() {
  return vName;
}

int Label::localName() {
  return vName;
}

Label::~Label() {
  cerr << "Label destroyed " << strName() << "\n";
}

void Label::setParent(Node* par, int ipos) {
  if(!getParent()) Node::setParent(par,ipos);
}
  
