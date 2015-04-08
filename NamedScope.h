
#ifndef _NAMED_SCOPE_HEADER
#define _NAMED_SCOPE_HEADER

#include "Scope.h"

class NamedScope : public Scope {

  int fqName;
  int lName;

  friend class Scope;

 protected:


 public:

  NamedScope(int fq, int name);

  virtual int getPrefixedName(int name);

  virtual Scope* beginScope();
  virtual Scope* endScope();

  virtual Definition* memberDefine(int name, Value* val);

  virtual int lookupName();
  virtual int localName();
  virtual int globalName();

  virtual bool receive(NodeVisitor* vis);

};

#endif
