#ifndef dist_user_h
#define dist_user_h

char *get_username_Dist_User_Fich(GArray *garray,int i);

char *get_name_Dist_User_Fich(GArray *garray,int i);

int get_distance_Dist_User_Fich(GArray *garray, int i);

int get_lastride_Dist_User_Fich(GArray *garray, int i);

GArray *init_garray_Dist_User();

void insert_Dist_User_Array(char* username, char* name,int last_ride,int distance,int index, GArray *garray);

int compare_Dist_User(gconstpointer a, gconstpointer b);

User get_value_user(gpointer value);

void top_User_Dist(GArray *garray, GHashTable *hashUsers);

#endif