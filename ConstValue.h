
#ifndef _CONST_VALUE_HEADER
#define _CONST_VALUE_HEADER

#include <iomanip>
#include "Value.h"
#include "Number.h"

class ByteValue : public Value {

  Number val;

  friend class Value;

 public:
  ByteValue(Number v) : Value(), val(v) {}

  virtual int childCount() const { return 0; }

  virtual Node* getChild(int idx) const { return 0; }

  virtual Number getValue() { return val; }

  virtual bool receive(NodeVisitor* vis) { return vis->procByteValue(this); }

  virtual int valueLen() { return 1; }
  
  virtual Value* eval() { return this; }
  virtual bool resolve() { return true; }
  virtual bool isResolved() { return true; }

  virtual ~ByteValue() {}


};

class WordValue : public Value {

  Number val;

  friend class Value;

 public:

  WordValue(Number v) : Value(), val(v) {}

  virtual int childCount() const { return 0; }

  virtual Node* getChild(int idx) const { return 0; }

  virtual int valueLen() { return 2; }

  virtual Number getValue() { return val; }

  virtual bool receive(NodeVisitor* vis) { return vis->procWordValue(this); }

  virtual bool resolve() { return true; }
  virtual Value* eval() { return this; }
  virtual bool isResolved() { return true; }

  virtual ~WordValue() {}

};


class StringValue : public Value {
  
  string val;

  friend class Value;
  
 public:

  virtual int childCount() const { return 0; }

  virtual Node* getChild(int idx) const { return 0; }

  virtual Number getValue() { return 0; }

  virtual Value* tryResolve() { return 0; }

  virtual bool isResolved() { return true; }

  virtual ~StringValue() {}

};

#endif
