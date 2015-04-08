
#include <iomanip>
#include "NodeTypes.h"
#include "PrettyPrinter.h"

using namespace std;

PrettyPrinter::PrettyPrinter(ostream& output) 
  : out(output), doindent(true), indent(18), pc(0) {
}
  
bool PrettyPrinter::visit(Node* n) { return visitNode(n); }
  
void PrettyPrinter::spaces(int count) {
  if(doindent) for(int k=0;k<count;k++) out << " ";
}

bool PrettyPrinter::procNode(Node* n) {
  
  out << " (" << n->strName() << ":";
  bool res = visitChilds(n);
  out << ":" << n->strName() << ")\n"; 

  return res;

}

bool PrettyPrinter::procRootScope(RootScope* n) {
  spaces(indent);

  Value* org = (Value*) n->getGlobalScope()->find(SymTable::PO_ORG);
  if (!org) return visitChilds(n);

  pc = org->getValue();
  out << "\n.org " << pc << "\n";

  return visitChilds(n);
}

bool PrettyPrinter::procScope(Scope* n) {
 
  spaces(indent);
  doindent = true;
  out << "{\n";
  indent+=2;
  visitChilds(n);
  indent-=2;
  spaces(indent);
  out << "}\n";
    
  return false;

}

bool PrettyPrinter::procNamedScope(NamedScope* n) {
  
  spaces(indent);
  out << ".scope " << n->strName() << "  ";
  doindent = false;
  
  return procScope(n);
  return false;

}

bool PrettyPrinter::procOpcode(Opcode* n) {

  out << hex << setw(8) << setfill('0') << pc << " : ";  
    
  if(n->getMode() < 0) {
    
    out << "?? ?? ?? ";
  
  } else {
  
    out << setw(2) << setfill('0')
	<< Opcode::OP_LIST[n->localName()].amode[n->getMode()]  << " "; 
  
    if(Opcode::AM_SIZES[n->getMode()] > 0)
      out << setw(2) << setfill('0') << (n->getOperand() & 0xff) << " ";
    else out << "   ";
    
    if(Opcode::AM_SIZES[n->getMode()] > 1)
      out << setw(2) << setfill('0') << ((n->getOperand() >> 8) & 0xff) << " ";
    else out << "   ";
    
  }
  
  spaces(indent - 20);
  out << n->strName();
  
  switch(n->getMode()) {
  case Opcode::A_IMP    :  break;
  case Opcode::A_IMM    :  out << "#"; visitChilds(n); break;
  case Opcode::A_ZP     :  out << " z "; visitChilds(n); break;
  case Opcode::A_ZP_X   :  out << " z "; visitChilds(n); out << ",x"; break;
  case Opcode::A_ZP_Y   :  out << " z "; visitChilds(n); out << ",y"; break;
  case Opcode::A_ABS    :  out << " "; visitChilds(n); break;
  case Opcode::A_ABS_X  :  out << " "; visitChilds(n); out << ",x"; break;
  case Opcode::A_ABS_Y  :  out << " "; visitChilds(n); out << ",y"; break;
  case Opcode::A_IND_X  :  out << "("; visitChilds(n); out << ",x)"; break;
  case Opcode::A_IND_Y  :  out << "("; visitChilds(n); out << "),y"; break;
  case Opcode::A_IND    :  out << "("; visitChilds(n); out << ")"; break;
  case Opcode::A_REL    :  out << " +"; visitChilds(n); break;
  default: out << "<umod>";
  }
   
  out << "\n";
  pc += n->codeLen();
  
  return false;
  
}

bool PrettyPrinter::procLabel(Label* n) {

  if(n->localName() == SymTable::NO_NAME) return false;
    
  out << setw(8) << setfill('0') << pc << " : ";  
  spaces(indent - 8 - 3);
  out << n->strName() << ":\n";
    
  return false;
    
}

bool PrettyPrinter::procLookup(Lookup* n) {
  out << n->strName() << "[ = " << n->getValue() << "]\n";
  return true;
}

bool PrettyPrinter::procDefinition(Definition* n) {

  spaces(indent);
  out << n->strName() << " = $" << hex << n->getValue() << "\n";

  return false;
  
}

bool PrettyPrinter::procValue(Value* n) {
	
	if(n->valueLen() == 1) 
  	out << "$" << setw(2) << setfill('0') <<  n->getValue();
  else 
  	out << "$" << setw(4) << setfill('0') <<  n->getValue();
  	
  return false;
}

bool PrettyPrinter::procByteValue(ByteValue* n) { 
  out << "$" << setw(2) << setfill('0') <<  n->getValue(); 
  return false;
}

bool PrettyPrinter::procWordValue(WordValue* n) { 
  out << "$" << setw(4) << setfill('0') <<  n->getValue();
  return false;
}

bool PrettyPrinter::procValueList(ValueList* n) { 
  
  spaces(indent);
  out << n->strName() << " ";
  
  int k;
  for(k = 0;k<n->childCount()-1;k++) {
    if( ! ((k+1)%10) ) {
      out << "\n";
      spaces(indent + n->strName().length()+1);
    }
    n->getChild(k)->receive(this);
    out << ",";
  }
  n->getChild(k)->receive(this);
  out << "\n";
  
  Node *nn;
  nn = n->getChild(k);
  nn->receive(this);

  pc += n->codeLen();

  return false;
}

bool PrettyPrinter::procByteBuffer(ByteBuffer* n) { 
  
  spaces(indent);
  out << n->strName() << " ";
  n->getChild(0)->receive(this);

  if(n->childCount() == 2) {
    out << " ";
    n->getChild(1)->receive(this);
    out << "\n";
  }

  pc += n->codeLen();

  return false;
}

