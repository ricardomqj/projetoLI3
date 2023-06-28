#include "../includes/structs.h"
#include "../includes/hash.h"

int account_age(char* account_creat)
{
    int idade_anos;
    int anos_dias = 0;

    anos_dias = convert_to_days(account_creat);
    anos_dias = 738312 - anos_dias;
    idade_anos = anos_dias / 365;

    return idade_anos;    
}

int organiza_gender(gconstpointer a,gconstpointer b,Geral geral)
{
    const Ride rideA =(Ride) a;
    const Ride rideB =(Ride) b;

    GHashTable* hashDriv = GetHashDrivers(geral);
    GHashTable* hashUser = GetHashUsers(geral);

    if( convert_to_days(get_Driver_account_creation(lookupDriver(hashDriv,get_Ride_idDriver(rideA)))) > convert_to_days(get_Driver_account_creation(lookupDriver(hashDriv,get_Ride_idDriver(rideB)))))
    {
        return 1;
    }
    if(convert_to_days(get_Driver_account_creation(lookupDriver(hashDriv,get_Ride_idDriver(rideA)))) < convert_to_days(get_Driver_account_creation(lookupDriver(hashDriv,get_Ride_idDriver(rideB)))))
    {
        return -1;
    }
    else
    {
        if(convert_to_days(get_User_account_creation((lookupUser(hashUser,get_Ride_username(rideA))))) > convert_to_days(get_User_account_creation((lookupUser(hashUser,get_Ride_username(rideB))))))
        {
            return 1;
        }
        if(convert_to_days(get_User_account_creation((lookupUser(hashUser,get_Ride_username(rideA))))) < convert_to_days(get_User_account_creation((lookupUser(hashUser,get_Ride_username(rideB))))))  
        {
            return -1;
        }
        else
        {
            if(get_Ride_id(rideA) > get_Ride_id(rideB))
                return 1;
            else
                return -1;
        }
    }
}

void filter_rides_gender_acc(Geral geral,char* gender,char* x,char* outputstring)
{
    GList *rides = g_list_first(GetRides(geral));
    GList *list_rides_by_gender = NULL;
    char string[1000000];
    GHashTable *hashDriv = GetHashDrivers(geral);
    GHashTable *hashUser = GetHashUsers(geral);

    Ride aux;
    int anos = atoi(x);

    //printf("%s\n",gender);

    while(rides != NULL)
    {
        aux = (Ride)rides->data;

        if (get_User_gender(lookupUser(hashUser, get_Ride_username(aux))) == get_Driver_gender(lookupDriver(hashDriv,get_Ride_idDriver(aux))) && 
            get_Driver_gender(lookupDriver(hashDriv,get_Ride_idDriver(aux))) == gender[0] &&
            account_age(get_User_account_creation(lookupUser(hashUser, get_Ride_username(aux)))) - anos >= 0 &&
            account_age(get_Driver_account_creation(lookupDriver(hashDriv,get_Ride_idDriver(aux)))) - anos >= 0)
            {
                if(get_User_account_status(lookupUser(hashUser, get_Ride_username(aux))) == 'a' && 
                get_Driver_account_status(lookupDriver(hashDriv,get_Ride_idDriver(aux))) == 'a')
                    list_rides_by_gender = g_list_prepend(list_rides_by_gender,aux);
            }        
            
        rides = g_list_next(rides);                
    }

    list_rides_by_gender = g_list_sort_with_data(list_rides_by_gender,(GCompareDataFunc)organiza_gender,geral);  

    while (list_rides_by_gender != NULL)
    {
        aux = (Ride)list_rides_by_gender->data;

        sprintf(string, "%s;%s;%s;%s\n",get_Ride_idDriver(aux), get_Driver_name(lookupDriver(hashDriv, get_Ride_idDriver(aux))),get_Ride_username(aux), get_User_name(lookupUser(hashUser, get_Ride_username(aux))));
        strcat(outputstring, string);
        list_rides_by_gender = g_list_next(list_rides_by_gender);           
    }
    g_list_free(list_rides_by_gender);
}
