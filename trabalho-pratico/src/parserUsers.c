#include "../includes/hash.h"
#include "../includes/parserDrivers.h"
#include "../includes/parserUsers.h"
#include "../includes/structs.h"
#include "../includes/date.h"
#include <stdio.h>

void parserUsers(GHashTable *hash, char* path)
{
    char pathusers[BUFSIZ];

    strcpy(pathusers, path);

    FILE *fusers = fopen(strcat(pathusers,"/users.csv"), "r");
    fseek(fusers, 75, SEEK_SET);

    char* result;

    char line[1024];

    char* tmp;

    while (fgets(line, 1024, fusers))
    {
        User Sujeito = init_user();

            for (int fc = 1; fc < 8; fc++)
            {
                tmp = strdup(line);

                switch (fc) {

                    case 1:
                    
                        result = getfield(tmp, fc);

                        if(result != NULL) {
                            set_User_username(Sujeito,result);                      
                        }
                        else goto fimdelinha;

                        break;
                    
                    case 2:
                    
                        result = getfield(tmp, fc);

                        if(result != NULL) {
                            set_User_name(Sujeito,result);                      
                        }
                        else goto fimdelinha;

                        break;
                    
                    case 3:
                    
                        result = getfield(tmp, fc);

                        if(result != NULL) {
                            set_User_gender(Sujeito,result);
                        }
                        else goto fimdelinha;

                        break;
                    
                    case 4:
                    
                        result = getfield(tmp, fc);

                        if (result != NULL) {
                            if (check_date(result) == 1) {
                                set_User_birth_date(Sujeito,result);
                            }
                            else goto fimdelinha;
                        }
                        else goto fimdelinha;

                        break;
                    
                    case 5:
                    
                        result = getfield(tmp, fc);

                        if (result != NULL) {
                            if (check_date(result) == 1) {
                                set_User_account_creation(Sujeito,result);
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

                        if (result != NULL) {
                            if (check_active_inactive(result) == 1) {
                                set_User_account_status(Sujeito,result);
                            }
                            else goto fimdelinha;
                        }
                        else goto fimdelinha;

                        break;
                }

            }
            set_User_distance(Sujeito,0);
            set_User_avaliacao(Sujeito,0);
            set_User_viagens(Sujeito,0);
            set_User_last_ride(Sujeito,convert_to_days("99/99/9999"));
            insertUser(hash, Sujeito);

            goto depois;

            fimdelinha:
                continue;

            depois:
                continue;

    }

    fclose(fusers);
}
