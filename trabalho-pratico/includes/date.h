#ifndef date_h
#define date_h

#include "structs.h"

typedef struct day * Day;

typedef struct viagensDatas * ViagensDatas;

int get_IntDay(Day d);

void set_IntDay(Day d, int n);

int get_IntMonth(Day d);

void set_IntMonth(Day d, int n);

int get_IntYear(Day d);

void set_IntYear(Day d, int n);

int get_NumViagensDay(Day d);

void set_NumViagensDay(Day d, int n);

int get_PrecoTotalDay(Day d);

void set_PrecoTotalDay(Day d, double price);

ViagensDatas getViagemDatas(Day d, int index);

ViagensDatas getViagemDatas(Day d, int index);

int getIdViagemViagensDatas(ViagensDatas v);

char *getCityViagensDatas(ViagensDatas v);

double getDistanceViagensDatas(ViagensDatas v);

double getTipViagensDatas(ViagensDatas v);

void initDayData(Day d);

void initMonthData(Day d);

void initYearData (Day d);

void initNumViagensData (Day d);

void initTotalPrecoData(Day d);

GPtrArray* createDates();

void print_struct_day(GPtrArray *days);

void acrescentaStructDay(GPtrArray *days, Driver driv, char *dataArg, char *distanceArg, int id_viagemArg, char *cityArg, char *tipArg);

Day lookupDay(GPtrArray *days, int indexDay);

void insertDay(GPtrArray *days, int indexDay, Day pointer);

int get_IntNViagensDate(Day d);

int sizeDay();

char* intDMYtoChar(int day, int month, int year);

int dayFromChar(char *data);

int monthFromChar(char *data);

int yearFromChar(char *data);

int convert_to_days(char *data);

#endif