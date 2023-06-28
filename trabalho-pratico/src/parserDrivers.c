#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/structs.h"
#include "../includes/hash.h"
#include "../includes/date.h"
#include "../includes/parserDrivers.h"

#define BUFFER 7200

void parserDrivers(GHashTable *hash, char *path)
{
    char pathdrivers[BUFSIZ];

    strcpy(pathdrivers, path);

    FILE *fdrivers = fopen(strcat(pathdrivers, "/drivers.csv"), "r");
    fseek(fdrivers, 86, SEEK_SET);

    char* tmp;

    char line[1024];

    char* result;

    while (fgets(line, 1024, fdrivers))
    {
        Driver Motorista = init_driver();

            for (int fc = 1; fc < 10; fc++)
            {
                tmp = strdup(line);

                switch (fc) {

                    case 1:
                    
                        result = getfield(tmp, fc);

                        if(result != NULL) {
                            set_Driver_id(Motorista, result);
                        }
                        else goto fimdelinha;

                        break;
                    
                    case 2:
                    
                        result = getfield(tmp, fc);

                        if(result != NULL) {
                            set_Driver_name(Motorista, result);
                        }
                        else goto fimdelinha;
                        
                        break;

                    case 3:
                    
                        result = getfield(tmp, fc);

                        if (result != NULL) {
                            if (check_date(result) == 1) {
                                set_Driver_bith_date(Motorista,result);
                            }
                            else goto fimdelinha;
                        }
                        else goto fimdelinha;
                    
                        break;

                    case 4:
                    
                        result = getfield(tmp, fc);

                        if(result != NULL) {
                            set_Driver_gender(Motorista, result);
                        }
                        else goto fimdelinha;

                        break;
                    
                    case 5:
                    
                        result = getfield(tmp, fc);

                        if (result != NULL) {
                            if (check_carclass(result) == 1) {
                                set_Driver_carclass(Motorista, result);
                            }
                            else goto fimdelinha;
                        }
                        else goto fimdelinha;

                        break;
                    
                    case 6:
                    
                        result = getfield(tmp, fc);

                        if(result != NULL) continue;
                        else goto fimdelinha;

                        break;
                    
                    case 7:
                    
                        result = getfield(tmp, fc);

                        if(result != NULL) continue;
                            //set_Driver_city(Motorista, result);                    
                        else goto fimdelinha;
                        
                        break;

                    case 8:
                    
                        result = getfield(tmp, fc);

                        if (result != NULL) {
                            if (check_date(result) == 1) {
                                set_Driver_account_creation(Motorista, result);
                            }
                            else goto fimdelinha;
                        }
                        else goto fimdelinha;
                    
                        break;

                    case 9:
                    
                        result = getfield(tmp, fc);

                        if (result != NULL) {
                            if (check_active_inactive(result) == 1) {
                                set_Driver_account_status (Motorista,result);
                            }
                            else goto fimdelinha;
                        }
                        else goto fimdelinha;
                        
                        break;
                }

            }
            set_Driver_avaliacao(Motorista,0);
            set_Driver_viagens(Motorista,0);
            set_Driver_last_ride(Motorista, convert_to_days("99/99/9999"));
            insertDriver(hash, Motorista);

            goto depois;

            fimdelinha:
                continue;

            depois:
                continue;

    }
    fclose(fdrivers);
}