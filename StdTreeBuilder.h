
#ifndef _STD_TREE_BUILDER_HEADER
#define _STD_TREE_BUILDER_HEADER

#include "CodeTreeBuilder.h"
#include "Value.h"
#include "FuncScope.h"
#include "NamedScope.h"

class StdTreeBuilder : public CodeTreeBuilder {

  vector<Value*> vlist;
  int encoding[256];
  
 protected:

  RootScope* root;
  Scope* global;
  Scope* curr;
  
 public:

  StdTreeBuilder();

  virtual void parse();
  virtual RootScope* getRootScope();

  virtual Scope* beginFuncScope(int name); 
  virtual Scope* beginNamedScope(int name);   
  virtual Scope* beginModuleScope(int name);   
  virtual Scope* beginModuleScope(Value* val);
   
  virtual Scope* beginScope();
  virtual Scope* endScope();

  virtual Definition* localDefine(int name, Value* v);
  virtual Definition* globalDefine(int name, Value* v);
  virtual Definition* exportDefine(int name, Value* v);
  virtual Definition* memberDefine(int name, Value* v);
  
  virtual Value* anonLabel();
  virtual Label* localLabel(int name);
  virtual Label* globalLabel(int name);
  virtual Label* exportLabel(int name);
  virtual Label* memberLabel(int name);

  virtual void op_implied(int opc);
  virtual void op_immediate(int opc, Value* oper);
  virtual void op_indir_x(int opc, Value* oper, char reg); 
  virtual void op_indir_y(int opc, Value* oper, char reg); 
  virtual void op_absrel(int opc, Value* oper, char reg); 
  virtual void op_indirect(int opc, Value* oper); 
  virtual void op_absolute(int opc, Value* oper); 

  virtual Definition* setEnv(int name, Value* v);
  virtual Value* getEnv(int name);

  virtual ByteBuffer* addByteBuffer(int mode, Value* size, 
			    Value* val = Value::constValue(0));
  
  virtual void addListValue(Value* v);
  virtual void addListValue(string* v);
  virtual void addCStr(string* str);
  virtual void endValueList(int t);
  
  virtual void setFilePos(string* name, int pos);
  bool parseEncLine(const char* line);
  virtual void setEncoding(string* file);
  virtual void error(const char* text);

  virtual ~StdTreeBuilder();
 
};

#endif
