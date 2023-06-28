#ifndef city_driver_h
#define city_driver_h

typedef struct city_driver *CityDriver;

CityDriver init_city_driver();


void set_city_driver_cityname(CityDriver city_driver, char *cityname);

void set_city_driver_id(CityDriver city_driver, char *id);

void set_city_driver_aval(CityDriver city_driver, float avaliacao);

void set_city_driver_viagens(CityDriver city_driver, int viagens);

void set_city_driver_last_Ride_days(CityDriver city_driver, int last_ride);

char* get_city_driver_cityname(CityDriver city_driver);

char* get_city_driver_id(CityDriver city_driver);

short get_city_driver_aval(CityDriver city_driver);

int get_city_driver_viagens(CityDriver city_driver);

int get_city_driver_last_Ride_days(CityDriver city_driver);

int compare_city_driv(gconstpointer a,gconstpointer b);

void insertCityDriver(CityDriver citydriver, City city);

double calcula_aval_med(CityDriver driv);

int organiza_city_driv(gconstpointer a,gconstpointer b);

void organiza_list_city(City city);

void organiza_lists_hashCity(GHashTable *hashcity);

#endif