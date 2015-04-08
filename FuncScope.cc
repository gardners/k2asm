
#include "FuncScope.h"

FuncScope::FuncScope(int fq, int name) : NamedScope(fq,name) {
}

Scope* FuncScope::endScope() {

  return NamedScope::endScope();

}
