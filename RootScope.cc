
#include "RootScope.h"
#include "Definition.h"

RootScope::RootScope() : Scope() {
  parent = 0;
}

RootScope* RootScope::create() {
  if(!root) { 
    root = new RootScope();
    global = new Scope();
    root->addChild(global);
    global->setParent(root);
  }
  return root;
}

bool RootScope::receive(NodeVisitor* vis) {
  return vis->procRootScope(this);
}

int RootScope::getOrg() { return org; }

void RootScope::setOrg(int o) { org = o; }

Definition* RootScope::localDefine(int name, Value* val) {
  Definition* nv = Scope::localDefine(name,val);
  exports.push_back(nv);
  return nv;
}

Definition* RootScope::globalDefine(int, Value*) {
  return 0;
}

