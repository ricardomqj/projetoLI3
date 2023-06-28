#ifndef querie4_h
#define querie4_h

#include "structs.h"

void conta_viagens_city(char *city, Geral geral);
void preco_total_city(Driver driv, char *distance, char *city, Geral geral);
double preco_medio(City city);
void returnquerie4(double preco, char *linha, char* output);
void returnquery4_interactive(double preco, char *output);

#endif
