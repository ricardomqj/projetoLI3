#ifndef hash_h
#define hash_h

#include "structs.h"

GHashTable *createHash();

void insertDriver(GHashTable *hash, Driver driv);

int sizeHash(GHashTable *hash);

Driver lookupDriver(GHashTable *hash, char *id);

void insertUser(GHashTable *hash, User user);

User lookupUser(GHashTable *hash, char *username);

Ride lookupRide(GHashTable *hash, char *id);

void insertCity(GHashTable *hash, City city);

City lookupCity(GHashTable *hash, char *city);

#endif