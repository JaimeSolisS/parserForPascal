%{     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 25 Jul 19   */

/* Jaime Solis 
UTEID: js96986*/
/* Copyright (c) 2019 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/* 14 Feb 01; 01 Oct 04; 02 Mar 07; 27 Feb 08; 24 Jul 09; 02 Aug 12 */
/* 30 Jul 13 */

/*
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.
; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.
; You should have received a copy of the GNU General Public License
; along with this program; if not, see <http://www.gnu.org/licenses/>.
  */


/* NOTE:   Copy your lexan.l lexical analyzer to this directory.      */

       /* To use:
                     make pars1y              has 1 shift/reduce conflict
                     pars1y                   execute the parser
                     i:=j .
                     ^D                       control-D to end input
                     pars1y                   execute the parser
                     begin i:=j; if i+j then x:=a+b*c else x:=a*b+c; k:=i end.
                     ^D
                     pars1y                   execute the parser
                     if x+y then if y+z then i:=j else k:=2.
                     ^D
           You may copy pars1.y to be parse.y and extend it for your
           assignment.  Then use   make parser   as above.
        */

        /* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
           the IF statement, but Yacc's default resolves it in the right way.*/

#include <stdio.h>
#include <ctype.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"
#include "pprint.h"

        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;

%}

/* Order of tokens corresponds to tokendefs.c; do not change */

%token IDENTIFIER STRING NUMBER   /* token types */
%token PLUS MINUS TIMES DIVIDE    /* Operators */
%token ASSIGN EQ NE LT LE GE GT POINT DOT AND OR NOT DIV MOD IN
%token COMMA                      /* Delimiters */
%token SEMICOLON COLON LPAREN RPAREN LBRACKET RBRACKET DOTDOT
%token ARRAY BEGINBEGIN           /* Lex uses BEGIN */
%token CASE CONST DO DOWNTO ELSE END FILEFILE FOR FUNCTION GOTO IF LABEL NIL
%token OF PACKED PROCEDURE PROGRAM RECORD REPEAT SET THEN TO TYPE UNTIL
%token VAR WHILE WITH

%%

