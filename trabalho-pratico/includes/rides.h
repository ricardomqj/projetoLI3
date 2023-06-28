#ifndef rides_h
#define rides_h

typedef struct ride *Ride;

Ride init_ride();

void set_Ride_id(Ride ride,char *id);

void set_Ride_data(Ride ride,char *data);

void set_Ride_idDriver(Ride ride,char *idDriver);

void set_Ride_username(Ride ride,char *username);

void set_Ride_city(Ride ride, char *city);

void set_Ride_distance(Ride ride,char *distance);

void set_Ride_score_user(Ride ride,char *score_user);

void set_Ride_score_driver(Ride ride,char *score_driver);

void set_Ride_tip(Ride ride,char *tip);

int get_Ride_id(Ride ride);

char *get_Ride_data(Ride ride);

char *get_Ride_idDriver(Ride ride);

char *get_Ride_username(Ride ride);

char *get_Ride_city(Ride ride);

char *get_Ride_distance(Ride ride);

char *get_Ride_score_user(Ride ride);

char *get_Ride_score_driver(Ride ride);

char *get_Ride_tip(Ride ride);

void cleanRide(Ride ride);

#endif