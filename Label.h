
#ifndef _LABEL_HEADER
#define _LABEL_HEADER

#include "NamedValue.h"

class Label : public NamedValue {

  int pc;
  int minpc;
  int maxpc;

  friend class Scope;

  Label (int name);

 public:

  virtual void setParent(Node* par, int ipos = -1);
  
  void setPC(int pc, int minpc = -1, int maxpc = -1);

  virtual int childCount() const;
  virtual Node* getChild(int idx) const;
  
  virtual Number getValue();
  virtual int valueLen();

  virtual int lookupName();
  virtual int localName();
  virtual string strName();

  virtual bool isResolved();
  virtual Value* eval();
  virtual bool resolve();
  
  virtual bool pcAwareResolving();
  virtual bool isLabel();

  virtual bool receive(NodeVisitor* vis);

  virtual ~Label();
  
};

#endif
