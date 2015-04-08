
#ifndef _OPERATOR_HEADER
#define _OPERATOR_HEADER

#include "Number.h"

struct Operator {
  virtual Number operator() (Number l, Number r) const =0;
};

struct OpPlus: Operator {
  static const Operator *obj;
  virtual Number operator() (Number l, Number r) const;
};

struct OpMinus: Operator {
  static const Operator *obj;
  virtual Number operator() (Number l, Number r) const;
};

struct OpMult: Operator {
  static const Operator *obj;
  virtual Number operator() (Number l, Number r) const;
};

struct OpDiv: Operator {
  static const Operator *obj;
  virtual Number operator() (Number l, Number r) const;
};

struct OpMod: Operator {
  static const Operator *obj;
  virtual Number operator() (Number l, Number r) const;
};

struct OpBitAnd: Operator {
  static const Operator *obj;
  virtual Number operator() (Number l, Number r) const;
};

struct OpBitOr: Operator {
  static const Operator *obj;
  virtual Number operator() (Number l, Number r) const;
};

struct OpBitXor: Operator {
  static const Operator *obj;
  virtual Number operator() (Number l, Number r) const;
};

struct OpHighByte: Operator {
  static const Operator *obj;
  virtual Number operator() (Number l, Number r) const;
};

struct OpLowByte: Operator {
  static const Operator *obj;
  virtual Number operator() (Number l, Number r) const;
};

struct OpShr: Operator {
  static const Operator *obj;
  virtual Number operator() (Number l,Number r) const;
};

struct OpShl: Operator {
  static const Operator *obj;
  virtual Number operator() (Number l,Number r) const;
};

#endif
