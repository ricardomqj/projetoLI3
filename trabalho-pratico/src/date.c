#include "../includes/date.h"
#include "../includes/structs.h"
#include <stdio.h>

typedef struct day {
    int day;
    int month;
    int year;
    int num_viagens;
    double total_preco;
    GPtrArray * listaViagens;
} day;

typedef struct viagensDatas {
    int id_viagem;
    char *city;
    double distance_Ride;
    double tip;
} viagensDatas;

int get_IntDay(Day d) {
    return d->day;
}

void set_IntDay(Day d, int n) {
    d->day = n;
}

int get_IntMonth(Day d) {
    return d->month;
}

void set_IntMonth(Day d, int n) {
    d->month = n;
}

int get_IntYear(Day d) {
    return d->year;
}

void set_IntYear(Day d, int n) {
    d->year = n;
}

int get_NumViagensDay(Day d) {
    return d->num_viagens;
}

void set_NumViagensDay(Day d, int n) {
    d->num_viagens = n;
}

int get_PrecoTotalDay(Day d) {
    return d->total_preco;
}

void set_PrecoTotalDay(Day d, double price) {
    d->total_preco = price;
} 

ViagensDatas getViagemDatas(Day d, int index) {
    return g_ptr_array_index(d->listaViagens, index);
}

void set_GptrArrayViagensDatas(Day d, ViagensDatas v) {
    g_ptr_array_add(d->listaViagens, v);
}

int getIdViagemViagensDatas(ViagensDatas v) {
    return v->id_viagem;
}

char *getCityViagensDatas(ViagensDatas v) {
    return strdup(v->city);
}

double getDistanceViagensDatas(ViagensDatas v) {
    return v->distance_Ride;
}

double getTipViagensDatas(ViagensDatas v) {
    return v->tip;
}
void initDayData(Day d) {
    d->day = 0;
}

void initMonthData(Day d) {
    d->month = 0;
}

void initYearData (Day d){
    d->year = 0;
}

void initNumViagensData (Day d) {
    d->num_viagens = 0;
}

void initTotalPrecoData(Day d) {
    d->total_preco = 0.0;
}

GPtrArray* createDates() {
    GPtrArray *dates = g_ptr_array_sized_new(8765); // dias desde 01/01/2000 até 31/12/2023
    g_ptr_array_set_size(dates, 8765); 

    GDate * actualDate = g_date_new_dmy(1,1,2000);
    int day, month, year;

    for(int i = 0; i<8765; i++) {
        Day pointerDay = malloc(sizeDay()); // alocar memoria para 1 dia

        initNumViagensData(pointerDay); // inicializa num_viagens
        initTotalPrecoData(pointerDay); // inicializa total_preco

        pointerDay->listaViagens = g_ptr_array_new(); //inicializa o GPtrArray listaViagens
        
        day = g_date_get_day(actualDate); 
        month = g_date_get_month(actualDate);
        year = g_date_get_year(actualDate);

        set_IntDay(pointerDay, day);
        set_IntMonth(pointerDay, month);
        set_IntYear(pointerDay, year);

        g_ptr_array_insert(dates, i, pointerDay);
        
        g_date_add_days(actualDate, 1); 
    }
    g_date_free(actualDate);

    return dates;
}

void print_struct_day(GPtrArray *days) {
    GDate * dataMinima = g_date_new_dmy(1,1,2000);
    GDate * beginDate = g_date_new_dmy(1,2,2021);
    GDate * endDate = g_date_new_dmy(1,3,2021);
    //int initIndex = g_date_days_between(dataMinima,beginDate);
    //int endIndex = g_date_days_between(dataMinima,endDate);

    for (int i = 0; i<8765; i++) {
        Day current = g_ptr_array_index(days, i);
        if(current->num_viagens!=0) {
            printf("%02d/%02d/%04d -> [num_viagens:%d][total_preco:%.3f]\n", current->day, current->month, current->year, current->num_viagens, current->total_preco);
            for(int j = 0; j<current->num_viagens; j++) {
                ViagensDatas v = g_ptr_array_index(current->listaViagens, j);
                printf("    [id_viagem:%d][city:%s][distance:%.03f][tip:%f]\n", v->id_viagem, v->city, v->distance_Ride,v->tip);
            }
        //break;
        }
    }

    g_date_free(dataMinima);
    g_date_free(beginDate);
    g_date_free(endDate);
}

