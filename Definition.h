
#ifndef _DEFINITION_HEADER
#define _DEFINITION_HEADER

#include "NamedValue.h"

class Definition : public NamedValue {

  Value* val;

  friend class Scope;
  friend class RootScope;
  Definition(int name, Value* val);

 public:

  virtual void setParent(Node* par, int ipos = -1);

  virtual bool resolve();
  virtual bool isResolved();
  virtual Value* eval();

  virtual int childCount() const;
  virtual Node* getChild(int idx) const;

  virtual Number getValue();
  virtual int valueLen();

  virtual int localName();
  virtual int lookupName();
  virtual int globalName();

  virtual bool receive(NodeVisitor* vis);

  virtual ~Definition();

};

#endif
