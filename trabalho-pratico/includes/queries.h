#ifndef queries_h
#define queries_h

#include "parserRides.h"
#include "structs.h"
#include <stdio.h>
#include <string.h>
#include "query1.h"
#include "querie2.h"
#include "querie3.h"
#include "querie4.h"
#include "hash.h"

int read_query_info(char *path, int n, char *str1, char *str2, char *str3, char *str4);
void percorre_comandos(char *path, char *sols, int verifytests, Geral geral);
void criaficheiro(char *linha, char *fullstr, char *pathres, char *commandx);
void criaficheirodouble(char *linha, char *fullstr, char *pathres, char *commandx);
double timer(double start, double end);
void printTime(double t, int query, int valid);
int compareFiles(char *pathres, char *pathsol, char *commandx);

#endif