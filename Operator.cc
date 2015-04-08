#include "Operator.h"

const Operator* OpPlus::obj = new OpPlus();

Number OpPlus::operator() (Number l, Number r) const {
  return l + r;
}

const Operator* OpMinus::obj = new OpMinus();

Number OpMinus::operator() (Number l, Number r) const {
  return l - r;
}

const Operator* OpMult::obj = new OpMult();

Number OpMult::operator() (Number l, Number r) const {
  return l * r;
}

const Operator* OpDiv::obj = new OpDiv();

Number OpDiv::operator() (Number l, Number r) const {
  return l / r;
}

const Operator* OpMod::obj = new OpMod();

Number OpMod::operator() (Number l, Number r) const {
  return l % r;
}

const Operator* OpBitAnd::obj = new OpBitAnd();

Number OpBitAnd::operator() (Number l, Number r) const {
  return l & r;
}

const Operator* OpBitOr::obj = new OpBitOr();

Number OpBitOr::operator() (Number l, Number r) const {
  return l | r;
}

const Operator* OpBitXor::obj = new OpBitXor();

Number OpBitXor::operator() (Number l, Number r) const {
  return l ^ r;
}

const Operator* OpHighByte::obj = new OpHighByte();

Number OpHighByte::operator() (Number l, Number r) const {
  return (r >> 8) & Number(0xff);
}

const Operator* OpLowByte::obj = new OpLowByte();

Number OpLowByte::operator() (Number l, Number r) const {
  return r & Number(0xff);
}

const Operator* OpShr::obj = new OpShr();
Number OpShr::operator() (Number l, Number r) const {
 return l >> r;
}

const Operator* OpShl::obj = new OpShl();
Number OpShl::operator() (Number l, Number r) const {
 return l << r;
}
