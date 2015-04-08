
// leastcost: G88HoXEd
// inland: 9ZZ3BOS4

#include "Scope.h"
#include "NamedScope.h" 
#include "RootScope.h" 
#include "FuncScope.h" 
#include "Definition.h" 
#include "Opcode.h" 
#include "FileInfo.h" 

RootScope* Scope::root;
Scope* Scope::global;

Scope::Scope() : 
  Node(), firstNV(0), lastNV(0) { }


void Scope::appendNV(NamedValue* nv) {
  if (lastNV) {
    lastNV->setNext(nv);
    lastNV = nv;
  } else 
    firstNV = lastNV = nv;  
}

Node* Scope::getChild(int idx) const {
  return childs[idx];
}

bool Scope::hasChilds() {
  return childs.size() > 0;
}

bool Scope::receive(NodeVisitor* vis) {
  return vis->procScope(this);
}


int Scope::childCount() const {
  return childs.size();
}

int Scope::getPrefixedName(int name) {
  return name;
}

int Scope::getFQName(int name) {

  Node *p = this;
  while (p && (p->globalName() == SymTable::NO_NAME)) {
    p = p->getParent();
  }

  if(!p) return name;
  
  string pn = SymTable::revLookup(p->globalName());
  pn += ".";
  pn += SymTable::revLookup(name);
  
  return SymTable::lookup(pn);
  
}

int Scope::createPFName(int prefix, int name) {
  
  string pn = SymTable::revLookup(prefix);
  pn += ".";
  pn += SymTable::revLookup(name);
  
  return SymTable::lookup(pn);
  
}

void Scope::addChild(Node* n) {
  childs.push_back(n);
}

Scope* Scope::beginScope() {

  localLabel(SymTable::CONT);
  return this;
  
} 

Scope* Scope::endScope() {
  localLabel(SymTable::BREAK);
  return (Scope*) getParent();
}


Label* Scope::localLabel(int name) {

  Label *l = new Label(name);
  
  Node* s = (name!=SymTable::NO_NAME) ?  find(name,true) : 0;
  if(s != 0) {

    AERR(l) << "double defined symbol \"" << SymTable::revLookup(name) << "\"\n";
    AERR(s) << "first defined here \n";
    delete l;
    return 0;

  } else {

    appendNV(l);
    l->setParent(this);
    addChild(l);
    return l;

  }
}

Label* Scope::memberLabel(int name) {

  Label* l = localLabel(name);
  
  Scope* p = getParentScope();
  int pn = getPrefixedName(name);
  if(p!= 0) p->memberDefine(pn,l);

  return l;

}

Label* Scope::globalLabel(int name) {

  Label* l = localLabel(name);
  
  Scope* p = getParentScope();
  int pn = getPrefixedName(name);
  if(p!= 0) p->globalDefine(pn,l);

  return l;

}

Label* Scope::exportLabel(int name) {
  Label* l = localLabel(name);

  Scope* p = getParentScope();
  int pn = getPrefixedName(name);
  if(p!= 0) p->exportDefine(pn,l);

  return l;
}

Definition* Scope::localDefine(int name, Value* val) {

  Definition* def = new Definition(name,val);

  Node* s = find(name,true);  
  if(s != 0) {

    AERR(def) << "multiply defined symbol \"" << SymTable::revLookup(name) << "\"\n";
    AERR(s) << "first defined here \n";
    delete def;
    return 0;

  } else {  

    appendNV(def);
    def->setParent(this);
    addChild(def);
    return def;

  }

}

Definition* Scope::memberDefine(int name, Value* val) {
  
  Definition* def = localDefine(name,val);

  Scope* p = getParentScope();
  int pn = getPrefixedName(name);
  if(p!= 0) p->memberDefine(pn,def);
  
  return def;
  
}


Definition* Scope::globalDefine(int name, Value* val) {

  Definition* def = localDefine(name,val);

  Scope* p = getParentScope();
  int pn = getPrefixedName(name);
  if(p!= 0) p->globalDefine(pn,def);

  return def;

}

Definition* Scope::exportDefine(int name, Value* val) {

  Definition* def = localDefine(name,val);

  Scope* p = getParentScope();
  int pn = getPrefixedName(name);
  if(p!= 0) p->exportDefine(pn,def);
  
  return def;
}

Node* Scope::find(int name, bool local) {
  
  for(NamedValue* it=firstNV; it != 0; it = it->getNext()) {
    if(it->lookupName() == name) { return it; }
  }
   
  return Node::find(name, local);
}

Scope::~Scope() {
  
}

