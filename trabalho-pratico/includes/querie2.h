#ifndef querie2_h
#define querie2_h

#include "structs.h"

void conta_viagens_driver(char *idDriver, Geral geral);

void conta_avaliacoes_driver(char *idDriver, char *score_driver, Geral geral);

int compare_drivers_aval(gconstpointer a, gconstpointer b);

void get_top_N_Drivers(Geral geral, int N, char *linha, char* outputstring);

void get_top_N_Drivers_interactive(Geral geral, int N, char* outputstring);

#endif
