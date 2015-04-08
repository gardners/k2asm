
#include "Value.h"
#include "ConstValue.h"
#include "Lookup.h"

Value::Value() : Node() {
}

Value* Value::eval() {
  return this;
}

Value* Value::constValue(Number v) {
  if((v < 256) && (v >= -128))
    return new ByteValue(v);
  else 
    return new WordValue(v);
  
}

Value* Value::lookupValue(int name) {
  return new Lookup(name);
}

int Value::calcLen(int v) {
  return (v < 256 && v >= -128) ? 1 : 2;
}

