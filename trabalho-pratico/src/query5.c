#include "../includes/hash.h"
#include "../includes/querie4.h"
#include "../includes/queries.h"
#include "../includes/structs.h"
#include "../includes/date.h"
#include <stdio.h>

int conta_viagens_2datas (GPtrArray *days, char *dataA, char *dataB) {
    int n_viagens = 0;
    int n_days, count_day;

    GDate *dataMinima = g_date_new_dmy(1, 1, 2000); //g_date para "01/01/0001" que é o primeiro dia do pointerArray Day
    GDate *beginDate = g_date_new_dmy(dayFromChar(dataA), monthFromChar(dataA), yearFromChar(dataA));
    GDate *endDate = g_date_new_dmy(dayFromChar(dataB), monthFromChar(dataB), yearFromChar(dataB));

    n_days = g_date_days_between(beginDate, endDate); // numero de dias entre dataA e dataB
    count_day = g_date_days_between(dataMinima, beginDate); // numero de dias entre data minima e dataA(index data A)

    while(n_days>=0) {
        n_viagens += get_NumViagensDay(lookupDay(days, count_day)); // lookupDay(geral, index) devolve um dia do array de dias *Day
        count_day++;
        n_days--;
    }

    g_date_free(dataMinima);
    g_date_free(beginDate);
    g_date_free(endDate);

    return n_viagens;
}


double conta_preco_total(GPtrArray *days, char *dataA, char *dataB){
    double preco_count = 0.0;
    int n_days, count_day;

    GDate *dataMinima = g_date_new_dmy(1, 1, 2000);
    GDate *beginDate = g_date_new_dmy(dayFromChar(dataA), monthFromChar(dataA), yearFromChar(dataA));
    GDate *endDate = g_date_new_dmy(dayFromChar(dataB), monthFromChar(dataB), yearFromChar(dataB));

    n_days = g_date_days_between(beginDate, endDate); // num de dias entre dataA e dataB
    count_day = g_date_days_between(dataMinima, beginDate); //numero de dias entre data minima e data A

    while(n_days>=0) {
        preco_count += get_PrecoTotalDay(lookupDay(days, count_day));
        count_day++;
        n_days--;
    }

    g_date_free(dataMinima);
    g_date_free(beginDate);
    g_date_free(endDate);

    return preco_count;
}

double precoMed_2datas(GPtrArray *days, char *dataA, char *dataB) {
    return (conta_preco_total(days, dataA, dataB)/conta_viagens_2datas(days, dataA, dataB));
}

void returnquerie5(double preco, char *linha, char *output)
{
    sprintf(output, "%.3f\n",preco);
}

void returnquerie5_interactive(double preco, char *output)
{
    sprintf(output, "%.3f\n",preco);
}