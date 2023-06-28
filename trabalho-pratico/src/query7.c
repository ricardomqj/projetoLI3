#include "../includes/hash.h"
#include "../includes/querie4.h"
#include "../includes/queries.h"
#include "../includes/structs.h"
#include <stdio.h>

void get_top_N_drivers_city(Geral geral,char* city_name,char* outputstring)
{
    GHashTable* hashcity = GetHashCity(geral);
    City city = lookupCity(hashcity, city_name);
    GList* list = get_City_drivers(city);
    CityDriver aux;


    while (list != NULL)
    {
        aux = (CityDriver) list->data;

        //sprintf(string, "%s;%s;%s;%s\n",get_Ride_idDriver(aux), get_Driver_name(lookupDriver(hashDriv, get_Ride_idDriver(aux))),get_Ride_username(aux), get_User_name(lookupUser(hashUser, get_Ride_username(aux))));
        //strcat(outputstring, string);
        list = g_list_next(list);           
    }
}