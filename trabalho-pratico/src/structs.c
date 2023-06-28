#include <stdio.h>
#include "../includes/structs.h"

struct geral
{
    GHashTable *hashDriv;
    GHashTable *hashUser;
    GList *rides;
    GHashTable *hashCity;
    GArray *top_Drivers_Aval;
    GArray *top_User_Dist;
    GPtrArray *day;
};

Geral init_geral()
{
    Geral geral = malloc(sizeof(struct geral));

    geral->hashDriv = g_hash_table_new(g_str_hash, g_str_equal);
    geral->hashUser = g_hash_table_new(g_str_hash, g_str_equal);
    geral->rides = NULL;
    geral->hashCity = g_hash_table_new(g_str_hash, g_str_equal);

    geral->top_Drivers_Aval = init_garray_Aval_Driv();
    geral->top_User_Dist = init_garray_Dist_User();
    
    geral->day = createDates();

    return geral;
}

char *getfield(char *line, int num)
{
    char *tok;
    for (tok = strsep(&line, ";");
         tok && *tok;
         tok = strsep(&line, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int tolower(int c) {
  if (c >= 'A' && c <= 'Z') {
    return c + ('a' - 'A');
  } else {
    return c;
  }
}  

void insertRide(Ride ride, Geral geral) 
{
    geral->rides = g_list_prepend(geral->rides, ride);
}


int check_active_inactive(char *field1) {
  
    for (int i = 0; field1[i]; i++) {
        field1[i] = tolower(field1[i]);
    }

  
    if (strcmp(field1, "active") == 0 || strcmp(field1, "inactive") == 0) {
        return 1;
    } else {
        return 0;
    }
}

int check_carclass(char *field1) {
  
    for (int i = 0; field1[i]; i++) {
        field1[i] = tolower(field1[i]);
    }

  
    if (strcmp(field1, "basic") == 0 || strcmp(field1, "premium") == 0 || strcmp(field1, "green") == 0) {
        return 1;  // The input is valid
    } else {
       return 0;  // The input is not valid
    }
}


int check_integer(char *str) {
    int i = 0;

    if (str[0] == '-') return 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;  // The string is not an integer
        }
    }

    if (atoi(str) == 0) return 0;

    return 1;  // The string is an integer
}

int check_tip(char *str) {
    
    for(int i = 0; str[i] != '\0'; i++) {
        if(!((str[i] >= '0' && str[i] <= '9') || str[i] == '.')){
            return 0;
        }
    }

    return 1;
}

int check_date(char *str) {
    int day, month, year;

    if (sscanf(str, "%d/%d/%d", &day, &month, &year) != 3) {
        return 0;  // The string is not a valid date
    }

    if (day < 1 || day > 31) {
        return 0;  // The string is not a valid date
    }

    if (month < 1 || month > 12) {
        return 0;  // The string is not a valid date
    }

    if (year < 1000 || year > 9999) {
        return 0;  // The string is not a valid date
    }

  return 1;  // The string is a valid date
}

GHashTable *GetHashDrivers(Geral geral)
{
    return geral->hashDriv;
}

GHashTable *GetHashUsers(Geral geral)
{
    return geral->hashUser;
}

GList *GetRides(Geral geral)
{
    return geral->rides;
}

GHashTable *GetHashCity(Geral geral)
{
    return geral->hashCity;
}

GArray *GetTopDrivers(Geral geral)
{
    return geral->top_Drivers_Aval;
}

GArray *GetTopUsers(Geral geral)
{
    return geral->top_User_Dist;
}

GPtrArray *GetPtrArrayDay(Geral geral) 
{
    return geral->day;
}

int ordena_ListRides_datas(gconstpointer a,gconstpointer b)
{
    const Ride rideA = (Ride) a;
    const Ride rideB = (Ride) b;

    if (convert_to_days(get_Ride_data(rideA)) < convert_to_days(get_Ride_data(rideB)))
    {
        return -1;
    }
    else
        return 1;
}

void organiza_rides(Geral geral)
{
    geral->rides = g_list_sort(geral->rides,ordena_ListRides_datas);    
}

void clean_geral(Geral geral)
{
    printf("estou a limpar!!\n");

    GList *c;

    //Drivers

    c = g_hash_table_get_keys(geral->hashDriv);
    while (c != NULL) {
        free(c->data);
        c = g_list_next(c);
    }
    c = g_hash_table_get_values(geral->hashDriv);
    while (c != NULL) {
        cleanDriver(c->data);
        c = g_list_next(c);
    }
    g_hash_table_destroy(geral->hashDriv);

    //Users

    c = g_hash_table_get_keys(geral->hashUser);
    while (c != NULL) {
        free(c->data);
        c = g_list_next(c);
    }
    c = g_hash_table_get_values(geral->hashUser);
    while (c != NULL) {
        cleanUser(c->data);
        c = g_list_next(c);
    }
    g_hash_table_destroy(geral->hashUser);

    //Cities
/*
    c = g_hash_table_get_keys(geral->hashCity);
    while (c != NULL) {
        free(c->data);
        c = g_list_next(c);
    }
    c = g_hash_table_get_values(geral->hashCity);
    while (c != NULL) {
        cleanCity(c->data);
        c = g_list_next(c);
    }
    g_hash_table_destroy(geral->hashCity);
*/

    //list rides

    g_list_free(geral->rides);

    //array topDrivers

    g_array_free(geral->top_Drivers_Aval,TRUE);

    //array topUsers

    g_array_free(geral->top_User_Dist,TRUE);

}