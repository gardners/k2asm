
#include "NodeTypes.h"
#include "CodeGen.h"

CodeGen::CodeGen(ostream& o) : 
  out(o), oexp(o), odnc(NULL),
  doexp(false), doobj(false), dodnc(false) {
}

CodeGen::CodeGen(ostream& o, ostream& e) : 
  out(o), oexp(e), odnc(NULL),
  doexp(true), doobj(false), dodnc(false) {
}

void CodeGen::setDncStream(ostream& d) {
  odnc = &d;
  dodnc = true;
}

CodeGen* CodeGen::setObj(bool obj) {
  doobj = obj;
  return this;
}

// ZY: now only writes DNC values max FF
void CodeGen::writeDNCData(const Number &nr, const Node *node) {
  int dncmask,h,l;
  if (!dodnc) return;
  dncmask=nr.getDNCMask();
  if (!dncmask) return;
  
  if(dncmask<0x100)
  {
    (*odnc) << "$" << hex << pc 
	  << " : $" << hex << dncmask 
	  << "\n";
  }
  else
  {
    l=dncmask&0xFF;
    h=dncmask>>8;
    (*odnc) << "$" << hex << pc << " : $" << hex << l << "\n";
    (*odnc) << "$" << hex << pc+1 << " : $" << hex << h << "\n";
  }
}


bool CodeGen::visit(Node* n) {
  return visitTopDown(n);
}

bool CodeGen::procNode(Node* n) { return false; }
bool CodeGen::procLabel(Label* n) { return true; }
bool CodeGen::procLookup(Lookup* n) { return true; }

bool CodeGen::procDefinition(Definition* n) { 
  if(root == n->getParent() && doexp) {
    oexp << n->strName() << " = $" << hex << n->getValue() << ";\n"; 
  }
  return true; 
}

bool CodeGen::procRootScope(RootScope* n) {

  root = n;

  Value* org = (Value*) n->getGlobalScope()->find(SymTable::PO_ORG);
  pc = org->getValue();

  if (!doobj) {
    out.put(pc & 0xff);
    out.put( ( pc >> 8 )  & 0xff);
  }
  
  return false;
}

bool CodeGen::procOpcode(Opcode* n) {

  if(n->getMode() < 0) {
    AERR(n) << "unresolved addressing mode\n";
  } else {
    out.put(Opcode::OP_LIST[n->localName()].amode[n->getMode()]);
    pc += 1;
    sizeContext = Opcode::AM_SIZES[n->getMode()];
  }

  return false;

}

bool CodeGen::procByteValue(ByteValue* n) {

  if(sizeContext == 1) {
    Number nr = n->getValue();

    out.put(nr & Number(0xff,0) );
    writeDNCData(nr, n);
    pc += 1;
        
  }

  if(sizeContext > 1) {
    // TODO: besser gar nicht erst zwischen ByteValue und WordValue unterscheiden
    WordValue nv(n->getValue());
    procWordValue(&nv);
  }

  return false;

}

bool CodeGen::procWordValue(WordValue* n) {

  if(sizeContext == 2 ) {
    Number nr = n->getValue();

    if (nr < -32768 || nr > 65535) {
      AERR(n) << "value out of bounds:" << n->valueLen() << "\n";
    }

    if (nr<0) nr = 65536+nr;
    out.put( nr & Number(0xff,0) );
    out.put( (nr >> 8) & Number(0xff,0) );
    writeDNCData(nr, n);

    pc += 2;
  } else {
    AERR(n) << "wrong operand size:" << n->valueLen() << " " << n->getValue() << "\n" ;
  }

  return false;

}

bool CodeGen::procValueList(ValueList* n) { 
  sizeContext = n->valueLen();
  return false;
}

bool CodeGen::procByteBuffer(ByteBuffer* n) { 
  for(int k=0;k<n->codeLen();k++)
    out.put( n->getFillValue() );

  pc += n->codeLen();
  return true;
}