program    : PROGRAM IDENTIFIER LPAREN idlist RPAREN SEMICOLON cblock DOT { parseresult = makeprogram($2, $4, $7); } ;
             ;
  u_constant :  NUMBER
             |  NIL 
             |  STRING
             ;
  sign       :  PLUS 
             |  MINUS
             ;
  constant   :  sign IDENTIFIER     { $$ = unaryop($1, $2); }
             |  IDENTIFIER        
             |  sign NUMBER         { $$ = unaryop($1, $2); }
             |  NUMBER
             |  STRING
             ;
  idlist     :  IDENTIFIER COMMA idlist { $$ = cons($1, $3); }
             |  IDENTIFIER    { $$ = cons($1, NULL); }
             ;
  cdef       :  IDENTIFIER EQ constant { instconst($1, $3); }
             ;
  clist      :  cdef SEMICOLON clist    
             |  cdef SEMICOLON          
             ;  
  tlist      :  IDENTIFIER EQ TYPE tlist
             |  IDENTIFIER EQ TYPE
             ;
  s_list     :  statement SEMICOLON s_list      { $$ = cons($1, $3); }
             |  statement
             ;
  cblock     :  CONST clist tblock              { $$ = $3; }
             |  tblock
             ;
  tblock     :  TYPE tlist vblock       { $$ = $3; }
             |  vblock
             ;
  vblock     :  VAR varspecs block       { $$ = $3; }
             |  block
             ;
  varspecs   :  vargroup SEMICOLON varspecs   
             |  vargroup SEMICOLON            
             ;
  vargroup   :  idlist COLON type { instvars($1, $3); }
             ;
  type       :  simpletype
             ;
  simpletype :  IDENTIFIER   { $$ = findtype($1); }
             ;
  block      :  BEGINBEGIN statement endpart   { $$ = makeprogn($1,cons($2, $3)); }  
             ;
  statement  :  BEGINBEGIN statement endpart   { $$ = makeprogn($1,cons($2, $3)); }
             |  IF expr THEN statement endif   { $$ = makeif($1, $2, $4, $5); }
             |  assignment
             |  funcall
             |  FOR assignment TO expr DO statement   { $$ = makefor(1, $1, $2, $3, $4, $5, $6); }
             |  REPEAT s_list UNTIL expr              { $$ = makerepeat($1, $2, $3, $4); }
             ;
  funcall    :  IDENTIFIER LPAREN expr_list RPAREN    { $$ = makefuncall($2, $1, $3); }
             ;
  expr_list  :  expr COMMA expr_list           { $$ = cons($1, $3); }
             |  expr
             ;
  endpart    :  SEMICOLON statement endpart    { $$ = cons($2, $3); }
             |  END                            { $$ = NULL; }
             ;
  endif      :  ELSE statement                 { $$ = $2; }
             |  /* empty */                    { $$ = NULL; }
             ;
  assignment :  variable ASSIGN expr         { $$ = binop($2, $1, $3); }
             ;
  variable   :  IDENTIFIER                            { $$ = findid($1); }
             ;
  plus_op    :  PLUS 
             |  MINUS  
             |  OR
             ;
  compare_op :  EQ 
             |  LT 
             |  GT 
             |  NE 
             |  LE 
             |  GE 
             |  IN
             ;
  times_op   :  TIMES 
             |  DIVIDE 
             |  DIV 
             |  MOD 
             |  AND
             ;
  s_expr     :  sign term                       { $$ = unaryop($1, $2); }
             |  term 
             |  s_expr plus_op term                 { $$ = binop($2, $1, $3); }
             ;
  expr       :  expr compare_op s_expr              { $$ = binop($2, $1, $3); }
             |  s_expr 
             ;
  term       :  term times_op factor              { $$ = binop($2, $1, $3); }
             |  factor
             ;
  factor     :  u_constant
             |  variable
             |  LPAREN expr RPAREN             { $$ = $2; }       
             |  funcall
             |  NOT factor          { $$ = unaryop($1, $2); }
             
%%

/* You should add your own debugging flags below, and add debugging
   printouts to your programs.
   You will want to change DEBUG to turn off printouts once things
   are working.
  */

#define DEBUG           0             /* set bits here for debugging, 0 = off  */
#define DB_CONS         1             /* bit to trace cons */
#define DB_BINOP        0             /* bit to trace binop */
#define DB_MAKEIF       0             /* bit to trace makeif */
#define DB_MAKEPROGN    0             /* bit to trace makeprogn */
#define DB_PARSERES     0            /* bit to trace parseresult */
#define DB_MAKEPROGRAM  0
#define DB_MAKEOP       0
#define DB_MAKEFUNCALL  0
#define DB_MAKEGOTO     0
#define DB_MAKELABEL    0
#define DB_MAKECOPY     0
#define DB_MAKENUMBER   0
#define DB_MAKEFOR      0

#define DB_UNOP         0
#define DB_FINDID       0  
#define DB_INSTCONST    1  
#define DB_MAKEREPEAT   0

 int labelnumber = 0;  /* sequential counter for internal label numbers */

   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */

/* cons links a new item onto the front of a list.  Equivalent to a push.
   (cons 'a '(b c))  =  (a b c)    */
TOKEN cons(TOKEN item, TOKEN list)           // add item to front of list 
  { item->link = list;
    if (DEBUG & DB_CONS){ 
      printf("cons\n");
      dbugprinttok(item);
      dbugprinttok(list);
    };
    return item;
  }

//NEW
  int isInteger(TOKEN tok) {
  if(tok->basicdt == INTEGER)
    return 1;
  else 
    return 0;
}
//NEW
int isReal(TOKEN tok) {
  if(tok->basicdt == REAL)
    return 1;
  else 
    return 0;
}
//NEW
/* makefloat forces the item tok to be floating, by floating a constant
   or by inserting a FLOATOP operator */   
