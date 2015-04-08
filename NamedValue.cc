#include "NamedValue.h"

NamedValue::NamedValue(int name) : Value(), next(0), vName(name) {
}

void NamedValue::setNext(NamedValue *next) {
  this->next = next;
}
NamedValue *NamedValue::getNext() {
  return next;
}
