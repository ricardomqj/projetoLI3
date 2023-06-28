#ifndef querie6_h
#define querie6_h

#include "structs.h"
#include "date.h"

int conta_viagens_2datas_city (GPtrArray *days, char *dataA, char *dataB, char *cityArg);

double conta_distanciaTotal_2datas_city(GPtrArray *days, char *dataA, char *dataB, char *cityArg);

double distMedia_2datas_city(GPtrArray *days, char *dataA, char *dataB, char *cityArg);

void returnquerie6(double dist, char *linha, char *output);

void returnquerie6_interactive(double dist, char *output);

#endif