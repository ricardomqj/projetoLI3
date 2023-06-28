#include "../includes/structs.h"

struct user
{
    char *username;
    char *name;
    char gender;
    char *birth_date;
    char *account_creation;
    char account_status;
    double totalgasto;
    int distance;
    int viagens;
    int avaliacao;
    int last_ride;
};

User init_user()
{
    User user = malloc(sizeof(struct user));
    
    user->username = NULL;
    user->name = NULL;
    user->gender = '\0';
    user->birth_date = NULL;
    user->account_creation = NULL;
    user->account_status = '\0'; 

    user->totalgasto = 0;
    user->distance = 0;
    user->viagens = 0;
    user->avaliacao = 0;
    user->last_ride = 0;

    return user;
}

// setters 

void set_User_username(User user, char *username)
{
    user->username = username;
}

void set_User_name(User user, char *name)
{
    user->name = name;
}

void set_User_gender(User user, char *gender)
{
    user->gender = gender[0];
}

void set_User_birth_date(User user, char *birth_date)
{
    user->birth_date = birth_date;
}

void set_User_account_creation(User user, char *account_creation)
{
    user->account_creation = account_creation;
}

/*
void set_User_pay_method(User user, char *pay_method)
{
    user->pay_method = pay_method;
}
*/

void set_User_account_status(User user, char *account_status)
{
    user->account_status = account_status[0];
}

void set_User_totalgasto(User user, double totalgasto)
{
    user->totalgasto = totalgasto;
}

void set_User_distance(User user, int distance)
{
    user->distance = distance;
}

void set_User_viagens(User user, int viagens)
{
    user->viagens = viagens;
}

void set_User_avaliacao(User user, int avaliacao)
{
    user->avaliacao = avaliacao;
}

void set_User_last_ride(User user, int last_ride)
{
    user->last_ride = last_ride;
}

// getters

char* get_User_username(User user)
{
    return strdup(user->username);
}

char* get_User_name(User user)
{
    return strdup(user->name);
}

char get_User_gender(User user)
{
    return user->gender;
}

char* get_User_birth_date(User user)
{
    return strdup(user->birth_date);
}

char* get_User_account_creation(User user)
{
    return strdup(user->account_creation);
}

/*
char* get_User_pay_method(User user)
{
    return strdup(user->pay_method);
}
*/

char get_User_account_status(User user)
{
    return user->account_status;
}

double get_User_totalgasto(User user)
{
    return user->totalgasto;
}

int get_User_distance(User user)
{
    return user->distance;
}

int get_User_viagens(User user)
{
    return user->viagens;
}

int get_User_avaliacao(User user)
{
    return user->avaliacao;
}

int get_User_last_ride(User user)
{
    return user->last_ride;
}

void update_last_ride_User(User user, char *data, char *aval)
{
    int days_data = convert_to_days(data);

    if (days_data < user->last_ride)
    {
        user->last_ride = days_data;
    }
}

void cleanUser(User user)
{
    free(user->username);

    free(user);
}