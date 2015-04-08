
#include "ModuleScope.h"
#include "RootScope.h"

ModuleScope::ModuleScope(int name) : NamedScope(name,name) {
}

Scope* ModuleScope::beginScope() {
  return Scope::beginScope();  
} 
