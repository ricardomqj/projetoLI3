#ifndef drivers_h
#define drivers_h

#include "structs.h"

typedef struct driver *Driver;

Driver init_driver();

void set_Driver_id(Driver driv,char *id);

void set_Driver_name(Driver driv,char *name);

void set_Driver_bith_date(Driver driv,char *birth_date);

void set_Driver_gender(Driver driv,char *gender);

void set_Driver_carclass(Driver driv,char *carclass);

//void set_Driver_license_plate(Driver driv,char *license_plate);

//void set_Driver_city(Driver driv,char *city);

void set_Driver_account_creation(Driver driv,char *account_creation);

void set_Driver_account_status(Driver driv,char *account_status);

void set_Driver_totalgasto(Driver driv,double totalgasto);

void set_Driver_viagens(Driver driv,int viagens);

void set_Driver_avaliacao(Driver driv,int avaliacao);

void set_Driver_last_ride(Driver driv,int last_ride);

char* get_Driver_id(Driver driv);

char* get_Driver_name(Driver driv);

char* get_Driver_bith_date(Driver driv);

char get_Driver_gender(Driver driv);

char get_Driver_carclass(Driver driv);

//char* get_Driver_license_plate(Driver driv);

//char* get_Driver_city(Driver driv);

char* get_Driver_account_creation(Driver driv);

char get_Driver_account_status(Driver driv);

double get_Driver_totalgasto(Driver driv);

int get_Driver_viagens(Driver driv);

int get_Driver_avaliacao(Driver driv);

int get_Driver_last_ride(Driver driv);

void update_last_ride_Driv(Driver driv, char *data, char *aval);

void cleanDriver(Driver driv);

#endif