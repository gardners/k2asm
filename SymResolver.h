
#ifndef _SYM_RESOLVER_HEADER
#define _SYM_RESOLVER_HEADER

#include "NodeVisitor.h"

class SymResolver : public NodeVisitor {
  
 public:

  SymResolver();

  virtual bool visit(Node* n);
  
  virtual bool procNode(Node* n);
  virtual bool procOpcode(Opcode* n);
  virtual bool procLookup(Lookup* n);
  
};

#endif // _SYM_RESOLVER_HEADER
