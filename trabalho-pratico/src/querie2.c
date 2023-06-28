#include <stdio.h>

#include "../includes/hash.h"
#include "../includes/structs.h"
#include "../includes/querie2.h"
#include "../includes/queries.h"
#include "../includes/avaliacao_driver.h"

void conta_viagens_driver(char *idDriver, Geral geral)
{
    GHashTable *hashDrivers = GetHashDrivers(geral);

    Driver aux = lookupDriver(hashDrivers, idDriver);

    int aux_viagens = get_Driver_viagens(aux); 
    aux_viagens += 1;
    set_Driver_viagens(aux,aux_viagens);
    insertDriver(hashDrivers, aux);
}

void conta_avaliacoes_driver(char *idDriver, char *score_driver, Geral geral)
{
    GHashTable *hashDrivers = GetHashDrivers(geral);

    Driver aux = lookupDriver(hashDrivers, idDriver);
    int score = atoi(score_driver);
    int aux_avaliacao = get_Driver_avaliacao(aux); 
    aux_avaliacao += score;
    set_Driver_avaliacao(aux,aux_avaliacao);
}


void get_top_N_Drivers(Geral geral, int N, char *linha, char* outputstring)
{
    GArray *garray = GetTopDrivers(geral);
    
    char fullstring[1000000] = "";

    //printf("QUERY 2: \n");

    for (int i = 0; i < N; i++)
    {
       
        sprintf(fullstring,"%s;%s;%.3f\n", get_id_Aval_Driv_Fich(garray, i), get_name_Aval_Driv_Fich(garray, i), get_avaliacao_med_Aval_Driv_Fich(garray, i));

        strcat(outputstring, fullstring);
    }


}

void get_top_N_Drivers_interactive(Geral geral, int N, char* outputstring)
{
    GArray *garray = GetTopDrivers(geral);

    char fullstring[1000000] = "";
    
    for (int i = 0; i < N; i++)
    {
        sprintf(fullstring,"%s;%s;%.3f\n", get_id_Aval_Driv_Fich(garray, i), get_name_Aval_Driv_Fich(garray, i), get_avaliacao_med_Aval_Driv_Fich(garray, i));
    
        strcat(outputstring, fullstring);
    }

}