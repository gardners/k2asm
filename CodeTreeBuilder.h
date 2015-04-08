

#ifndef _CODE_TREE_BUILDER_HEADER
#define _CODE_TREE_BUILDER_HEADER

#include "SymTable.h"

class Node;
class Scope;
class Value;
class Label;
class Definition;
class ByteBuffer;
class RootScope;

class CodeTreeBuilder  {
  
 public:
  
  virtual Scope* beginFuncScope(int name) = 0; 
  virtual Scope* beginNamedScope(int name) = 0;   
  virtual Scope* beginModuleScope(int name) = 0;
  virtual Scope* beginModuleScope(Value* val) = 0;

  virtual Scope* beginScope() = 0;
  virtual Scope* endScope() = 0;

  virtual Definition* localDefine(int name, Value* v) = 0;
  virtual Definition* globalDefine(int name, Value* v) = 0;
  virtual Definition* exportDefine(int name, Value* v) = 0;
  virtual Definition* memberDefine(int name, Value* v) = 0;
  
  virtual Value* anonLabel() = 0;
  virtual Label* localLabel(int name) = 0;
  virtual Label* globalLabel(int name) = 0;
  virtual Label* exportLabel(int name) = 0;
  virtual Label* memberLabel(int name) = 0;

  virtual void op_implied(int opc) = 0;
  virtual void op_immediate(int opc, Value* oper) = 0;
  virtual void op_indir_x(int opc, Value* oper, char reg) = 0; 
  virtual void op_indir_y(int opc, Value* oper, char reg) = 0; 
  virtual void op_absrel(int opc, Value* oper, char reg) = 0; 
  virtual void op_indirect(int opc, Value* oper) = 0; 
  virtual void op_absolute(int opc, Value* oper) = 0; 

  virtual Definition* setEnv(int name, Value* v) = 0;
  virtual Value* getEnv(int name) = 0;

  virtual ByteBuffer* addByteBuffer(int mode, Value* size, 
				    Value* val = 0) = 0;
  
  virtual void addListValue(Value* v) = 0;
  virtual void addListValue(string* v) = 0;
  virtual void addCStr(string* str) = 0;
  virtual void endValueList(int t) = 0;
  
  virtual void setFilePos(string* name, int pos) = 0;
  virtual void setEncoding(string* enc) = 0;

  virtual void error(const char* text) = 0;
  
};

#endif
