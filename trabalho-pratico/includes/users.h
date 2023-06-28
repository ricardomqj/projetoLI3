#ifndef users_h
#define users_h

typedef struct user *User;

User init_user();

void set_User_username(User user, char *username);

void set_User_name(User user, char *name);

void set_User_gender(User user, char *gender);

void set_User_birth_date(User user, char *birth_date);

void set_User_account_creation(User user, char *account_creation);

void set_User_pay_method(User user, char *pay_method);

void set_User_account_status(User user, char *account_status);

void set_User_totalgasto(User user, double totalgasto);

void set_User_distance(User user, int distance);

void set_User_viagens(User user, int viagens);

void set_User_avaliacao(User user, int avaliacao);

void set_User_last_ride(User user, int last_ride);

char* get_User_username(User user);

char* get_User_name(User user);

char get_User_gender(User user);

char* get_User_birth_date(User user);

char* get_User_account_creation(User user);

char get_User_account_status(User user);

double get_User_totalgasto(User user);

int get_User_distance(User user);

int get_User_viagens(User user);

int get_User_avaliacao(User user);

int get_User_last_ride(User user);

void update_last_ride_User(User user, char *data, char *aval);

void cleanUser(User user);

#endif