TOKEN makefloat(TOKEN tok){

    TOKEN out; 
   if(tok->tokentype == NUMBERTOK) {
    tok->basicdt = REAL;
    tok->realval = (double) tok->intval;
    return tok;
  } else {
    TOKEN floatop = makeop(FLOATOP);
    floatop->operands = tok;
    return floatop;
  }
}
//NEW
/* binop links a binary operator op to two operands, lhs and rhs. */
TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs)        /* reduce binary operator */
{ op->operands = lhs;          /* link operands to operator       */
    lhs->link = rhs;             /* link second operand to first    */
    rhs->link = NULL;            /* terminate operand list          */
    if (DEBUG & DB_BINOP){ 
      printf("binop\n");
      dbugprinttok(op);
      dbugprinttok(lhs);
      dbugprinttok(rhs);
    };

    if (isReal(lhs) && isReal(rhs)) {
      op->basicdt = REAL;     
    } else if (isReal(lhs) && isInteger(rhs)) {
      op->basicdt = REAL;
      TOKEN ftok = makefloat(rhs);
      lhs->link = ftok;
    } else if (isInteger(lhs) && isReal(rhs)) {
      if (op->whichval == ASSIGNOP) {
        op->basicdt = INTEGER;
        TOKEN fixtok = makefix(rhs);
        lhs->link = fixtok;
      } else {
        op->basicdt = REAL;
        TOKEN ftok = makefloat(lhs);
        ftok->link = rhs;
      }
    } 

    return op;
}
//NEW
/* unaryop links a unary operator op to one operand, lhs */
TOKEN unaryop(TOKEN op, TOKEN lhs) {
  op->operands = lhs;
  lhs->link = NULL;
  if (DEBUG & DB_UNOP){ 
    printf("unaryop\n");
    dbugprinttok(op);
    dbugprinttok(lhs);
  };
  return op;  
}

/* makeif makes an IF operator and links it to its arguments.
   tok is a (now) unused token that is recycled to become an IFOP operator */
TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart)
{  tok->tokentype = OPERATOR;  /* Make it look like an operator   */
    tok->whichval = IFOP;
    if (elsepart != NULL) elsepart->link = NULL;
    thenpart->link = elsepart;
    exp->link = thenpart;
    tok->operands = exp;
    if (DEBUG & DB_MAKEIF){ 
      printf("makeif\n");
      dbugprinttok(tok);
      dbugprinttok(exp);
      dbugprinttok(thenpart);
      dbugprinttok(elsepart); 
    };
     return tok;
}

/* makeprogn makes a PROGN operator and links it to the list of statements.
   tok is a (now) unused token that is recycled. */
TOKEN makeprogn(TOKEN tok, TOKEN statements)
  {  tok->tokentype = OPERATOR;
     tok->whichval = PROGNOP;
     tok->operands = statements;
     if (DEBUG & DB_MAKEPROGN){ 
       printf("makeprogn\n");
       dbugprinttok(tok);
       dbugprinttok(statements);
      };
     return tok;
}

/* makeprogram makes the tree structures for the top-level program */
TOKEN makeprogram(TOKEN name, TOKEN args, TOKEN statements) {
    TOKEN tok = talloc();
    TOKEN nameToArgs = talloc();
    tok->tokentype = OPERATOR;
    tok->whichval = PROGRAMOP;
    tok->operands = name;
    nameToArgs = makeprogn(nameToArgs, args);
    name->link = nameToArgs;
    nameToArgs->link = statements;
    if (DEBUG & DB_MAKEPROGRAM) { 
      printf("makeprogram\n");
      dbugprinttok(tok);
      dbugprinttok(nameToArgs);
    };
    return tok;
  }

  /* instvars will install variables in symbol table.
   typetok is a token containing symbol table pointer for type. */
void instvars(TOKEN idlist, TOKEN typetok) {  
  SYMBOL typesym, sym; 
  int align;
  typesym = typetok->symtype;
  align = alignsize(typesym);
  while ( idlist != NULL )  {  
    sym = insertsym(idlist->stringval);
    sym->kind = VARSYM; 
    sym->offset = wordaddress(blockoffs[blocknumber], align);
    sym->size = typesym->size;
    blockoffs[blocknumber] = sym->offset + sym->size;
    sym->datatype = typesym;
    sym->basicdt = typesym->basicdt;
    idlist = idlist->link;
  };
}

