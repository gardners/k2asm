#ifndef _LOOKUP_HEADER
#define _LOOKUP_HEADER

#include "Value.h"

class Lookup : public Value {

  int rName;
  Value* val;

  friend class Value;

 public:

  Lookup(int ref);
  Lookup(Value* val);

  virtual bool isResolved();
  virtual Number getValue();
  
  virtual Value* eval();
  virtual bool resolve();
  virtual bool resolveName();

  virtual int childCount() const;
  virtual Node* getChild(int idx) const;

  virtual int valueLen();

  virtual int lookupName();
  virtual int localName();
  virtual bool receive(NodeVisitor* vis);
  virtual ~Lookup();

};

#endif
