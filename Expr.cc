
#include "Expr.h"
#include "Value.h"

Value* Expr::byteNull = Value::constValue(0);

Expr::Expr(Value* l, Value* r, const Operator *o) : 
  Value(), left(l), right(r), oper(o)  
{
  left->setParent(this);
  right->setParent(this);
}

Expr *Expr::expr(Value* l, Value* r, const Operator* o) {
  return new Expr(l,r,o);
}

Expr *Expr::unaryExpr(Value* v, const Operator* o) {
  return new Expr(byteNull, v, o);
}

/*
Value* Expr::tryResolve() {
  
  left = replaceResolved(left);
  right = replaceResolved(right);
  
  if(left->isResolved() && right->isResolved()) {
    
    int val = op(left->getValue(),right->getValue());
    return Value::constValue(val);
      
  } else return 0; 
  
}
*/

bool Expr::resolve() {
  return false;
}

Value* Expr::eval() {
  
  left = replaceEval(left);
  right = replaceEval(right);

  if(left->isResolved() && right->isResolved()) {
    
    Number val = (*oper)(left->getValue(),right->getValue());
    //delete this;
    return Value::constValue(val);
    
  } else return this; 
  
}

Number Expr::getValue() {
  return 0;
}

bool Expr::isResolved() {
  return false;
}

int Expr::valueLen() {
  return 2;
}

int Expr::childCount() const {
  if(left != byteNull) return 2;
  else return 1;
}

Node* Expr::getChild(int idx) const {
  if(idx == 0) return right;
  else return left;
}

bool Expr::receive(NodeVisitor* vis) {
  return vis->procExpr(this);
}

