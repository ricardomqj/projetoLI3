#ifndef parserDrivers_h
#define parserDrivers_h

#include "structs.h"

char *getfield(char *line, int num);

void modified_getfield(char *line, int num, char *field, int field_size);

void parserDrivers(GHashTable *hash, char *path);

#endif