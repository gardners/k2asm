
#ifndef _FUNC_SCOPE_HEADER
#define _FUNC_SCOPE_HEADER

#include "NamedScope.h"
#include "Opcode.h"

class FuncScope : public NamedScope {

  friend class Scope;

 protected:

 public:

  FuncScope(int fq, int name);
  virtual Scope* endScope();

};

#endif
