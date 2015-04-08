#include "ConstValue.h"
#include <iomanip>
#include "Opcode.h"


const int Opcode::AM_SIZES[] = { 0,1,1,1,1,2,2,2,1,1,2,1 };

const OpcodeEntry Opcode::OP_LIST[] = { 

  //         imp  #imm  zp    zp,x  zp,y  abs   abs,x abs,y (i,x) (i),y (ind)  rel

{ "adc",  {   -1, 0x69, 0x65, 0x75,  -1,  0x6d, 0x7d, 0x79, 0x61, 0x71,   -1,   -1 } },
{ "and",  {   -1, 0x29, 0x25, 0x35,  -1,  0x2d, 0x3d, 0x39, 0x21, 0x31,   -1,   -1 } },
{ "asl",  { 0x0a,   -1, 0x06, 0x16,  -1,  0x0e, 0x1e,   -1,   -1,   -1,   -1,   -1 } },

{ "bcc",  {   -1,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1, 0x90 } },
{ "bcs",  {   -1,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1, 0xb0 } },
{ "beq",  {   -1,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1, 0xf0 } },
{ "bit",  {   -1,   -1, 0x24,   -1,  -1,  0x2c,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "bmi",  {   -1,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1, 0x30 } },
{ "bne",  {   -1,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1, 0xd0 } },
{ "bpl",  {   -1,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1, 0x10 } },
{ "brk",  { 0x00,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "bvc",  {   -1,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1, 0x50 } },
{ "bvs",  {   -1,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1, 0x70 } },

{ "clc",  { 0x18,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "cld",  { 0xd8,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "cli",  { 0x58,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "clv",  { 0xb8,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "cmp",  {   -1, 0xc9, 0xc5, 0xd5,  -1,  0xcd, 0xdd, 0xd9, 0xc1, 0xd1,   -1,   -1 } },
{ "cpx",  {   -1, 0xe0, 0xe4,   -1,  -1,  0xec,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "cpy",  {   -1, 0xc0, 0xc4,   -1,  -1,  0xcc,   -1,   -1,   -1,   -1,   -1,   -1 } },

  //         imp  #imm  zp    zp,x  zp,y  abs   abs,x abs,y (i,x) (i),y (ind)  rel

{ "dec",  {   -1,   -1, 0xc6, 0xd6,  -1,  0xce, 0xde,   -1,   -1,   -1,   -1,   -1 } },
{ "dex",  { 0xca,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "dey",  { 0x88,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },

{ "eor",  {   -1, 0x49, 0x45, 0x55,  -1,  0x40, 0x5d, 0x59, 0x41, 0x51,   -1,   -1 } },

{ "inc",  {   -1,   -1, 0xe6, 0xf6,  -1,  0xee, 0xfe,   -1,   -1,   -1,   -1,   -1 } },
{ "inx",  { 0xe8,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "iny",  { 0xc8,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },

{ "jmp",  {   -1,   -1,   -1,   -1,  -1,  0x4c,   -1,   -1,   -1,   -1, 0x6c,   -1 } },
{ "jsr",  {   -1,   -1,   -1,   -1,  -1,  0x20,   -1,   -1,   -1,   -1,   -1,   -1 } },

{ "lda",  {   -1, 0xa9, 0xa5, 0xb5,  -1,  0xad, 0xbd, 0xb9, 0xa1, 0xb1,   -1,   -1 } },
{ "ldx",  {   -1, 0xa2, 0xa6,   -1,0xb6,  0xae,   -1, 0xbe,   -1,   -1,   -1,   -1 } },
{ "ldy",  {   -1, 0xa0, 0xa4, 0xb4,  -1,  0xac, 0xbc,   -1,   -1,   -1,   -1,   -1 } },
{ "lsr",  { 0x4a,   -1, 0x46, 0x54,  -1,  0x4e, 0x5e,   -1,   -1,   -1,   -1,   -1 } },

{ "nop",  { 0xea,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },

{ "ora",  {   -1, 0x09, 0x05, 0x15,  -1,  0x0d, 0x1d, 0x19, 0x01, 0x11,   -1,   -1 } },

{ "pha",  { 0x48,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "php",  { 0x08,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "pla",  { 0x68,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "plp",  { 0x28,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },

  //         imp  #imm  zp    zp,x  zp,y   abs   abs,x abs,y (i,x) (i),y (ind)  rel

{ "rol",  { 0x2a,   -1, 0x26, 0x36,  -1,  0x2e, 0x3e, 0x3e,   -1,   -1,   -1,   -1 } },
{ "ror",  { 0x6a,   -1, 0x66, 0x76,  -1,  0x6e, 0x7e,   -1,   -1,   -1,   -1,   -1 } },
{ "rti",  { 0x40,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "rts",  { 0x60,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },

{ "sbc",  {   -1, 0xe9, 0xe5, 0xf5,  -1,  0xed, 0xfd, 0xf9, 0xe1, 0xf1,   -1,   -1 } },
{ "sec",  { 0x38,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "sed",  { 0xf8,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "sei",  { 0x78,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "sta",  {   -1,   -1, 0x85, 0x95,  -1,  0x8d, 0x9d, 0x99, 0x81, 0x91,   -1,   -1 } },
{ "stx",  {   -1,   -1, 0x86,   -1,0x96,  0x8e,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "sty",  {   -1,   -1, 0x84, 0x94,  -1,  0x8c,   -1,   -1,   -1,   -1,   -1,   -1 } },

{ "tax",  { 0xaa,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "tay",  { 0xa8,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "tsx",  { 0xba,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "txa",  { 0x8a,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "txs",  { 0x9a,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{ "tya",  { 0x98,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },

{ "xxx",  {   -1,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } },
{     0,  {   -1,   -1,   -1,   -1,  -1,    -1,   -1,   -1,   -1,   -1,   -1,   -1 } }
};


bool Opcode::tradeoff = false;

Opcode::Opcode(int opc, Value* value): mn(opc), amod(U_UNDEF), val(value)  {
  if(val) val->setParent(this);
}

bool Opcode::support(int m) {
  return (m >= 0) && (OP_LIST[mn].amode[m] >= 0);
}

void Opcode::setMode(int m) {

  if(m == U_ABS && support(A_REL)) amod = U_REL;
  else if(m >= 0 && !support(m)) {
    AERR(this) << "unsupported adressing mode\n";
  } else amod = m;
  
}

string Opcode::strName() {
  return SymTable::revLookup(mn);
}

bool Opcode::hasChilds() {
  return val != 0;
}

int Opcode::childCount() const {
  return (val == 0) ? 0 : 1;
}

Node* Opcode::getChild(int idx) const {
  return val;
}

int Opcode::localName() {
  return mn;
}

bool Opcode::resolveOperand() {
  if(val) {
    val->resolve();
    val = replaceEval(val);
    return val->isResolved();
  } else return true;
}

int Opcode::minCodeLen() {
  if(amod < 0) return 2; 
  else return codeLen();
}

int Opcode::maxCodeLen() {
  if(amod == U_REL) return 2;
  else if(amod < 0) return 3;
  else return codeLen();
}

int Opcode::codeLen() {
  if(amod == U_REL) return 2;
  else if(amod < 0) return -1;
  else return AM_SIZES[amod] + 1;
}

int Opcode::getOperand() {
  if(val) return val->getValue();
  else {
    INT_ERR << "opcode has no operand\n";
    return 0;
  }
}

int Opcode::opLen() {
  if(val) return val->valueLen();
  return 0;
}

int Opcode::getMode() {
  return amod;
}

bool Opcode::receive(NodeVisitor* vis) {
  return vis->procOpcode(this);
}

void Opcode::setOperand(int o) {
  //delete val;
  val = Value::constValue(o);
}
