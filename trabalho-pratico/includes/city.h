#ifndef city_h
#define city_h

typedef struct city *City;

City init_City();

void set_City_cityname(City city,char *cityname);

void set_City_preco(City city,double preco);

void set_City_viagens(City city,int viagens);

char* get_City_cityname(City city);

double get_City_preco(City city);

int get_City_viagens(City city);

GList *get_City_drivers(City city);

void cleanCity(City city);

#endif