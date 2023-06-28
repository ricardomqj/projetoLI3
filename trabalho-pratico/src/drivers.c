#include "../includes/structs.h"

struct driver
{
    char *id;
    char *name;
    char *birth_date;
    char *account_creation;
    double totalgasto;
    int viagens;
    int avaliacao;
    int last_ride;
    char gender;
    char carclass;
    char account_status;
};

Driver init_driver()
{
    Driver driv = malloc(sizeof(struct driver));

    driv->id = NULL;
    driv->name = NULL;
    driv->birth_date = NULL;
    driv->gender = '\0';
    driv->carclass = '\0';
    driv->account_creation = NULL;
    driv->account_status = '\0';

    driv->totalgasto = 0;
    driv->viagens = 0;
    driv->avaliacao = 0;
    driv->last_ride = 0;

    return driv;
}

// setters

void set_Driver_id(Driver driv, char *id)
{
    driv->id = id;
}

void set_Driver_name(Driver driv,char *name)
{
    driv->name = name;
}

void set_Driver_bith_date(Driver driv,char *birth_date)
{
    driv->birth_date = birth_date;
}

void set_Driver_gender(Driver driv,char *gender)
{
    driv->gender = gender[0];
}

void set_Driver_carclass(Driver driv,char *carclass)
{
    driv->carclass = carclass[0];
}

void set_Driver_account_creation(Driver driv,char *account_creation)
{
    driv->account_creation = account_creation;
}

void set_Driver_account_status(Driver driv,char *account_status)
{
    driv->account_status = account_status[0];
}

void set_Driver_totalgasto(Driver driv,double totalgasto)
{
    driv->totalgasto = totalgasto;
}

void set_Driver_viagens(Driver driv,int viagens)
{
    driv->viagens = viagens;
}

void set_Driver_avaliacao(Driver driv,int avaliacao)
{
    driv->avaliacao = avaliacao;
}

void set_Driver_last_ride(Driver driv,int last_ride)
{
    driv->last_ride = last_ride;
}

// getters 

char* get_Driver_id(Driver driv)
{
    return strdup(driv->id);
}

char* get_Driver_name(Driver driv)
{
    return strdup(driv->name);
}

char* get_Driver_bith_date(Driver driv)
{
    return strdup(driv->birth_date);
}

char get_Driver_gender(Driver driv)
{
    return driv->gender;
}

char get_Driver_carclass(Driver driv)
{
    return driv->carclass;
}

char* get_Driver_account_creation(Driver driv)
{
    return strdup(driv->account_creation);
}

char get_Driver_account_status(Driver driv)
{
    return driv->account_status;
}

double get_Driver_totalgasto(Driver driv)
{
    return driv->totalgasto;
}

int get_Driver_viagens(Driver driv)
{
    return driv->viagens;
}

int get_Driver_avaliacao(Driver driv)
{
    return driv->avaliacao;
}

int get_Driver_last_ride(Driver driv)
{
    return driv->last_ride;
}

void update_last_ride_Driv(Driver driv, char *data, char *aval)
{
    int days_data = convert_to_days(data);

    if (days_data < get_Driver_last_ride(driv))
    {
        set_Driver_last_ride(driv, days_data);
    }
}

void cleanDriver(Driver driv)
{
    free(driv->id);

    free(driv);
}