#include <stdio.h>

#include "../includes/query1.h"

#define datahoje "09/10/2022"

int is_user_or_driver(char* iden, Geral geral)
{
	GHashTable *hashDrivers = GetHashDrivers(geral);
	GHashTable *hashUsers = GetHashUsers(geral);

	if ((lookupUser(hashUsers, iden) != NULL)) return 0;

	if ((lookupDriver(hashDrivers, iden) != NULL)) return 1;
	
	return -1;
}	

void conta_viagens_user(char *username, Geral geral)
{
	GHashTable *hashUsers = GetHashUsers(geral);
    User aux = lookupUser(hashUsers, username);
    int aux_viagens = get_User_viagens(aux); 
	aux_viagens += 1;
	set_User_viagens(aux,aux_viagens);
	insertUser(hashUsers, aux);
}

void conta_avaliacoes_user(char *username, char *score_user, Geral geral)
{
	GHashTable *hashUsers = GetHashUsers(geral);
    User aux = lookupUser(hashUsers, username);
    int score = atoi(score_user);
    int aux_avaliacao = get_User_avaliacao(aux); 
	aux_avaliacao += score;
	set_User_avaliacao(aux,aux_avaliacao);
}

double avaliacao_med_user(User user)
{
    return ((double) get_User_avaliacao(user) / get_User_viagens(user));
}

void preco_total_driver(Driver driver, char *distance, char* idDriv, char* tip, Geral geral)
{
	GHashTable *hashDrivers = GetHashDrivers(geral);
	char driver_carclass = get_Driver_carclass(driver);

	double price;
	Driver aux = lookupDriver(hashDrivers, idDriv);

	int dist = atoi(distance);

	if (driver_carclass == 'b')
	{
		price = 3.25 + (0.62 * dist) + atof(tip);
	}
	if (driver_carclass == 'g')
	{
		price = 4.00 + (0.79 * dist) + atof(tip);
	}
	if (driver_carclass == 'p')
	{
		price = 5.20 + (0.94 * dist) + atof(tip);
	}
	double total_gasto_Aux = get_Driver_totalgasto(aux); 
	total_gasto_Aux += price;
	set_Driver_totalgasto (aux,total_gasto_Aux);
}

int idade_user(char* username, Geral geral)
{
	GHashTable *hashUsers = GetHashUsers(geral);
	char *user_birthdate = get_User_birth_date(lookupUser(hashUsers, username));

	int birthdate = convert_to_days(user_birthdate);
	int todaysdate = convert_to_days(datahoje);

	free(user_birthdate);
	return ((todaysdate - birthdate) / 365.25);
}

int idade_driver(char* id, Geral geral)
{
	GHashTable *hashDrivers = GetHashDrivers(geral);
	char *driver_birthdate = get_Driver_bith_date(lookupDriver(hashDrivers, id));

	int birthdate = convert_to_days(driver_birthdate);
	int todaysdate = convert_to_days(datahoje);

	free(driver_birthdate);
	return ((todaysdate - birthdate) / 365);
}

void preco_total_user(Driver driver, char *distance, char* user, char* tip, Geral geral)
{
	double price;
	char driver_carclass = get_Driver_carclass(driver);

	User aux = lookupUser(GetHashUsers(geral), user);

	int dist = atoi(distance);

	if (driver_carclass == 'b')
	{
		price = 3.25 + (0.62 * dist) + atof(tip);
	}
	if (driver_carclass == 'g')
	{
		price = 4.00 + (0.79 * dist) + atof(tip);
	}
	if (driver_carclass == 'p')
	{
		price = 5.20 + (0.94 * dist) + atof(tip);
	}
	double aux_totalgasto = get_User_totalgasto(aux); 
	aux_totalgasto += price;
	set_User_totalgasto(aux,aux_totalgasto);
}

