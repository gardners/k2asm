
#ifndef _OPCODE_HEADER
#define _OPCODE_HEADER

#include "Node.h"
#include "Value.h"

struct OpcodeEntry {

  const char* mnomic;
  int amode[12];

};

class Opcode : public Node {

  friend class Scope;
  
 public:

  static const OpcodeEntry OP_LIST[];
  static const int AM_SIZES[];

  static const int U_UNDEF  = -5;
  static const int U_REL    = -4;
  static const int U_ABS    = -3;
  static const int U_REL_X  = -2;
  static const int U_REL_Y  = -1;
  static const int A_IMP    =  0;
  static const int A_IMM    =  1;
  static const int A_ZP     =  2;
  static const int A_ZP_X   =  3;
  static const int A_ZP_Y   =  4;
  static const int A_ABS    =  5;
  static const int A_ABS_X  =  6;
  static const int A_ABS_Y  =  7;
  static const int A_IND_X  =  8;
  static const int A_IND_Y  =  9;
  static const int A_IND    = 10;
  static const int A_REL    = 11;

  static bool tradeoff;
  
 protected:

  int mn;
  int amod;
  Value* val;

  int serOper(ostream& out, int size);

 public:

  Opcode(int opc, Value* oper);
  
  bool support(int m);

  void setMode(int m);
  
  virtual Node* getChild(int idx) const;
  virtual int childCount() const;
  virtual bool hasChilds();
  
  bool resolveOperand();
  int opLen();
  int getOperand();
  void setOperand(int o);
  
  virtual int codeLen();
  virtual int minCodeLen();
  virtual int maxCodeLen();
  virtual int getMode();

  virtual string strName();
  virtual int localName();

  virtual bool receive(NodeVisitor* vis);

};

#endif
