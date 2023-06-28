#include "../includes/structs.h"

struct ride
{
    char *data;
    char *idDriver;
    char *username;
    char *city;
    char *distance;
    char *score_user;
    char *score_driver;
    char *tip;
    int id;
};


Ride init_ride()
{
    Ride ride = malloc(sizeof(struct ride));

    ride->data = NULL;
    ride->idDriver = NULL;
    ride->username = NULL;
    ride->city = NULL;
    ride->distance = NULL;
    ride->score_user = NULL;
    ride->tip = NULL;

    return ride;
}

// setters

void set_Ride_id(Ride ride,char *id)
{
    ride->id = atoi(id);
}

void set_Ride_data(Ride ride,char *data)
{
    char* aux;
    aux = strdup(data);
    ride->data = aux;
}

void set_Ride_idDriver(Ride ride,char *idDriver)
{
    char* aux;
    aux = strdup(idDriver);
    ride->idDriver = aux;
}

void set_Ride_username(Ride ride,char *username)
{
    char* aux;
    aux = strdup(username);    
    ride->username = aux;
}

void set_Ride_city(Ride ride, char *city)
{
    char* aux;
    aux = strdup(city);    
    ride->city = aux;
}

void set_Ride_distance(Ride ride,char *distance)
{
    char* aux;
    aux = strdup(distance);
    ride->distance = aux;
}

void set_Ride_score_user(Ride ride,char *score_user)
{
    char* aux;
    aux = strdup(score_user);
    ride->score_user = aux;
}

void set_Ride_score_driver(Ride ride,char *score_driver)
{
    char* aux;
    aux = strdup(score_driver);    
    ride->score_driver = aux;
}

void set_Ride_tip(Ride ride,char *tip)
{
    char* aux;
    aux = strdup(tip);    
    ride->tip = aux;
}

// getters

int get_Ride_id(Ride ride)
{
    return (ride->id);
}

char *get_Ride_data(Ride ride)
{
    return strdup(ride->data);
}

char *get_Ride_idDriver(Ride ride)
{
    return strdup(ride->idDriver);
}

char *get_Ride_username(Ride ride)
{
    return strdup(ride->username);
}

char *get_Ride_city(Ride ride)
{
    return strdup(ride->city);
}

char *get_Ride_distance(Ride ride)
{
    return strdup(ride->distance);
}

char *get_Ride_score_user(Ride ride)
{
    return strdup(ride->score_user);
}

char *get_Ride_score_driver(Ride ride)
{
    return strdup(ride->score_driver);
}

char *get_Ride_tip(Ride ride)
{
    return strdup(ride->tip);
}

void cleanRide(Ride ride)
{
    free(get_Ride_data(ride));
    free(get_Ride_city(ride));
}