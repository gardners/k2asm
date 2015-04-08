
#ifndef _EXPR_HEADER
#define _EXPR_HEADER

#include "Value.h"
#include "Operator.h"

class Expr : public Value {
  
  Value* left;
  Value* right;
  const Operator* oper;

  static Value* byteNull;

  Expr(Value* l, Value* r, const Operator* o);

public:

  static Expr *expr(Value* l, Value* r, const Operator* o);
  static Expr *unaryExpr(Value* v, const Operator* o);
  //  virtual Value* tryResolve();
  
  virtual Value* eval();
  
  virtual bool isResolved(); 
  virtual bool resolve();

  virtual Number getValue();
  virtual int valueLen();
  virtual int childCount() const ;
  virtual Node* getChild(int idx) const;
  virtual bool receive(NodeVisitor* vis);

};

#endif