//NEW
  /* findid finds an identifier in the symbol table, sets up symbol table
   pointers, changes a constant to its number equivalent */
TOKEN findid(TOKEN tok) { 
   SYMBOL sym, typ;
    sym = searchst(tok->stringval);
    
    tok->symentry = sym;
    
    
    if (sym->kind == CONSTSYM) {
      if (sym->basicdt == REAL) {
        tok->tokentype = NUMBERTOK;
        tok->basicdt = REAL;
        tok->realval = sym->constval.realnum;
      }
      else if (sym->basicdt == INTEGER) {
        tok->tokentype = NUMBERTOK;
        tok->basicdt = INTEGER;
        tok->intval = sym->constval.intnum;
      }

      if (DEBUG & DB_FINDID) { 
        dbugprinttok(sym);
        debugprinttok(tok);
      };
      return tok;
    }

    typ = sym->datatype;
    tok->symtype = typ;
    if ( typ->kind == BASICTYPE ||
         typ->kind == POINTERSYM)
        tok->basicdt = typ->basicdt;

    if (DEBUG & DB_FINDID) { 
      dbugprinttok(sym);
      debugprinttok(tok);
    };

    return tok;
  }

/* findtype looks up a type name in the symbol table, puts the pointer
   to its type into tok->symtype, returns tok. */
TOKEN findtype(TOKEN tok) {
    SYMBOL sym = searchst(tok->stringval);
    tok->symtype = sym;
    return tok;
}

/* makeop makes a new operator token with operator number opnum.
   Example:  makeop(FLOATOP)  */
TOKEN makeop(int opnum){
    TOKEN tok = talloc();
    tok->tokentype = OPERATOR;
    tok->whichval = opnum;
    if (DEBUG & DB_MAKEOP) {
      printf("makeop\n");
      dbugprinttok(tok);
    }
    return tok;
}

//NEW
/* makefix forces the item tok to be integer, by truncating a constant
   or by inserting a FIXOP operator */
TOKEN makefix(TOKEN tok){
  if(tok->tokentype == NUMBERTOK) {
    tok->basicdt = INTEGER;
    tok->intval = (int) tok->realval;
    return tok;
  } else { 
    TOKEN fixop = makeop(FIXOP);
    fixop->operands = tok;
    return fixop;
  }
}


/* makefuncall makes a FUNCALL operator and links it to the fn and args.
   tok is a (now) unused token that is recycled. */
TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args) {
  tok->tokentype = OPERATOR;
  tok->whichval = FUNCALLOP;
  tok->operands = fn;
  fn->link=args;
  if (DEBUG && DB_MAKEFUNCALL) {
      printf("makefuncall\n");
      dbugprinttok(tok);
  }
  return tok;
}

/* copytok makes a new token that is a copy of origtok */
TOKEN copytok(TOKEN origtok) {
  TOKEN copy = talloc();
  copy->tokentype = origtok->tokentype;
  copy->whichval = origtok->whichval;
  copy->basicdt = origtok->basicdt;
  copy->symtype = origtok->symtype;
  copy->symentry = origtok->symentry;
  copy->link = origtok->link;
  copy->intval = origtok->intval;
  copy->realval = origtok->realval;
  if (DEBUG & DB_MAKECOPY) {
    printf("copytok\n");
    dbugprinttok(copy);
  }
  return copy;
}

TOKEN makenumber(int number) {
  TOKEN tok = talloc();
  tok->tokentype = NUMBERTOK;
  tok->basicdt = INTEGER;
  tok->intval = number;
  if (DEBUG & DB_MAKENUMBER) {
      printf("makenumber\n");
      dbugprinttok(tok);
  }
  return tok;
}

/* makelabel makes a new label, using labelnumber++ */
TOKEN makelabel() {
  TOKEN tok = talloc();
  tok->tokentype = OPERATOR;
  tok->whichval = LABELOP;
  tok->operands = makenumber(labelnumber++);
  if (DEBUG & DB_MAKELABEL) {
      printf("makelabel\n");
      dbugprinttok(tok);
  }
  return tok;
}

