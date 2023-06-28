#ifndef structs_h
#define structs_h

#include "glib.h"
#include "ncurses.h"
#include "drivers.h"
#include "users.h"
#include "rides.h"
#include "city.h"
#include "avaliacao_driver.h"
#include "dist_user.h"
#include "date.h"
#include "interactive_mode.h"
#include "query5.h"
#include "query6.h"
#include "city_driver.h"
#include "query8.h"
#include "query9.h"

#include <time.h>


Geral init_geral();

char *getfield(char *line, int num);

void modified_getfield(char *line, int num, char *field, int field_size);

int check_tip(char *str);

int tolower(int c);

int check_active_inactive(char *field1);

int check_carclass(char *field1);

int check_integer(char *str);

int check_scores(char *str);

int check_date(char *str);

void insertRide(Ride ride, Geral geral);

GHashTable *GetHashDrivers(Geral geral);

GHashTable *GetHashUsers(Geral geral);

GList *GetRides(Geral geral);

GHashTable *GetHashCity(Geral geral);

GArray *GetTopDrivers(Geral geral);

GArray *GetTopUsers(Geral geral);

GPtrArray *GetPtrArrayDay(Geral geral);

int ordena_ListRides_datas(gconstpointer a,gconstpointer b);

void organiza_rides(Geral geral);

void clean_geral(Geral geral);

#endif
