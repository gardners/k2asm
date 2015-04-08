
#include "NodeTypes.h"
#include "SymResolver.h"

SymResolver::SymResolver() {

}

bool SymResolver::procNode(Node* n) {
  return false;
}

bool SymResolver::visit(Node* n) {
  return visitTopDown(n);
}

bool SymResolver::procOpcode(Opcode *n) {

  if(n->getMode() == Opcode::U_ABS && n->support(Opcode::U_REL)) 
    n->setMode(Opcode::U_REL);

  else if(n->getMode() == Opcode::U_ABS && !n->support(Opcode::A_ZP)) 
    n->setMode(Opcode::A_ABS);

  else if(n->getMode() == Opcode::U_REL_X && !n->support(Opcode::A_ZP_X)) 
    n->setMode(Opcode::A_ABS_X);

  else if(n->getMode() == Opcode::U_REL_Y && !n->support(Opcode::A_ZP_Y)) 
    n->setMode(Opcode::A_ABS_Y);
  
  return false;
}


bool SymResolver::procLookup(Lookup* n) {
  if (! n->resolveName()) {
    AERR(n) << "unresolved symbol " << n->strName() << "\n";
  }
  return true;
}