/* makegoto makes a GOTO operator to go to the specified label.
   The label number is put into a number token. */
TOKEN makegoto(int label){
  TOKEN tok = talloc();
  tok->tokentype = OPERATOR;
  tok->whichval = GOTOOP;
  tok->operands = makenumber(label);
  if (DEBUG && DB_MAKEGOTO) {
    printf("makegoto\n");
    dbugprinttok(tok);
  }
  return tok;
}

/* makefor makes structures for a for statement.
   sign is 1 for normal loop, -1 for downto.
   asg is an assignment statement, e.g. (:= i 1)
   endexpr is the end expression
   tok, tokb and tokc are (now) unused tokens that are recycled. */
TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr, 
      TOKEN tokc, TOKEN statement) 
{
  tok = makeprogn(tok, asg);
  TOKEN label = makelabel();
  asg->link = label;

  TOKEN ifs = talloc();
  TOKEN body = talloc();
  body = makeprogn(body, statement);

  TOKEN leftoper = makeop(LEOP);
  ifs = makeif(ifs, leftoper, body, NULL);
  TOKEN iden1 = copytok(asg->operands);
  TOKEN iden2 = copytok(iden1);
  TOKEN iden3 = copytok(iden1);
  iden1->link = endexpr;
  leftoper->operands = iden1;

  TOKEN assgn = makeop(ASSIGNOP);
  TOKEN increment = makeop(PLUSOP);

  iden3->link=makenumber(1);
  increment->operands=iden3;
  iden2->link=increment;
  assgn->operands=iden2;

  int currentnum = labelnumber - 1;
  TOKEN gototok = makegoto(currentnum);
  assgn->link = gototok;
  statement->link = assgn;

  leftoper->link = body;
  ifs->operands = leftoper;
  label->link = ifs;
  if (DEBUG && DB_MAKEFOR) {
      printf("makefor\n");
      dbugprinttok(tok);
  }
  return tok;
}

//NEW
/* instconst installs a constant in the symbol table */
void  instconst(TOKEN idtok, TOKEN consttok){
  SYMBOL sym;
  sym = insertsym(idtok->stringval);
  sym->kind = CONSTSYM;
  sym->basicdt = consttok->basicdt;
  if(sym->basicdt == REAL) {
      sym->constval.realnum = consttok->realval;
     // sym->size = basicsizes[REAL];
  }

  if(sym->basicdt == INTEGER) 
      sym->constval.intnum = consttok->intval;
     // sym->size = basicsizes[INTEGER];

  if (DEBUG & DB_INSTCONST) {
    printf("install const\n");
    dbugprinttok(sym);
  }
}


//NEW
/* makerepeat makes structures for a repeat statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr){

   TOKEN label = makelabel();
   int current = labelnumber - 1;
   tok = makeprogn(tok, label);

   TOKEN body = tokb;
   body = makeprogn(body, statements);
   label->link = body;

   TOKEN gototok = makegoto(current);
   TOKEN emptytok = makeprogn((TOKEN) talloc(), NULL);
   emptytok->link = gototok;

   TOKEN ifs = talloc();
   ifs = makeif(ifs, expr, emptytok, gototok);
   body->link = ifs;

   if (DEBUG && DB_MAKEREPEAT) {
         printf("make repeat\n");
         dbugprinttok(tok);
   }

   return tok;  
}

int wordaddress(int n, int wordsize)
  { return ((n + wordsize - 1) / wordsize) * wordsize; }
 
yyerror(const char *s) /* commented in lexan.h */
  { 
    fprintf (stderr, "%s\n", s);
  }

main()
  { int res;
    initsyms();
    res = yyparse();
    printstlevel(1);          
    /* to shorten, change to:  printstlevel(1);  */
    //printst();
    printf("yyparse result = %8d\n", res);
    if (DEBUG & DB_PARSERES) 
      dbugprinttok(parseresult);
    ppexpr(parseresult);           /* Pretty-print the result tree */
  }