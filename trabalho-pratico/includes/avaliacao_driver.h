#ifndef avaliacao_driver_h
#define avaliacaoo_driver_h

#include "structs.h"

typedef struct aval_driver Aval_Driver;

void set_name_Aval_Driv(Aval_Driver d1, char *name);

void set_id_Aval_Driv(Aval_Driver d1, char* id);

void set_last_ride_days_Aval_Driv(Aval_Driver d1, int last_ride);

void set_avaliacao_med_Aval_Driv(Aval_Driver d1, int avalicao_med);

int get_avaliacao_med_Aval_Driv(Aval_Driver d1);

int get_last_ride_days_Aval_Driv(Aval_Driver d1);

char* get_id_Aval_Driv_Fich(GArray *garray, int i);

char *get_name_Aval_Driv_Fich(GArray *garray, int i);

double get_avaliacao_med_Aval_Driv_Fich(GArray *garray, int i);

GArray *init_garray_Aval_Driv();

void insert_Aval_Driv_Array(char *nome, char* id, int last_ride, double avaliacao_med, int index, GArray *garray);

int compare_Aval_Driv(gconstpointer a, gconstpointer b);

Driver get_Value_Driv(gpointer value);

double avaliacao_med_driver(Driver driver);

Aval_Driver get_Index_Aval_Driver(GArray *garray, int index);

void top_Drivers_Aval(GArray *garray, GHashTable *hashDriv);

#endif