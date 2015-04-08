
#ifndef _VALUE_HEADER
#define _VALUE_HEADER

#include "Node.h"
#include "Number.h"

class Value : public Node {

 protected:  
  Value();
  
 public:

  virtual int childCount() const = 0;
  virtual Node* getChild(int idx) const = 0;
  
  virtual Number getValue() = 0;
  virtual int valueLen() = 0;

  virtual bool isResolved() = 0; 
  virtual Value* eval() = 0;
  virtual bool resolve() = 0;
    
  static Value* constValue(Number v);
  static Value* lookupValue(int name);
  
  static int Value::calcLen(int v);
  
};

#endif
