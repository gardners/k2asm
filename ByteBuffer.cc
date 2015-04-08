
#include "ByteBuffer.h"

ByteBuffer::ByteBuffer(int m, Value *s, Value* v) : 
  Node(), mode(m), size(s), val(v), pc(-1), minpc(-1), maxpc(-1) {
  size->setParent(this);
  if(val) val->setParent(this);
}

int ByteBuffer::childCount() const {
  return (val) ? 2 : 1;
}

void ByteBuffer::setPC(int pc, int minpc, int maxpc) {
  this->pc = pc;
  if(minpc >= 0) this->minpc = minpc;
  if(maxpc >= 0) this->minpc = minpc;
}

int ByteBuffer::getFillValue() {
  if(val) return val->getValue();
  else return 0;
}

Node* ByteBuffer::getChild(int idx) const {
  if(idx == 0) return size;
  else return val;
}
  
int ByteBuffer::localName() {
  return mode;
}

int ByteBuffer::minCodeLen() {
  if(!size->isResolved()) return 0x0;
  int s = size->getValue();
  if(mode == SymTable::PO_BUF) return s;
  else return (minpc/s)*s+s-minpc;
}

int ByteBuffer::maxCodeLen() {
  if(!size->isResolved()) return 0xffff;
  int s = size->getValue();
  if(mode == SymTable::PO_BUF) return s;
  else return (maxpc/s)*s+s-maxpc;
}

int ByteBuffer::codeLen() {
  if(isResolved()) return size->getValue();
  else return -1;
}

bool ByteBuffer::receive(NodeVisitor* vis) {
  return vis->procByteBuffer(this);
}

bool ByteBuffer::isResolved() {
  bool vres = (val) ? val->isResolved() : true;
  if(mode==SymTable::PO_BUF) return size->isResolved() && vres;
  else return (pc >= 0) && size->isResolved() && vres;
}

void ByteBuffer::resolve() {
  
  if(val) { 
    val = replaceEval(val);
  }
  size = replaceEval(size);
  

  if (mode == SymTable::PO_BUF);
  else if(pc >= 0 && size->isResolved()) {
    int s = size->getValue();
    // obacht ?? delete size; 
    size = Value::constValue ( (pc/s)*s+s-pc ) ;
    mode = SymTable::PO_BUF;
  }
 
}

