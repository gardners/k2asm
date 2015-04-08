AM_YFLAGS=-d

bin_PROGRAMS = k2asm
bin_SCRIPTS = k2pp

EXTRA_DIST = k2pp

k2asm_SOURCES = \
     ByteBuffer.cc ByteBuffer.h \
     Expr.cc Expr.h \
     FuncScope.cc FuncScope.h \
     Label.cc Label.h \
     Definition.cc Definition.h \
     Lookup.cc Lookup.h \
     NamedScope.cc NamedScope.h \
     ModuleScope.cc ModuleScope.h \
     NamedValue.cc NamedValue.h \
     Node.cc Node.h \
     Opcode.cc Opcode.h \
     RootScope.cc RootScope.h \
     Scope.cc Scope.h \
     SymTable.cc SymTable.h \
     Value.cc Value.h \
     ValueList.cc ValueList.h \
     NodeVisitor.cc NodeVisitor.h \
     NodeTypes.h \
     PrettyPrinter.cc PrettyPrinter.h \
     SymResolver.cc SymResolver.h \
     ValueResolver.cc ValueResolver.h \
     CodeGen.cc CodeGen.h \
     CodeTreeBuilder.h \
     StdTreeBuilder.cc StdTreeBuilder.h \
     Operator.cc Operator.h \
     Number.cc Number.h \
     main.cc \
     asm.yy asm_lex.ll asm.h \
     ConstValue.h \
     FileInfo.h


k2asm_LDADD=-lfl
k2asm_CXXFLAGS= -DBINDIR=\"$(bindir)\"

CXXFLAGS=-Wall -g
