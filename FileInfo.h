
#ifndef _FILE_INFO_HEADER
#define _FILE_INFO_HEADER

#include "Node.h"

class FileInfo : public Node {

  string fname;

  friend class Scope;

 protected:

 public:

  FileInfo(const string& name) : Node(), fname(name) {
  }

  virtual bool isResolved() { return false; }
  virtual string strName() { return fname; } 
  virtual Value* tryResolve() { SymTable::currFile(fname); return 0; } 

  virtual bool hasChilds() { return false; }
  virtual int childCount() const { return 0; }
  virtual Node* getChild(int idx) const { return 0; }

  virtual ~FileInfo() {}

  virtual void report(ostream& out) { out << ".file" << " " << strName() << "\n"; }
  
};

#endif
