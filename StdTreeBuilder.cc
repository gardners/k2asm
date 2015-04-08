
// leastcost: G88HoXEd
// inland: 9ZZ3BOS4

#include <fstream>

#include "StdTreeBuilder.h" 
#include "FileInfo.h"
#include "Opcode.h"
#include "RootScope.h"
#include "Lookup.h"
#include "FuncScope.h"
#include "NamedScope.h"
#include "ModuleScope.h"

StdTreeBuilder::StdTreeBuilder() { }

StdTreeBuilder::~StdTreeBuilder() { }

Scope* StdTreeBuilder::beginScope() {
  
  Scope* s = new Scope();
  
  s->setParent(curr);
  s->beginScope();
  curr->addChild(s); 
  
  return curr = s;

} 

Scope* StdTreeBuilder::beginNamedScope(int name) {
  
  Scope* s = new NamedScope(curr->getFQName(name),name);
  
  s->setParent(curr);
  s->beginScope();
  curr->addChild(s);
  
  return curr = s; 
  
} 

Scope* StdTreeBuilder::beginModuleScope(int name) {

  setEnv(SymTable::PO_ORG,new Lookup(name));
  
  Scope* s = new ModuleScope(name);
  
  s->setParent(curr);
  s->beginScope();
  curr->addChild(s);
  
  return curr = s; 
  
} 

Scope* StdTreeBuilder::beginModuleScope(Value* val) {

  setEnv(SymTable::PO_ORG,val);
  return beginScope();

} 


Scope* StdTreeBuilder::beginFuncScope(int name) {

  Scope* s = new FuncScope(curr->getFQName(name),name);
  
  s->setParent(curr);
  s->beginScope();
  curr->addChild(s); 
  
  return curr = s;

} 


Scope* StdTreeBuilder::endScope() {
  return (curr = curr->endScope());
}


ByteBuffer* StdTreeBuilder::addByteBuffer(int mode, Value* size, Value* value) {

  ByteBuffer* b = new ByteBuffer(mode,size,value);
  b->setParent(curr);
  curr->addChild(b);
  return b;

}

void StdTreeBuilder::setFilePos(string* name, int pos) {
  
  SymTable::line = pos;

  if(SymTable::currFile() != (*name) || SymTable::line != pos) {
    FileInfo* fi = new FileInfo(*name);
    curr->addChild(fi);
    SymTable::currFile(*name);
  }
  
  delete name;

}

Definition* StdTreeBuilder::setEnv(int name, Value* v) {
  cerr << "found " << SymTable::revLookup(name) << "\n";
  return global->localDefine(name,v);
}

Value* StdTreeBuilder::getEnv(int name) {
  return dynamic_cast<Value*>(global->find(name));
}

void StdTreeBuilder::addListValue(Value* v) {
  vlist.push_back(v);
}

void StdTreeBuilder::addListValue(string* s) {
  Value* val;
  int ival;
  for(int k=s->length()-2;k>0;k--) {
    ival = (int) (*s)[k];
    val = Value::constValue( encoding[ival] );
    vlist.push_back(val);
  }
}

void StdTreeBuilder::endValueList(int typ) {

  if(typ == SymTable::PO_ENC) typ = SymTable::PO_BYTE;

  Value** tmp = new Value*[vlist.size()];
  ValueList* res = new ValueList(typ,vlist.size(),tmp);
  
  for(size_t k=0;k<vlist.size();k++) {
    tmp[vlist.size()-1-k] = vlist[k];
    tmp[vlist.size()-1-k]->setParent(res);
  }
  
  res->setParent(curr);
  curr->addChild(res);
  vlist.clear();
  
}

void StdTreeBuilder::addCStr(string* str) {

  Value** tmp = new Value*[str->size()-1];
  ValueList* res = new ValueList(SymTable::PO_BYTE,str->size()-1,tmp);
  
  size_t k;
  for(k=1;k<str->size()-1;k++) {
    cerr << (*str)[k];
    tmp[k-1] = Value::constValue((*str)[k]);
    tmp[k-1]->setParent(res);
  }
  tmp[k-1] = Value::constValue(0);
  tmp[k-1]->setParent(res);

  cerr << "\n";
  res->setParent(curr);
  curr->addChild(res);

  delete str;

}
 
void StdTreeBuilder::parse() {

  root = RootScope::create();
  curr = global = root->getGlobalScope();
  
}

RootScope* StdTreeBuilder::getRootScope() {
  return root;
}

Value* StdTreeBuilder::anonLabel() {
  Label* a = curr->localLabel(SymTable::NO_NAME);
  return new Lookup(a);
}

