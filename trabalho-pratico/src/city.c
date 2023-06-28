#include "../includes/structs.h"

struct city
{
    char *cityname;
    double preco;
    int viagens;
    GList *drivers;
};


City init_City()
{
    City city =  malloc(sizeof(struct city));
    
    city->cityname = NULL;
    city->preco = 0;
    city->viagens = 0;
    city->drivers = NULL;

    return city;
}

// setters 

void set_City_cityname(City city,char *cityname)
{
    city->cityname = cityname;
}

void set_City_preco(City city,double preco)
{
    city->preco = preco;
}

void set_City_viagens(City city,int viagens)
{
    city->viagens = viagens;
}

// getters 

char* get_City_cityname(City city)
{
    return strdup(city->cityname);
}

double get_City_preco(City city)
{
    return city->preco;
}

int get_City_viagens(City city)
{
    return city->viagens;
}

GList *get_City_drivers(City city)
{
    return city->drivers;
}

void cleanCity(City city)
{
    free(city->cityname);

    free(city);
}