void define_output(Geral geral, char* iden, char* linha, char *output)
{	
	GHashTable *hashDrivers = GetHashDrivers(geral);
	GHashTable *hashUsers = GetHashUsers(geral);

	/*
	if(get_Driver_account_status(lookupDriver(hashDrivers, iden)) != 'a' && get_User_account_status(lookupUser(hashUsers, iden)) != 'a'){
		strcpy(output, "");
		return;
	}
	*/

	char fullstring[502] = {0};

	if (is_user_or_driver(iden, geral) == 0) // USER
	{
		if(get_User_account_status(lookupUser(hashUsers, iden)) != 'a'){
			strcpy(output,"");
			return;
		}

		strcpy(fullstring, "");

		sprintf(fullstring, "%s;%c;%d;%.3f;%d;%.3f\n",get_User_name(lookupUser(hashUsers, iden)),get_User_gender(lookupUser(hashUsers, iden)),idade_user(iden, geral),avaliacao_med_user(lookupUser(hashUsers, iden)),get_User_viagens(lookupUser(hashUsers, iden)),get_User_totalgasto(lookupUser(hashUsers, iden)));

		strcpy(output, fullstring);

	}
	if (is_user_or_driver(iden, geral) == 1) // DRIVER
	{
		
		if(get_Driver_account_status(lookupDriver(hashDrivers, iden)) != 'a'){
			strcpy(output,"");
			return;
		}
		
		strcpy(fullstring, "");

		sprintf(fullstring, "%s;%c;%d;%.3f;%d;%.3f\n",get_Driver_name(lookupDriver(hashDrivers, iden)),get_Driver_gender(lookupDriver(hashDrivers, iden)),idade_driver(iden,geral),avaliacao_med_driver(lookupDriver(hashDrivers, iden)),get_Driver_viagens(lookupDriver(hashDrivers, iden)),get_Driver_totalgasto(lookupDriver(hashDrivers, iden)));

		strcpy(output, fullstring);
	}
	if (is_user_or_driver(iden, geral) == -1) // NOTHING
	{
		//criaficheiro(linha, "");
	}
}

void define_output_interactive(Geral geral, char* iden,char *output)
{
	char fullstring[502] = {0};

	GHashTable *hashDrivers = GetHashDrivers(geral);
	GHashTable *hashUsers = GetHashUsers(geral);

	if (is_user_or_driver(iden, geral) == 0) // USER
	{
		if(get_User_account_status(lookupUser(hashUsers, iden)) != 'a'){
			strcpy(output,"");
			return;
		}

		strcpy(fullstring, "");

		sprintf(fullstring, "%s;%c;%d;%.3f;%d;%.3f\n",get_User_name(lookupUser(hashUsers, iden)),get_User_gender(lookupUser(hashUsers, iden)),idade_user(iden, geral),avaliacao_med_user(lookupUser(hashUsers, iden)),get_User_viagens(lookupUser(hashUsers, iden)),get_User_totalgasto(lookupUser(hashUsers, iden)));

		strcpy(output, fullstring);

	}
	if (is_user_or_driver(iden, geral) == 1) // DRIVER
	{
		
		if(get_Driver_account_status(lookupDriver(hashDrivers, iden)) != 'a'){
			strcpy(output,"");
			return;
		}
		
		strcpy(fullstring, "");

		sprintf(fullstring, "%s;%c;%d;%.3f;%d;%.3f\n",get_Driver_name(lookupDriver(hashDrivers, iden)),get_Driver_gender(lookupDriver(hashDrivers, iden)),idade_driver(iden,geral),avaliacao_med_driver(lookupDriver(hashDrivers, iden)),get_Driver_viagens(lookupDriver(hashDrivers, iden)),get_Driver_totalgasto(lookupDriver(hashDrivers, iden)));

		strcpy(output, fullstring);
	}
	/*
	if (is_user_or_driver(iden, geral) == -1) // NOTHING
	{
		char ret[20] = "ID inválido\n";
		strcpy(output,ret);
	}
	*/
}