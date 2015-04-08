
#ifndef _SCOPE_HEADER
#define _SCOPE_HEADER

#include <iostream>

#include "CodeTreeBuilder.h"

#include "Node.h"
#include "Label.h"
#include "ValueList.h"
#include "Definition.h"
#include "ByteBuffer.h"

#include "NodeVisitor.h"

class Scope : public Node  {

  //friend class RootScope;
  NamedValue* firstNV;
  NamedValue* lastNV;
  void appendNV(NamedValue* nv);

 protected:
  
  vector<Node*> childs;
  static Scope* global;
  static RootScope* root;
  
 public:

  Scope();

  int getFQName(int name);
  int createPFName(int prefix, int name);

  virtual bool receive(NodeVisitor* vis);
  
  virtual Node* getChild(int idx) const;
  virtual int childCount() const;
  virtual bool hasChilds();
  
  virtual Node* find(int name, bool local = false);

  //virtual void resolve();
  
  virtual ~Scope();
 
  // ************* Construction Methods ************************ //
  
  virtual void addChild(Node* n);
  
  virtual RootScope* getRootScope() { return root; }
  virtual Scope* getGlobalScope() { return global; }
  virtual Scope* getParentScope() { return dynamic_cast<Scope*>(getParent()); }
  
  virtual Scope* beginScope();
  virtual Scope* endScope();

  virtual int getPrefixedName(int name);

  virtual Definition* localDefine(int name, Value* v);
  virtual Definition* memberDefine(int name, Value* v);
  virtual Definition* globalDefine(int name, Value* v);
  virtual Definition* exportDefine(int name, Value* v);
  
  virtual Label* localLabel(int name);
  virtual Label* memberLabel(int name);
  virtual Label* globalLabel(int name);
  virtual Label* exportLabel(int name);
 
};

#endif
