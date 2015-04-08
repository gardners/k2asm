
#ifndef _VALUE_LIST_HEADER
#define _VALUE_LIST_HEADER

#include "Node.h"
#include "Value.h"

class ValueList : public Node {
  
  int type;
  size_t size;
  Value** vals;

  friend class Scope;
  
 public:
  
  ValueList(int ty, size_t s, Value** v);

  virtual Node* getChild(int idx) const;
  virtual bool hasChilds();
  virtual int childCount() const;
  
  void resolve();

  int valueLen();

  virtual int localName();
  
  virtual int minCodeLen();
  virtual int maxCodeLen();
  virtual int codeLen();
  
  virtual bool receive(NodeVisitor* vis);
  
};

#endif
