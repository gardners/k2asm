
#include "NamedScope.h"
#include "RootScope.h"

NamedScope::NamedScope(int fq, int name) : Scope(), fqName(fq), lName(name) {
}

Scope* NamedScope::beginScope() {

  Scope *p = getParentScope();  
  cerr << "export: " << SymTable::revLookup(lName) << "\n";
  p->exportLabel(lName);
  
  return Scope::beginScope();
  
} 


Scope* NamedScope::endScope() {
 
  Scope* res = Scope::endScope();

  int lab = createPFName(lName,SymTable::END); 
  Label* l = res->localLabel(lab);

  getRootScope()->localDefine(getFQName(SymTable::END),l);
  
  return res;

}

bool NamedScope::receive(NodeVisitor* vis) {
  return vis->procNamedScope(this);
}

int NamedScope::getPrefixedName(int name) {

  string pn = SymTable::revLookup(localName());
  pn += ".";
  pn += SymTable::revLookup(name);
  
  return SymTable::lookup(pn);

}

Definition* NamedScope::memberDefine(int name, Value* val) {

  Definition* nv = localDefine(name,val);
  return nv;
  
}

int NamedScope::lookupName() {
  return SymTable::NO_NAME;
}

int NamedScope::localName() {
  return lName;
}

int NamedScope::globalName() {
  return fqName;
}