void acrescentaStructDay(GPtrArray *days, Driver driv, char *dataArg, char *distanceArg, int id_viagemArg, char *cityArg, char *tipArg) {
    GDate * dataMinima = g_date_new_dmy(1,1,2000);
    GDate * data = g_date_new_dmy(dayFromChar(dataArg),monthFromChar(dataArg),yearFromChar(dataArg));
    int index = g_date_days_between(dataMinima, data); 
    int dist = atoi(distanceArg);
    char driver_carclass = get_Driver_carclass(driv);
    double tip = atof(tipArg);
    double price = 0.0;

    if (driver_carclass == 'b'){
        price = 3.25 + (0.62 * dist);
    }
    if (driver_carclass == 'g'){
        price = 4.00 + (0.79 * dist);
    }
    if (driver_carclass == 'p'){
        price = 5.20 + (0.94 * dist);
    }

    ViagensDatas v = malloc(sizeof(viagensDatas));
    v->id_viagem = id_viagemArg;
    v->city = cityArg;
    v->distance_Ride = dist;
    v->tip = tip;
    
    Day dia = lookupDay(days,index);
    dia->num_viagens++;
    dia->total_preco += price;
    g_ptr_array_add(dia->listaViagens, v);

    g_date_free(dataMinima);
    g_date_free(data);
}

Day lookupDay(GPtrArray *days, int indexDay) {
    Day d = g_ptr_array_index(days, indexDay);
    return d;
}

void insertDay(GPtrArray *days, int indexDay, Day pointer) {
    g_ptr_array_insert(days, indexDay, pointer);
}

int get_IntNViagensDate(Day d) {
    return d->num_viagens;
}


// Funcao que devolve o tamanho da estrutura Day
int sizeDay() {
    return sizeof(struct day);
}

char* intDMYtoChar(int day, int month, int year) {
    static char date[11];
    sprintf(date, "%02d/%02d/%04d", day, month, year);
    return date;
}

int dayFromChar (char *data) {
    char resto[BUFSIZ];
    int d, m, y;
    sscanf(data, "%02d/%02d/%04d%s", &d, &m, &y, resto);
    return d;
}

int monthFromChar (char *data) {
    char resto[BUFSIZ];
    int d, m, y;
    sscanf(data, "%02d/%02d/%04d%s", &d, &m, &y, resto);
    return m;
}

int yearFromChar (char *data) {
    char resto[BUFSIZ];
    int d, m, y;
    sscanf(data, "%02d/%02d/%04d%s", &d, &m, &y, resto);
    return y;
}

int convert_to_days(char *data) {
    if(data[0] < '0' || data[0] > '9') return 0;

    int r = 0, d, m, a;
    sscanf(data, "%d/%d/%d", &d, &m, &a);

    r = d + a*365;

    for (int i = 1; i < m; i++) 
        switch (i) {
            case 1:
                r = r + 31;
                break;
            case 2:
                r = r + 28;
                break;
            case 3:
                r = r + 31;
                break;
            case 4:
                r = r + 30;
                break;
            case 5:
                r = r + 31;
                break;
            case 6:
                r = r + 30;
                break;
            case 7:
                r = r + 31;
                break;
            case 8:
                r = r + 31;
                break;
            case 9:
                r = r + 30;
                break;
            case 10:
                r = r + 31;
                break;
            case 11:
                r = r + 30;
                break;
            case 12:
                r = r + 31;
                break;
            
        }
    
    return r;

}
