#include <stdio.h>

#include "../includes/structs.h"
#include "../includes/hash.h"
#include "../includes/querie3.h"
#include "../includes/queries.h"

void soma_distance_User(char *username, char *distancia, Geral geral)
{
    User aux = lookupUser(GetHashUsers(geral), username);
    int dist = atoi(distancia);
    int aux_distance = get_User_distance(aux);
    aux_distance += dist;
    set_User_distance(aux,aux_distance);
}

void Get_Top_User_Dist(Geral geral, int N, char *linha, char *outputstring)
{
    GArray *garray = GetTopUsers(geral);

    char fullstring[1000000] = "";

    for (int i = 0; i < N; i++)
    {
        sprintf(fullstring,"%s;%s;%d\n", get_username_Dist_User_Fich(garray,i), get_name_Dist_User_Fich(garray,i), get_distance_Dist_User_Fich(garray,i));

        strcat(outputstring,fullstring);
    }

}

void Get_Top_User_Dist_interactive(Geral geral, int N, char *outputstring)
{
    GArray *garray = GetTopUsers(geral);

    char fullstring[1000000] = "";

    for (int i = 0; i < N; i++)
    {
        sprintf(fullstring,"%s;%s;%d\n", get_username_Dist_User_Fich(garray,i), get_name_Dist_User_Fich(garray,i), get_distance_Dist_User_Fich(garray,i));

        strcat(outputstring,fullstring);
    }

}