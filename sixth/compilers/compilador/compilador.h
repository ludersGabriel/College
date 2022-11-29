/* -------------------------------------------------------------------
 *            Arquivo: compilador.h
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [09/08/2020, 19h:01m]
 *
 * -------------------------------------------------------------------
 *
 * Tipos, protótipos e variáveis globais do compilador (via extern)
 *
 * ------------------------------------------------------------------- */

#define TAM_TOKEN 16

typedef enum simbolos {
  simb_program, simb_var, simb_begin, simb_end,
  simb_identificador, simb_numero,
  simb_ponto, simb_virgula, simb_ponto_e_virgula, simb_dois_pontos,
  simb_atribuicao, simb_abre_parenteses, simb_fecha_parenteses,
  simb_label, simb_type, simb_array, simb_of, simb_procedure, 
  simb_function, simb_goto, simb_if, simb_then, simb_else, 
  simb_while, simb_do, simb_or, simb_div, simb_and
} simbolos;

#include "stack.h"

/* -------------------------------------------------------------------
 * variáveis globais
 * ------------------------------------------------------------------- */

extern simbolos simbolo, relacao;
extern char token[TAM_TOKEN];
extern int nivelLexico;
extern int desloc;
extern int nl;
extern int qtdVar;

/* -------------------------------------------------------------------
 * prototipos globais
 * ------------------------------------------------------------------- */

void geraCodigo (char*, char*);
int yylex();
void yyerror(const char *s);

/* -------------------------------------------------------------------
 *  Adições à biblioteca
 * ------------------------------------------------------------------- */

typedef struct ELEMENTO_TABELA_SIMBOLOS {
  char* token;
  struct {
    int nivelLexico;
    int offset;
  };
  enum {
    UNDEFINED,
    INTEGER,
    BOOLEAN
  } type;

  enum {
    c_UNDEFINED,
    VS,
    PF
  }class;
} elTabelaSimbolos;

elTabelaSimbolos* elTabelaSimbolosConstructor(char* token, int nivelLexico, int offset, int type, int class);
void elTabelaSimbolosDestructor(elTabelaSimbolos* el);
void updateTypes(stack* s, char* type);
void printElTabelaSimbolos(elTabelaSimbolos* el);
int cleanLexicalLevel(stack* s, int level);

extern stack* tabelaSimbolos;