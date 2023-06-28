#include "../includes/structs.h"
#include <stdio.h>

// Drivers section

void insertDriver(GHashTable *hash, Driver driv)
{
    g_hash_table_insert(hash, get_Driver_id(driv), driv);
}

Driver lookupDriver(GHashTable *hash, char *id)
{
    Driver driv;
    driv = g_hash_table_lookup(hash, id);
    return driv;
}


// Users section

void insertUser(GHashTable *hash, User user)
{ 
    g_hash_table_insert(hash, get_User_username(user), user);
}

User lookupUser(GHashTable *hash, char *username)
{
    return g_hash_table_lookup(hash, username);
}

// Cities section

void insertCity(GHashTable *hash, City city)
{
    g_hash_table_insert(hash, get_City_cityname(city), city);
}

City lookupCity(GHashTable *hash, char *city)
{
    return g_hash_table_lookup(hash, city);;
}