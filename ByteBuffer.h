
#ifndef _BYTE_BUFFER_HEADER
#define _BYTE_BUFFER_HEADER

#include "Value.h"

class ByteBuffer : public Node {

 private:

  
  int mode;
  Value* size;
  Value* val;
  int pc, minpc, maxpc;

  friend class Scope;

 protected:

 public:

  ByteBuffer(int m, Value* s, Value* v = Value::constValue(0));

  void setPC(int pc, int minpc, int maxpc);
  int getFillValue();

  virtual int childCount() const;
  virtual Node* getChild(int idx) const;
  
  virtual int minCodeLen();
  virtual int maxCodeLen();
  virtual int codeLen();
  
  virtual bool receive(NodeVisitor* vis);
  
  virtual int localName();

  virtual bool isResolved();
  virtual void resolve();
  
};

#endif
