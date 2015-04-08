
%{

#include <iostream>
#include <stdlib.h>
#include <string>

#include "Value.h" 
#include "Expr.h" 
#include "SymTable.h" 
#include "CodeTreeBuilder.h"

extern CodeTreeBuilder* builder;

int yylex();
void yyendofline();
  
int yyerror(char* s) { return 0; }
   
%}

%union {
  Value* v;
  Number* n;
  int    i;
  string*  s;
}

%token <i> SCOPE
%token <i> MODULE
%token <i> FUNC
%token <i> PSEUDO
%token <i> PSBUFF
%token <i> PSLINE
%token <i> PSEXPORT
%token <i> PSGLOBAL
%token <i> PSLOCAL
%token <i> ENCODING
%token <i> ENC
%token <i> TO
%token <i> LABEL
%token <i> R_REL
%token <i> OPCODE_1
%token <i> IDENT
%token <n> DNCHEX
%token <n> DNCBIN
%token <n> DEC
%token <c> MOD
%token <c> DIV
%token <c> ORG
%token <s> STRING
%token <c> CHAR
%type <v> expr
%type <v> value

%left '<' '>'
%left '|' '^'
%left '&'
%left '-' '+'
%left '*' '/' DIV MOD
%left NEG

%%

input:				
	| input line		
;

line:   scope_def 
        | func_def 
        | label
        | assign 
        | op_1         
        | pseu   
	| ORG expr               { builder->setEnv(SymTable::PO_ORG,$2); }
	| ')' error              { builder->error("unmatched closing brace"); }
	| '}' error              { builder->error("unmatched closing scope"); }
        | PSEXPORT error	 { builder->error("assignment or label expected"); }
        | PSGLOBAL error	 { builder->error("assignment or label expected"); }
        | PSLOCAL error		 { builder->error("assignment or label expected"); }
	| '.' error              { builder->error("undefined pseudo opcode"); }
	| error			 { builder->error("unknown opcode or command"); }
;

scope_def: scope_start input scope_end
;

func_def: func_start input scope_end
;


scope_start : '{' 			{ builder->beginScope(); }
            | SCOPE IDENT '{'           { builder->beginNamedScope($2); }
            | MODULE IDENT '{'          { builder->beginModuleScope($2); }
            | MODULE expr '{'           { builder->beginModuleScope($2); }
            | SCOPE error               { builder->error("invalid scope declaration"); }
            | MODULE error              { builder->error("invalid module declaration"); }

;

scope_end :  '}'			{ builder->endScope(); }
	   | error                      { builder->error("scope end ('}') expected"); }
;

func_start : FUNC IDENT '{'             { builder->beginFuncScope($2); }
;

label:    LABEL                         { builder->localLabel($1); }
        | PSEXPORT LABEL		{ builder->exportLabel($2); }
        | '+' LABEL                     { builder->exportLabel($2); }
        | PSGLOBAL LABEL		{ builder->globalLabel($2); }
        | PSLOCAL LABEL		        { builder->memberLabel($2); }
;

pseu:     PSEUDO list                   { builder->endValueList($1); } 
        | PSEUDO STRING                 { builder->addCStr($2); } 
        | PSBUFF expr   	       	{ builder->addByteBuffer($1,$2); } 
        | PSBUFF expr expr 		{ builder->addByteBuffer($1,$2,$3); }
        | PSLINE DEC ',' STRING ',' DEC	{ builder->setFilePos($4,*($2)); }
        | ENCODING STRING               { builder->setEncoding($2); }
	| ENC slist			{ builder->endValueList($1); } 
;

slist:    expr                          { builder->addListValue($1); }	
        | expr ',' slist                { builder->addListValue($1); }
     	| STRING                        { builder->addListValue($1); }
        | STRING ',' slist              { builder->addListValue($1); }
	| error				{ builder->error("comma separedted list expected"); }
;

list:     expr                          { builder->addListValue($1); }
        | expr ',' list                 { builder->addListValue($1); }
	| expr ','  error		{ builder->error("comma separedted list expected"); }
;

op_1:   OPCODE_1			{ builder->op_implied($1); }
      | OPCODE_1 '#' expr		{ builder->op_immediate($1,$3); }
      | OPCODE_1 '(' expr R_REL ')'	{ builder->op_indir_x($1,$3,$4); }
      | OPCODE_1 '(' expr ')' R_REL 	{ builder->op_indir_y($1,$3,$5); }
      | OPCODE_1 expr R_REL		{ builder->op_absrel($1,$2,$3); }
      | OPCODE_1 '(' expr ')'		{ builder->op_indirect($1,$3); }
      | OPCODE_1 expr		        { builder->op_absolute($1,$2); }
      | OPCODE_1 error		        { builder->error("malformed operand"); }      
;

assign:   IDENT '=' expr                  { builder->localDefine($1,$3); }
        | IDENT '=' expr TO expr          { builder->localDefine($1,$3); }
        | IDENT '=' expr '[' expr ']'     { builder->localDefine($1,$3); }
	| PSGLOBAL IDENT '=' expr	  { builder->globalDefine($2,$4); }
	| PSEXPORT IDENT '=' expr	  { builder->exportDefine($2,$4); }
	| PSLOCAL IDENT '=' expr	  { builder->memberDefine($2,$4); }
;

expr:     value
        | '*'			{ $$ = builder->anonLabel(); }
        | '-' expr %prec NEG	{ $$ = Expr::expr(Value::constValue(0),$2, OpMinus::obj); }
	| expr '+' expr         { $$ = Expr::expr($1,$3, OpPlus::obj); }
        | expr '-' expr		{ $$ = Expr::expr($1,$3, OpMinus::obj); }
        | expr '*' expr		{ $$ = Expr::expr($1,$3, OpMult::obj); }
	| expr '/' expr		{ $$ = Expr::expr($1,$3, OpDiv::obj); }
        | expr DIV expr		{ $$ = Expr::expr($1,$3, OpDiv::obj); }
        | expr MOD expr		{ $$ = Expr::expr($1,$3, OpMod::obj); }
        | expr '|' expr		{ $$ = Expr::expr($1,$3, OpBitOr::obj); }
        | expr '&' expr		{ $$ = Expr::expr($1,$3, OpBitAnd::obj); }
        | expr '^' expr		{ $$ = Expr::expr($1,$3, OpBitXor::obj); }
        | '(' expr ')'		{ $$ = $2; } 
        | '<' expr 		{ $$ = Expr::unaryExpr($2, OpLowByte::obj); }
	| '>' expr              { $$ = Expr::unaryExpr($2, OpHighByte::obj); }
        | expr '>' expr         { $$ = Expr::expr($1,$3, OpShr::obj); }
        | expr '<' expr         { $$ = Expr::expr($1,$3, OpShl::obj); }
        | '(' error             { $$ = Value::constValue(0); 
                                  builder->error("invalid expression, ')' expected"); }
        | error                 { $$ = Value::constValue(0); 
                                  builder->error("invalid expression"); }
;

value:    DNCHEX		{ $$ = Value::constValue(*($1)); }
        | DNCBIN		{ $$ = Value::constValue(*($1)); }
        | DEC			{ $$ = Value::constValue(*($1)); }
	| IDENT                 { $$ = Value::lookupValue($1); }
        | error			{ $$ = Value::constValue(0); 
                                  builder->error("maformed value"); }
;

%%
