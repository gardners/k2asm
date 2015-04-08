
#ifndef _ROOT_SCOPE_HEADER
#define _ROOT_SCOPE_HEADER

#include "Scope.h"
#include "Value.h"
#include "ValueList.h"

class RootScope : public Scope {
  
  vector<Value*> exports;
  int org;

  RootScope();

 protected:

 public:

  static RootScope* create();

  int getOrg();
  virtual void setOrg(int o);

  virtual Definition* localDefine(int name, Value* val);
  virtual Definition* globalDefine(int name, Value* val);
  bool receive(NodeVisitor* vis);

  virtual string strName() { return "_root_"; }
  virtual ~RootScope() {}

};

#endif
