#ifndef querie3_h
#define querie3_h

#include "structs.h"

void soma_distance_User(char *username, char *distancia, Geral geral);

void Get_Top_User_Dist(Geral geral, int N, char *linha, char *outputstring);

void Get_Top_User_Dist_interactive(Geral geral, int N, char *outputstring);

#endif