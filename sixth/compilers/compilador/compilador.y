
// Testar se funciona corretamente o empilhamento de parametros
// passados por valor ou por referencia.

%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "stack.h"

int qtdVar, desloc;
stack* tabelaSimbolos;
int nivelLexico = -1;

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO
%token LABEL TYPE ARRAY OF PROCEDURE FUNCTION GOTO IF THEN ELSE WHILE DO OR DIV AND

%%

programa    :{
             geraCodigo (NULL, "INPP");
             }
             PROGRAM IDENT
             ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
             bloco PONTO {
             geraCodigo (NULL, "PARA");
             }
;

bloco       :
               {
                  desloc = 0;
                  nivelLexico += 1;
               }

               parte_declara_vars

               comando_composto
               {
                     int d = cleanLexicalLevel(tabelaSimbolos, nivelLexico);

                     if(d > 0){
                        char aux[20];
                        sprintf(aux, "DMEM %d", d);
                        geraCodigo(NULL, aux);  
                     }
                     
                     nivelLexico -= 1;
                     printElements(tabelaSimbolos);
               }
               ;




parte_declara_vars:  var
;


var         : { } VAR declara_vars
            |
;

declara_vars: declara_vars declara_var
            | declara_var
;

declara_var : { qtdVar = 0; }
              lista_id_var DOIS_PONTOS
              tipo
              { /* AMEM */
               char aux[20];
               sprintf(aux, "AMEM %d", qtdVar);
               geraCodigo (NULL, aux);

               // update tipo
               updateTypes(tabelaSimbolos, token);

               printElements(tabelaSimbolos);
              }
              PONTO_E_VIRGULA
;

tipo        : IDENT
;

lista_id_var: lista_id_var VIRGULA IDENT
              { 
                  elTabelaSimbolos* el = elTabelaSimbolosConstructor(
                     token,
                     nivelLexico,
                     desloc,
                     UNDEFINED,
                     VS
                  );
                  push(tabelaSimbolos, (void*) el);
                  desloc++;
                  qtdVar++;
              }
            | IDENT { 
               elTabelaSimbolos* el = elTabelaSimbolosConstructor(
                     token,
                     nivelLexico,
                     desloc,
                     UNDEFINED,
                     VS
                  );
                  push(tabelaSimbolos, (void*) el);
                  desloc++;
                  qtdVar++;
            }
;

lista_idents: lista_idents VIRGULA IDENT
            | IDENT
;


comando_composto: T_BEGIN comandos T_END

comandos:
;


%%

int main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }


/* -------------------------------------------------------------------
 *  Inicia a Tabela de Símbolos
 * ------------------------------------------------------------------- */
   tabelaSimbolos = stackConstructor(
      sizeof(elTabelaSimbolos),
      100,
      (void (*)(void*)) elTabelaSimbolosDestructor,
      (void (*)(void*)) printElTabelaSimbolos
   );

   yyin=fp;
   yyparse();

   return 0;
}
