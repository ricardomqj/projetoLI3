
#include "../includes/structs.h"

struct city_driver
{
    char* idDriver;
    char* driver_name;
    short avaliacao;
    int viagens;
};

CityDriver init_city_driver()
{
    CityDriver city_driver = malloc(sizeof(struct city_driver));

    city_driver->idDriver = NULL;
    city_driver->avaliacao = 0;
    city_driver->viagens = 0;

    return city_driver;
}

void set_city_driver_id(CityDriver city_driver, char *id)
{
    city_driver->idDriver = id;
}

void set_city_driver_aval(CityDriver city_driver, float avaliacao)
{
    city_driver->avaliacao = avaliacao;
}

void set_city_driver_viagens(CityDriver city_driver, int viagens)
{
    city_driver->viagens = viagens;
}

char* get_city_driver_id(CityDriver city_driver)
{
    return strdup(city_driver->idDriver);
}

short get_city_driver_aval(CityDriver city_driver)
{
    return city_driver->avaliacao;
}

int get_city_driver_viagens(CityDriver city_driver)
{
    return city_driver->viagens;
}

City get_Value_City(gpointer value)
{
    City aux = (City)value;
    return aux;
}

//------------------

int compare_city_driv(gconstpointer a,gconstpointer b)
{
   const CityDriver dA = (CityDriver)a;
   const CityDriver dB = (CityDriver)b;

    return strcmp(get_city_driver_id(dA), get_city_driver_id(dB));
}

void insertCityDriver(CityDriver citydriver,City city) 
{
    //GList* find_city_driv = g_list_find_custom(get_City_drivers(city), citydriver, compare_city_driv);
    GList* list = get_City_drivers(city);
    CityDriver aux;
    int key = 0;
   
   while(list != NULL)
   {
        printf("estou aqui!\n");
        aux = (CityDriver)list->data;

        if(strcmp(aux->idDriver,citydriver->idDriver) == 0)
        {

            aux->viagens += 1;
            aux->avaliacao += citydriver->avaliacao;
            key = 1;
            break;
        }

        list = g_list_next(list);
   }

   /*
    if(find_city_driv != NULL) 
    {
        printf("estou aqui!\n");
        CityDriver city_driv = find_city_driv->data;

        city_driv->viagens += 1;
        city_driv->avaliacao += citydriver->avaliacao;

        find_city_driv->data = city_driv;
    }
    */

    if(key == 0)
    {
        citydriver->viagens = 1;
        GList* list =  get_City_drivers(city);
        list = g_list_prepend(list, citydriver);
    }
}

double calcula_aval_med(CityDriver driv)
{
    return (double)driv->avaliacao / driv->viagens;
}

int organiza_city_driv(gconstpointer a,gconstpointer b)
{
    const CityDriver drivA = (CityDriver) a;
    const CityDriver drivB = (CityDriver) b;

    if(calcula_aval_med(drivA) > calcula_aval_med(drivB))
        return -1;

    if(calcula_aval_med(drivA) < calcula_aval_med(drivB))
        return 1;
    else
    {
        if(strcmp(drivA->idDriver,drivB->idDriver) > 0)
            return 1;

        else
            return -1;
    }    
}

void organiza_list_city(City city)
{
    GList *list = get_City_drivers(city);

    list = g_list_sort(list,(GCompareFunc) organiza_city_driv);
}

void organiza_lists_hashCity(GHashTable *hashcity)
{
    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init(&iter, hashcity);
    while (g_hash_table_iter_next(&iter, &key, &value))
    {
        City city = get_Value_City(value);
        organiza_list_city(city);
    }
}