bool StdTreeBuilder::parseEncLine(const char* line) {
  
  enum State { START, SOURCE, TARGET, FAIL, READY, COMMENT };

  State state = START;
  char token[128];
  int src = -1;
  int trg = -1;
  int pos = 0;

  while(*line && state != READY) {
    
    switch(*line) {
      
    case '9' :
    case '8' :
    case '7' :
    case '6' :
    case '5' :
    case '4' :
    case '3' :
    case '2' :
    case '1' :
    case '0' : 
      if (state == START)
	state = SOURCE;

      token[pos++] = *line++;
      
      break;
      
    case ':' : 
      if(state == SOURCE) {
	token[pos++] = '\0';
	src = atoi(token);
	pos = 0;
	state = TARGET;
      }
      else state = FAIL;      
      line++;
      break;
      
    case ' ' :
      line++;
      break;

    case '#' :
      if(state == START) 
	state = COMMENT;
      else if(state == TARGET)
	state = READY;
      else 
	state = FAIL;
      line++;
      break;

    default:
      state = FAIL;

    }

    if(state == FAIL) return false;
    else if(state == COMMENT) return true;
  }

  if (state == START) return true; 
  
  token[pos++] = '\0';
  trg = atoi(token);
  
  if(src < 256 && trg < 256) {
    encoding[src] = trg;
 } else 
    return false;

  return true;

}

void StdTreeBuilder::setEncoding(string* s) {

  string file = s->substr(1,s->length()-2);
  
  static char line[1024];
  ifstream in(file.c_str());
  int lcount = 1;

  if(!in) {
    PERR << "ERROR opening encoding file \"" << file << "\" \n";
    return;
  }

  for(int i=0;i<256;i++)
    encoding[i] = 0;

  while (!in.eof()) {
    in.getline(line,1024);
    if(! parseEncLine(line)) {
      PERR << "ERROR reading encoding \"" << file << "\" in line " 
	   << lcount << "\n"; 
    }
    lcount++;
  }
  
}

Label* StdTreeBuilder::localLabel(int name) {
  return curr->localLabel(name);
}

Label* StdTreeBuilder::globalLabel(int name) {
  return curr->globalLabel(name);
}

Label* StdTreeBuilder::exportLabel(int name) {
  return curr->exportLabel(name);
}

Label* StdTreeBuilder::memberLabel(int name) {
  return curr->memberLabel(name);
}

Definition* StdTreeBuilder::localDefine(int name, Value* val) {
  return curr->localDefine(name,val);
}

Definition* StdTreeBuilder::globalDefine(int name, Value* val) {
  return curr->globalDefine(name,val);
}

Definition* StdTreeBuilder::exportDefine(int name, Value* val) {
  return curr->exportDefine(name,val);
}

Definition* StdTreeBuilder::memberDefine(int name, Value* val) {
  return curr->memberDefine(name,val);
}


void StdTreeBuilder::op_implied(int opc) { 

  Opcode *o = new Opcode(opc,0);
  o->setMode(Opcode::A_IMP);

  o->setParent(curr);
  curr->addChild(o);
  
}

void StdTreeBuilder::op_immediate(int opc, Value* oper) { 

  Opcode *o = new Opcode(opc,oper);
  o->setMode(Opcode::A_IMM);

  o->setParent(curr);
  curr->addChild(o);
  
}


void StdTreeBuilder::op_indir_x(int opc, Value* oper, char reg) {   

  Opcode *o = new Opcode(opc,oper);

  INT_ERR << " " << reg << "\n";

  if(reg == 'x') 
    o->setMode(Opcode::A_IND_X);
  else {
    AERR(o) << "unsupported addressing mode ,x expected\n";
  }
  o->setParent(curr);
  curr->addChild(o);
  
}


void StdTreeBuilder::op_indir_y(int opc, Value* oper, char reg) { 

  Opcode *o = new Opcode(opc,oper);

  if(reg == 'y') 
    o->setMode(Opcode::A_IND_Y);
  else {
    AERR(o) << "unsupported addressing mode: ,y expected\n";
  }
  o->setParent(curr);
  curr->addChild(o);
  
}
 
void StdTreeBuilder::op_absrel(int opc, Value* oper, char reg) { 

  Opcode *o = new Opcode(opc,oper);
  
  if(reg == 'y') 
    o->setMode(Opcode::U_REL_Y);
  else 
    o->setMode(Opcode::U_REL_X);

  o->setParent(curr);
  curr->addChild(o);
  
}


void StdTreeBuilder::op_indirect(int opc, Value* oper) { 

  Opcode *o = new Opcode(opc,oper);
  o->setMode(Opcode::A_IND);
  o->setParent(curr);
  curr->addChild(o);
  
}


void StdTreeBuilder::op_absolute(int opc, Value* oper) { 
  
  Opcode *o = new Opcode(opc,oper);
  o->setMode(Opcode::U_ABS);
  o->setParent(curr);
  curr->addChild(o);
  
}

void StdTreeBuilder::error(const char* text) {
  SymTable::parseError(text);
}
