
#ifndef _NAMED_VALUE_HEADER
#define _NAMED_VALUE_HEADER

#include "Value.h"

class NamedValue : public Value {
  NamedValue *next;

 protected:

  int vName;

  NamedValue(int name);

 public:
  
  void setNext(NamedValue *next);
  NamedValue *getNext();

};

#endif
