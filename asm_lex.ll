
%{

#include <iostream>
#include "Number.h"
#include "Scope.h"
#include "RootScope.h"
#include "Value.h" 

#include "asm.h"


  extern Scope* root;
  extern Scope* curr;

  int yyparse();

%}

SCOPE     scope
MODULE    module
FUNC      func
ORG       org
PSEUDO    byte|str|word|cstr
PSBUFF    align|buf
PSEXPORT  export
PSGLOBAL  global
PSLOCAL   local
PSLINE    line
ENC       enc
ENCODING  encoding
TO        "."
OPCODE_1  adc|and|asl|bcc|bcs|beq|bit|bmi|bne|bpl|brk|bvc|bvs|clc|cld|cli|clv|cmp|cpx|cpy|dec|dex|dey|eor|inc|inx|iny|jmp|jsr|lda|ldx|ldy|lsr|nop|ora|pha|php|pla|plp|rol|ror|rti|rts|sbc|sec|sed|sei|sta|stx|sty|tax|tay|tsx|txa|txs|tya
DIV       MOD|mod
MOD       DIV|div
IDENT     [_a-zA-Z][_0-9a-zA-Z\.]*
IDENTT	  [0-9]*"$"
HEX       $[0-9a-fA-F]*
BIN       %[0-1]*
DEC       [0-9]+
DNCHEX	  $[0-9a-fA-F?]+
DNCBIN	  %[0-1?]+
STRING    \"([^\\"]|\\.)*\"

%%

";"             for(int c = yyinput(); c != '\n' ; c = yyinput()); SymTable::lex_line++;
"\n"            SymTable::lex_line++;
"\t"            ;
"{"             return '{';
"}"             return '}';
"["             return '[';
"]"             return ']';
"="             return '=';
"+"             return '+';
"-"             return '-';
"/"             return '/';
"*"             return '*';
"|"             return '|';
"&"             return '&';
"^"             return '^';
":"             return ':';
"("             return '(';
")"             return ')';
"#"             return '#';
"<"             return '<';
">"             return '>';
"."{SCOPE}      return SCOPE;
"."{MODULE}    	cerr << "module found\n"; return MODULE;
"."{FUNC}       return FUNC;
"."{ORG}        return ORG;
",x"            yylval.i = 'x'; return R_REL;
",y"            yylval.i = 'y'; return R_REL;
","             return ',';
{OPCODE_1}	yylval.i = SymTable::lookup(yytext); return OPCODE_1;
{DIV}           return DIV;
{MOD}           return MOD;
{DEC}		yylval.n = new Number(yytext,10); return DEC;
{DNCHEX}	yylval.n = new Number(yytext,16); return DNCHEX;
{DNCBIN}	yylval.n = new Number(yytext,2); return DNCBIN;
"."{PSEUDO}     yylval.i = SymTable::lookup(yytext); return PSEUDO;
"."{PSBUFF}     yylval.i = SymTable::lookup(yytext); return PSBUFF;
"."{PSLINE}     yylval.i = SymTable::lookup(yytext); return PSLINE;
"."{PSEXPORT}   yylval.i = SymTable::lookup(yytext); return PSEXPORT;
"."{PSGLOBAL}   yylval.i = SymTable::lookup(yytext); return PSGLOBAL;
"."{PSLOCAL}    yylval.i = SymTable::lookup(yytext); return PSLOCAL;
"."{ENCODING}   yylval.i = SymTable::lookup(yytext); return ENCODING;
"."{ENC}        yylval.i = SymTable::lookup(yytext); return ENC;
"."{TO}         yylval.i = SymTable::lookup(yytext); return TO;
{IDENT}":"	yylval.i = SymTable::mkLabel(yytext); return LABEL;
{IDENT}		yylval.i = SymTable::lookup(yytext); return IDENT;
{IDENTT}":"	yylval.i = SymTable::mkLabel(yytext); return LABEL;
{IDENTT}	yylval.i = SymTable::lookup(yytext); return IDENT;
"."             return '.';
{STRING}	yylval.s = new string(yytext); return STRING;
" "		;

%%

void yyendofline() {
  for(int c = yyinput(); c != '\n' ; c = yyinput()); 
  SymTable::lex_line++;
}

void nowarn() {
  // supress warning of unused yyunput(..)
  yyunput(10,"hallo");
}
