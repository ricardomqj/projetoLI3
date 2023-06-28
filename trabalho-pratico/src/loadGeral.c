#include "../includes/structs.h"

#include "../includes/hash.h"
#include "../includes/parserDrivers.h"
#include "../includes/parserUsers.h"
#include "../includes/parserRides.h"
#include "../includes/loadGeral.h"
#include <stdio.h>

void load_geral(Geral geral, char *path)
{
    parserDrivers(GetHashDrivers(geral), path);
    printf("fiz o parsing dos drivers\n");
    parserUsers(GetHashUsers(geral), path);
    printf("fiz o parsing dos users\n");
    parserRides(GetRides(geral), geral, path);
    printf("fiz o parsing das rides\n");

    organiza_rides(geral);

    top_Drivers_Aval(GetTopDrivers(geral),GetHashDrivers(geral));
    printf("fiz o GArray Top Drivers\n");
    top_User_Dist(GetTopUsers(geral),GetHashUsers(geral));
    printf("fiz o GArray Top Users\n");
}