#include "../includes/hash.h"
#include "../includes/querie4.h"
#include "../includes/queries.h"
#include "../includes/structs.h"
#include <stdio.h>

void conta_viagens_city(char *city, Geral geral)
{
	GHashTable *hashCity = GetHashCity(geral);

	City aux = lookupCity(hashCity, city);
	int aux_viagens = get_City_viagens(aux); 
	aux_viagens += 1;
	set_City_viagens(aux,aux_viagens);
	insertCity(GetHashCity(geral), aux);
}

void preco_total_city(Driver driv, char *distance, char *city, Geral geral)
{
	double price;
	char driver_carclass = get_Driver_carclass(driv);

	City aux = lookupCity(GetHashCity(geral), city);

	int dist = atoi(distance);

	if (driver_carclass == 'b')
	{
		price = 3.25 + (0.62 * dist);
	}
	if (driver_carclass == 'g')
	{
		price = 4.00 + (0.79 * dist);
	}
	if (driver_carclass == 'p')
	{
		price = 5.20 + (0.94 * dist);
	}
	double aux_preco = get_City_preco(aux); 
	aux_preco += price;
	set_City_preco(aux,aux_preco);
}

double preco_medio(City city)
{
	double precomed = ( get_City_preco(city) / get_City_viagens(city));
	return precomed;
}

void returnquerie4(double preco, char *linha, char *output)
{
	sprintf(output, "%.3f\n",preco);
}

void returnquery4_interactive(double preco, char *output) 
{
	sprintf(output, "%.3f\n",preco);
}