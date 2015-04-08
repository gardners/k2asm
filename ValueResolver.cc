
#include "ValueResolver.h"
#include "NodeTypes.h"

bool ValueResolver::visit(Node* n) {
  return visitTopDown(n);
}

ValueResolver::ValueResolver() : minpc(0), maxpc(0), pc(0) {
  
}

void ValueResolver::updatePC(Node* n) {
  
  int off = n->codeLen();
  
  if(off < 0 || pc < 0) {
    pc = -1;
    minpc += n->minCodeLen();
    maxpc += n->maxCodeLen();
  } else {
    pc += off;
    minpc += off;
    maxpc += off;
  } 
  
}


bool ValueResolver::procNode(Node* n) {
  return false;
}


bool ValueResolver::procRootScope(RootScope* n) {
  
  Value* org = (Value*) n->getGlobalScope()->find(SymTable::PO_ORG);
  
  if(org == 0) {
    AERR(n) << "no org specified, assuming $1000\n";
    pc = minpc = maxpc = 0x1000;
  } else if(! org->resolve()) {
    AERR(org) << "cannot resolve ORG, assuming $1000\n";
    pc = minpc = maxpc = 0x1000;
  } else {
    pc = minpc = maxpc = org->getValue();
  }
  
  return false;

}

bool ValueResolver::procValueList(ValueList *n) {
  n->resolve();
  updatePC(n);
  return true;
}

bool ValueResolver::procByteBuffer(ByteBuffer *n) {
  n->setPC(pc,minpc,maxpc);
  n->resolve();
  updatePC(n);
  return true;
}

bool ValueResolver::procLabel(Label *n) {
  n->setPC(pc,minpc,maxpc);
  return false;
}
  
//bool ValueResolver::procNode(Node* n);
//bool ValueResolver::procScope(Scope* n);
//bool ValueResolver::procRootScope(RootScope* n);
//bool ValueResolver::procNamedScope(NamedScope* n);

bool ValueResolver::procOpcode(Opcode* n) {

  n->resolveOperand();
    
  if( (n->getMode() == Opcode::U_ABS) && (n->opLen() == 2) ) 
    n->setMode(Opcode::A_ABS);
  
  else if( (n->getMode() == Opcode::U_ABS) && (n->opLen() == 1) ) 
    n->setMode(Opcode::A_ZP);
  
  else if( (n->getMode() == Opcode::U_REL_X) && (n->opLen() == 2) ) 
    n->setMode(Opcode::A_ABS_X);
  
  else if( (n->getMode() == Opcode::U_REL_X) && (n->opLen() == 1) ) { 
    n->setMode(Opcode::A_ZP_X);    
    VERB << "detetcted zp adressing: " << n->strName() << " = " << n->getOperand() << "\n"; 
  }

  else if( (n->getMode() == Opcode::U_REL_Y) && (n->opLen() == 2) ) 
    n->setMode(Opcode::A_ABS_Y);
  
  else if( (n->getMode() == Opcode::U_REL_Y) && (n->opLen() == 1) ) { 
    n->setMode(Opcode::A_ZP_Y);    
    VERB << "detetcted zp adressing: " << n->strName() << " = " << n->getOperand() << "\n"; 
  }
  
  else if( (n->getMode() == Opcode::U_REL) && (pc >=0) && (n->getOperand() > 0) ) {
    n->setMode(Opcode::A_REL);
    int rj = n->getOperand() - pc - 2;
    if(rj < -128) { AERR(n) << "branch too far away\n"; }
    else if(rj > 127) { AERR(n) << "branch too far away\n"; }
    n->setOperand(rj);
  }
  
  //n->resolveOperand();

  updatePC(n);
  return true;
  
}

bool ValueResolver::procDefinition(Definition* n) {
  n->resolve();
  return true;
}

