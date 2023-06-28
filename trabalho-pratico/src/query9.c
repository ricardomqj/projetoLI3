#include "../includes/structs.h"

int compara_viagnesDatas (gconstpointer a,gconstpointer b)
{
    const Ride rideA =(Ride) a;
    const Ride rideB =(Ride) b;

    if (atoi(get_Ride_distance(rideA)) > atoi(get_Ride_distance(rideB)))
    {
        return -1;
    }
    if(atoi(get_Ride_distance(rideA)) < atoi(get_Ride_distance(rideB)))
    {
        return 1;
    }
    else 
    {
        int A = convert_to_days(get_Ride_data(rideA));
        int B = convert_to_days (get_Ride_data(rideB));

        if(A > B)
        {
            return -1;
        }
        if(A < B)
        {
            return 1;
        }
        else
        {
            if(get_Ride_id(rideA) > get_Ride_id(rideB))
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
    }
}

void make_Glista_grojeta_intervalo(Geral geral,char* dataA,char* dataB, char* outputstring)
{
    GList *rides = GetRides(geral);
    GList *viagens_entre_datas = NULL;
    char string[1000000];
    Ride aux;
    int dataA_dias = convert_to_days(dataA);
    int dataB_dias = convert_to_days(dataB);

    while(rides != NULL && convert_to_days(get_Ride_data((Ride)rides->data)) < dataA_dias)
    {
        rides = g_list_next(rides);
    }
    while(rides != NULL && convert_to_days(get_Ride_data((Ride)rides->data)) <= dataB_dias)
    {
        aux = (Ride)rides->data; 
        if(get_Ride_tip(aux) > 0)
        {
            viagens_entre_datas = g_list_prepend(viagens_entre_datas,aux);
        }    
        rides = g_list_next(rides);
    }

    viagens_entre_datas = g_list_sort(viagens_entre_datas,compara_viagnesDatas);  

    while (viagens_entre_datas != NULL) 
    {
        aux = (Ride)viagens_entre_datas->data;

        char *eptr;

        double tip;

        tip = strtod(get_Ride_tip(aux), &eptr);

        sprintf(string,"%012d;%s;%s;%s;%.3f\n",get_Ride_id(aux),get_Ride_data(aux),get_Ride_distance(aux),get_Ride_city(aux),tip);
        strcat(outputstring, string); 

        viagens_entre_datas = g_list_next(viagens_entre_datas);
    }

    g_list_free(viagens_entre_datas);
}