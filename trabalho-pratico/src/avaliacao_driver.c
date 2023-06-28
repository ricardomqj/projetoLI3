#include "../includes/structs.h"

struct aval_driver
{
    char* id;
    char *name;
    double avaliacao_med;
    int last_ride_days;
};

void set_name_Aval_Driv(Aval_Driver d1, char *name)
{
    d1.name = name;
}

void set_id_Aval_Driv(Aval_Driver d1, char* id)
{
    d1.id = id;
}

void set_last_ride_days_Aval_Driv(Aval_Driver d1, int last_ride)
{
    d1.last_ride_days = last_ride;
}

void set_avaliacao_med_Aval_Driv(Aval_Driver d1, int avalicao_med)
{
    d1.avaliacao_med = avalicao_med;
}

int get_avaliacao_med_Aval_Driv(Aval_Driver d1)
{
    return d1.avaliacao_med;
}

int get_last_ride_days_Aval_Driv(Aval_Driver d1)
{
    return d1.last_ride_days;
}

char* get_id_Aval_Driv_Fich(GArray *garray, int i)
{
    Aval_Driver aux = get_Index_Aval_Driver(garray, i);
    return (aux.id);
}

char *get_name_Aval_Driv_Fich(GArray *garray, int i)
{
    Aval_Driver aux = get_Index_Aval_Driver(garray, i);
    return strdup(aux.name);
}

double get_avaliacao_med_Aval_Driv_Fich(GArray *garray, int i)
{
    Aval_Driver aux = g_array_index(garray, Aval_Driver, i);

    return aux.avaliacao_med;
}

GArray *init_garray_Aval_Driv()
{
    return g_array_new(!TRUE, TRUE, sizeof(struct aval_driver));
}

void insert_Aval_Driv_Array(char *nome, char* id, int last_ride, double avaliacao_med, int index, GArray *garray)
{

    Aval_Driver driver_avaliado;
    driver_avaliado.name = nome;
    driver_avaliado.id = id;
    driver_avaliado.last_ride_days = last_ride;
    driver_avaliado.avaliacao_med = avaliacao_med;

    g_array_insert_val(garray, index, driver_avaliado);
    index += 1;
}

int compare_Aval_Driv(gconstpointer a, gconstpointer b)
{
    const Aval_Driver *driverA = a;
    const Aval_Driver *driverB = b;

    if (driverA->avaliacao_med > driverB->avaliacao_med)
    {
        return -1;
    }
    if (driverA->avaliacao_med < driverB->avaliacao_med)
    {
        return 1;
    }
    else
    {
        if (driverA->last_ride_days > driverB->last_ride_days)
            return 1;
        if (driverA->last_ride_days < driverB->last_ride_days)
            return -1;
        else
        {
            if (strcmp(driverA->id, driverB->id) > 0)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
}

Aval_Driver get_Index_Aval_Driver(GArray *garray, int index)
{
    Aval_Driver aux = g_array_index(garray, Aval_Driver, index);
    return aux;
}

int compare_drivers_aval(gconstpointer a, gconstpointer b)
{
    return compare_Aval_Driv(a, b);
}

Driver get_Value_Driv(gpointer value)
{
    Driver aux = (Driver)value;
    return aux;
}

double avaliacao_med_driver(Driver driver)
{
    return ((double)get_Driver_avaliacao(driver) / get_Driver_viagens(driver));
}

void top_Drivers_Aval(GArray* garray,GHashTable* hashDriv)
{   
    guint index = 0;

    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init(&iter, hashDriv);
    while (g_hash_table_iter_next(&iter, &key, &value))
    {
        Driver driv = get_Value_Driv(value);
        char account_status = get_Driver_account_status(driv);
        if (account_status == 'a')
        {
            char* driv_name = get_Driver_name(driv);
            
            char* driv_id =  get_Driver_id(driv);

            insert_Aval_Driv_Array(driv_name, driv_id, get_Driver_last_ride(driv), avaliacao_med_driver(driv), index, garray);
        }
    }
    g_array_sort(garray, compare_drivers_aval);


}