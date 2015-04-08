
#ifndef _NODE_HEADER
#define _NODE_HEADER

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "SymTable.h"
#include "NodeVisitor.h"

#define INT_ERR cerr << __FILE__ << ":" << __PRETTY_FUNCTION__ << ":" << dec << __LINE__ << ":" 


#define AERR(NODE) SymTable::err(); \
cerr << SymTable::currFile() << ":"  << dec << NODE->getPos()  << ":" << hex 
#define PERR SymTable::err(); \
cerr << SymTable::currFile() << ":" 
#define VERB cerr << __FILE__ << ":" << __LINE__ << ":"

#define DBG(a)
//#define DBG(a) cerr << a << endl

using namespace std;

class Value;

class Node {

protected:
  Node* parent;
  int pos;

  Node();

 protected:
  Value* replaceEval(Value* v);

 public:

  int getPos() const { return pos; }

  virtual void setParent(Node* par, int ipos = -1);
  Node* getParent(); 
  
  virtual int childCount() const = 0;
  virtual Node* getChild(int idx) const = 0; 
  virtual bool hasChilds();
  
  virtual int lookupName();
  virtual int localName();
  virtual int globalName();
  
  virtual string strName();

  virtual int minCodeLen();
  virtual int maxCodeLen();
  virtual int codeLen();
  
  virtual bool receive(NodeVisitor* vis);
  
  virtual Node* find(int name, bool local = false);

  virtual ~Node();

};

#endif
