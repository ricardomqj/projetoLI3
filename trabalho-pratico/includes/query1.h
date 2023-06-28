#ifndef query1_h
#define query1_h

#include "structs.h"
#include "hash.h"
#include "loadGeral.h"
#include "querie2.h"
#include "queries.h"
#include "date.h"

void define_output(Geral geral, char* identity, char* linha, char* output);
void define_output_interactive(Geral geral, char* iden,char* output);
void define_output_interactive(Geral geral, char* iden,char* output);
void preco_total_user(Driver driver, char *distance, char* user, char* tip, Geral geral);
void preco_total_driver(Driver driver, char *distance, char* idDriv,char* tip, Geral geral);
void conta_avaliacoes_user(char *username, char *score_user, Geral geral);
void conta_viagens_user(char *username, Geral geral);
int is_user_or_driver(char* identity, Geral geral);
int idade_driver(char* id, Geral geral);
int idade_user(char* id, Geral geral);

#endif