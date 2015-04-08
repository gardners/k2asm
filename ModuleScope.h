
#ifndef _MODULE_SCOPE_HEADER
#define _MODULE_SCOPE_HEADER

#include "NamedScope.h"

class ModuleScope : public NamedScope {

  friend class Scope;

 public:

  ModuleScope(int name);
  virtual Scope* beginScope();

};

#endif
