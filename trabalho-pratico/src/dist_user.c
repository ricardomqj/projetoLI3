#include "../includes/structs.h"

typedef struct dist_user
{
    char *username;
    char *name;
    int distance;
    int last_ride_days;
    
} Dist_User;

char *get_username_Dist_User_Fich(GArray *garray,int i)
{
    return strdup(g_array_index(garray, Dist_User,i).username);
}

char *get_name_Dist_User_Fich(GArray *garray,int i)
{
    Dist_User aux = g_array_index(garray, Dist_User,i);
    return strdup(aux.name);
}

int get_distance_Dist_User_Fich(GArray *garray, int i)
{
    Dist_User aux = g_array_index(garray,Dist_User,i);
    return aux.distance;
}

int get_lastride_Dist_User_Fich(GArray *garray, int i)
{
    Dist_User aux = g_array_index(garray,Dist_User,i);
    return aux.last_ride_days;
}

GArray *init_garray_Dist_User()
{
    return g_array_new(!TRUE, TRUE, sizeof(struct dist_user));
}

void insert_Dist_User_Array(char* username, char* name,int last_ride,int distance,int index, GArray *garray)
{  

    Dist_User user;
    user.username = username;
    user.name = name;
    user.last_ride_days = last_ride;
    user.distance = distance;

    g_array_insert_val(garray, index, user);
    index += 1;
}

int compare_Dist_User(gconstpointer a, gconstpointer b)
{
    const Dist_User *userA = a;
    const Dist_User *userB = b;

    if (userA->distance > userB->distance)
        return -1;
    if (userA->distance < userB->distance)
        return 1;
    else
    {
        if (userA->last_ride_days > userB->last_ride_days)
            return -1;
        if (userA->last_ride_days < userB->last_ride_days)
            return 1;
        else 
        {
            if ((strcmp(userA->username, userB->username)) > 0) 
                return -1;
            else
                return 1;    
        }        
    }        
}

int compare_users_dist(gconstpointer a, gconstpointer b)
{
    return compare_Dist_User(a,b);
}

User get_value_user(gpointer value)
{
    User aux = (User)value;
    return aux;
}

void top_User_Dist(GArray *garray, GHashTable *hashUsers)
{
    guint index = 0;

    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init(&iter, hashUsers);
    while (g_hash_table_iter_next(&iter, &key, &value))
    {
        User user = get_value_user(value);

        if (get_User_account_status(user) == 'a')
        {
             insert_Dist_User_Array(get_User_username(user),get_User_name(user),get_User_last_ride(user),get_User_distance(user),index, garray);
        }
    }
    g_array_sort(garray, compare_users_dist);
}