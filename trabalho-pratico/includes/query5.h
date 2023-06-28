#ifndef querie5_h
#define querie5_h

#include "structs.h"

int conta_viagens_2datas(GPtrArray *days, char *dataA, char *dataB);

double conta_preco_total(GPtrArray *days, char *dataA, char *dataB);

double precoMed_2datas(GPtrArray *days, char *dataA, char *dataB);

void returnquerie5(double preco, char *linha, char *output);

void returnquerie5_interactive(double preco, char *output);

#endif