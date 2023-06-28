#include "../includes/structs.h"
#include "../includes/hash.h"
#include "../includes/query1.h"
#include "../includes/querie2.h"
#include "../includes/querie3.h"
#include "../includes/querie4.h"
#include "../includes/parserDrivers.h"

#include <stdio.h>

void parserRides(GList *list, Geral geral, char *path)
{
    
    char pathrides[BUFSIZ];

    strcpy(pathrides, path);

    FILE *frides = fopen(strcat(pathrides, "/rides.csv"), "r");

    fseek(frides, 70, SEEK_SET);

    GHashTable *hashDriv = GetHashDrivers(geral);
    GHashTable *hashUser = GetHashUsers(geral);
    GHashTable *hashCity = GetHashCity(geral);

    char tmp[1024] = "";

    char line[1024];

    char* result1;
    char* result2;
    char* result3;
    char* resultESP;
    char* result5;
    char* result6;
    char* result7;
    char* result8;
    char* result9;

    while (fgets(line, 1024, frides))
    {
        Ride rides = init_ride();

        CityDriver citydriver = init_city_driver();

            for (int fc = 1; fc < 10; fc++)
            {
                strcpy(tmp, line);

                switch (fc) {
                
                    case 1:
                    
                        result1 = getfield(tmp, fc);

                        if(result1 != NULL) {
                            set_Ride_id(rides,result1);
                        }
                        else goto fimdelinha;

                        break;
                    
                    case 2:
                    
                        result2 = getfield(tmp, fc);

                        if (result2 != NULL) {
                            if (check_date(result2) == 1) {
                                    set_Ride_data(rides,result2);
                            }
                            else goto fimdelinha;
                        }
                        else goto fimdelinha;

                        break;
                    
                    case 3:
                    
                        result3 = getfield(tmp, fc);
                        
                        if (result3 != NULL) {
                            if (lookupDriver(GetHashDrivers(geral),result3) == NULL)
                            {
                                goto fimdelinha;
                            }    
                            else {
                                set_Ride_idDriver(rides,result3);
                                set_city_driver_id(citydriver, result3);
                            }
                        }
                        else goto fimdelinha; 

                        break;
                    
                    case 4:
                    
                        resultESP = getfield(tmp, fc);

                        if (resultESP != NULL) {
                            set_Ride_username(rides,resultESP);
                        }
                        else goto fimdelinha;

                        break;
                    
                    case 5:
                    
                        result5 = getfield(tmp, fc);

                        if (result5 != NULL) {
                            set_Ride_city(rides,result5);


                            if (!g_hash_table_contains(GetHashCity(geral),result5))
                            {
                                City aux = init_City();
                                set_City_cityname(aux,result5);
                                set_City_preco(aux,0);
                                set_City_viagens(aux,0);
                                
                                insertCity(GetHashCity(geral), aux);
                            }

                        }
                        else goto fimdelinha;

                        break;
                    
                    case 6:
                    
                        result6 = getfield(tmp, fc);

                        if (result6 != NULL) {
                            if (check_integer(result6) == 1)
                            {
                                set_Ride_distance(rides,result6);


                            }
                            else goto fimdelinha;
                        }
                        else goto fimdelinha;

                        break;
                    
                    case 7:
                    
                        result7 = getfield(tmp, fc);

                        if (result7 != NULL) {
                            if (check_integer(result7) == 1) {                                
                                set_Ride_score_user(rides,result7);
                            }
                            else goto fimdelinha;
                        }
                        else goto fimdelinha;

                        break;
                    
                    case 8:
                    
                        result8 = getfield(tmp, fc);

                        if (result8 != NULL) {
                            if (check_integer(result8) == 1) {
                                set_Ride_score_driver(rides,result8);
                                set_city_driver_aval(citydriver,atoi(result8));
                            }
                            else goto fimdelinha;
                        }
                        else goto fimdelinha;

                        break;
                    
                    case 9:
                    
                        result9 = getfield(tmp, fc);

                        if (result9 != NULL) {
                            if (check_tip(result9) == 1) {
                                set_Ride_tip(rides,result9);
                            }
                            else goto fimdelinha;
                        }
                        else goto fimdelinha;

                        break;

                }
                strcpy(tmp, "");
            }
            char* ride_tip = get_Ride_tip(rides);
            char* ride_distance = get_Ride_distance(rides);
            char* ride_username = get_Ride_username(rides);
            char* ride_idDriver = get_Ride_idDriver(rides);
            char* ride_data = get_Ride_data(rides);
            char* ride_city = get_Ride_city(rides);
            int ride_id = get_Ride_id(rides);

            //1

            //2

            //3
            conta_viagens_driver(result3, geral);
            //4
            conta_viagens_user(resultESP, geral);
            //5
            conta_viagens_city(result5, geral);
            //6
            soma_distance_User(ride_username , ride_distance, geral);
            preco_total_city(lookupDriver(hashDriv,ride_idDriver),ride_distance, ride_city, geral);
            //7
            set_Ride_score_user(rides,result7);
            conta_avaliacoes_user(ride_username,result7, geral);
            update_last_ride_User(lookupUser(hashUser,ride_username),ride_data,result7);
            //8
            conta_avaliacoes_driver(ride_idDriver,result8 , geral);
            update_last_ride_Driv(lookupDriver(hashDriv,ride_idDriver),ride_data,result8);
         
            //9
            preco_total_driver(lookupDriver(hashDriv,ride_idDriver),ride_distance,ride_idDriver,ride_tip, geral);
            preco_total_user(lookupDriver(hashDriv,ride_idDriver),ride_distance,ride_username,ride_tip, geral);
            acrescentaStructDay(GetPtrArrayDay(geral),lookupDriver(hashDriv,ride_idDriver),ride_data,ride_distance,ride_id,ride_city,ride_tip);            
                
            if(get_Driver_account_status(lookupDriver(hashDriv,result3)) == 'a') {
                insertCityDriver(citydriver, lookupCity(GetHashCity(geral),result5));
            }

            insertRide(rides, geral);

            free(ride_tip);
            free(ride_distance);
            free(ride_username);
            free(ride_idDriver);
            free(ride_data);

            goto depois;

            fimdelinha: 
                continue;

            depois:
                continue;

    }

    fclose(frides);
}