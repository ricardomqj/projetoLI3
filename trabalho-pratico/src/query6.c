#include "../includes/query6.h"
#include "../includes/querie4.h"
#include "../includes/query5.h"
#include "../includes/queries.h"

int conta_viagens_2datas_city (GPtrArray *days, char *dataA, char *dataB, char *cityArg){
    int n_viagens = 0;
    int n_days, count_day;
    int perc_day = 0;

    GDate * dataMinima = g_date_new_dmy(1,1,2000);
    GDate * beginDate = g_date_new_dmy(dayFromChar(dataA),monthFromChar(dataA),yearFromChar(dataA));
    GDate * endDate = g_date_new_dmy(dayFromChar(dataB),monthFromChar(dataB),yearFromChar(dataB));

    n_days = g_date_days_between(beginDate, endDate);
    count_day = g_date_days_between(dataMinima, beginDate);

    while(n_days>=0) {
        Day d = lookupDay(days,count_day);
        while(perc_day<get_NumViagensDay(d)) {
            // colocar em lista de viagens a lista de viagens do Day d
            ViagensDatas v = getViagemDatas(d,perc_day);
            if(strcmp(getCityViagensDatas(v),cityArg)==0)
                n_viagens++;
            perc_day++;
        }
        perc_day=0;

        count_day++;
        n_days--;
    }

    g_date_free(dataMinima);
    g_date_free(beginDate);
    g_date_free(endDate);

    return n_viagens;
} 

double conta_distanciaTotal_2datas_city(GPtrArray *days, char *dataA, char *dataB, char *cityArg) {
    double counter = 0.0;
    int n_days, count_day;
    int perc_day = 0;

    GDate * dataMinima = g_date_new_dmy(1,1,2000);
    GDate * beginDate = g_date_new_dmy(dayFromChar(dataA),monthFromChar(dataA),yearFromChar(dataA));
    GDate * endDate = g_date_new_dmy(dayFromChar(dataB),monthFromChar(dataB),yearFromChar(dataB));
    
    n_days = g_date_days_between(beginDate, endDate);
    count_day = g_date_days_between(dataMinima, beginDate);

    while (n_days>=0) {
        Day d = lookupDay(days,count_day);
        while(perc_day<get_NumViagensDay(d)) {
            ViagensDatas v = getViagemDatas(d, perc_day);
            if(strcmp(getCityViagensDatas(v),cityArg)==0) 
                counter+=getDistanceViagensDatas(v);
            perc_day++;
        }
        perc_day=0;

        count_day++;
        n_days--;
    }

    g_date_free(dataMinima);
    g_date_free(beginDate);
    g_date_free(endDate);

    return counter;
}

double distMedia_2datas_city(GPtrArray *days, char *dataA, char *dataB, char *cityArg) {
    double dm = conta_distanciaTotal_2datas_city(days,dataA,dataB,cityArg)/conta_viagens_2datas_city(days,dataA,dataB,cityArg);
    return dm;
}

void returnquerie6(double dist, char *linha, char *output)
{
    sprintf(output, "%.3f\n",dist);
}

void returnquerie6_interactive(double dist, char *output) 
{
    sprintf(output, "%.3f\n",dist);
}