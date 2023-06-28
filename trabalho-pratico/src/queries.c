#include "../includes/queries.h"
#include "../includes/structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_query_info(char *path, int n, char *str1, char *str2, char *str3, char *str4)
{
	FILE *txt = fopen(path, "r");

	char line[1024] = {0};

	char query_number[4] = {0};

	char q_info1[15] = {0};

	char q_info2[15] = {0};

	char q_info3[15] = {0};

	char q_info4[15] = {0};

	int qnum = 0;

	int linha = 1;

	while (fgets(line, 1024, txt))
	{
		if (linha == n)
		{
			sscanf(line, "%s%s%s%s%s", query_number, q_info1, q_info2, q_info3, q_info4);

			qnum = atoi(query_number);

			strcpy(str1, q_info1);

			strcpy(str2, q_info2);

			strcpy(str3, q_info3);

			strcpy(str4, q_info4);

			return qnum;
		}
		else
			linha++;
	}

	return -1;
}

double timer(double start, double end) {

	return ((end - start) / CLOCKS_PER_SEC);
}

void percorre_comandos(char *path, char *pathsol, int verifytests, Geral geral)
{
	clock_t start, end;

	//double time[9] = {0};

	char str1[BUFSIZ];
    char str2[BUFSIZ];
    char str3[BUFSIZ];
    char str4[BUFSIZ];

    int valid = 0;

    char pathres[BUFSIZ];

    char pathlocal[BUFSIZ];

    char pathcoms[BUFSIZ];

	char outputstring[1000000];

	char commandsol[BUFSIZ];

	char pathlocalsol[BUFSIZ];

	strcpy(pathcoms, path);

	FILE *txt = fopen(path, "r");

	char line[1024];

	char linha[BUFSIZ] = "1";
	int intlinha = 1;

	while (fgets(line, 1024, txt))
	{
		int qnum = read_query_info(path, atoi(linha),str1, str2, str3, str4);

		switch (qnum)
		{

		case 1: ;

			strcpy(pathlocalsol, pathsol);

			start = clock();

			define_output(geral, str1, linha, outputstring);

			end = clock();

			criaficheiro(linha, outputstring, pathres, commandsol);

			strcpy(pathlocal, pathres);

			strcpy(outputstring,"");

			if(verifytests == 1) {

				valid = compareFiles(pathlocal, pathlocalsol, commandsol);

				printTime(timer(start,end), qnum, valid);
			}

			strcpy(commandsol, "");

			strcpy(pathlocalsol,"");

			strcpy(pathlocal,"");

			break;	
		
		case 2: ;

			strcpy(pathlocalsol, pathsol);

			start = clock();

			get_top_N_Drivers(geral, atoi(str1), linha, outputstring);

			end = clock();

			criaficheiro(linha, outputstring, pathres, commandsol);

			strcpy(pathlocal, pathres);

			strcpy(outputstring,"");

			
			if(verifytests == 1) {
				valid = compareFiles(pathlocal, pathlocalsol, commandsol);
				printTime(timer(start,end), qnum, valid);
			}
			
			strcpy(commandsol, "");

			strcpy(pathlocalsol,"");

			strcpy(pathlocal,"");

			break;

		case 3: ;

			strcpy(pathlocalsol, pathsol);

			start = clock();

			Get_Top_User_Dist(geral, atoi(str1), linha, outputstring);

			end = clock();

			criaficheiro(linha, outputstring, pathres, commandsol);

			strcpy(pathlocal, pathres);

			strcpy(outputstring,"");


			if(verifytests == 1) {
				valid = compareFiles(pathlocal, pathlocalsol, commandsol);
				printTime(timer(start,end), qnum, valid);
			}

			strcpy(commandsol, "");

			strcpy(pathlocalsol,"");

			strcpy(pathlocal,"");

			break;

		case 4:	;

			strcpy(pathlocalsol, pathsol);

			start = clock();

			City aux = lookupCity(GetHashCity(geral), str1); 
			if ((aux == NULL) || (get_City_viagens(aux) == 0))
			{
				free(aux);

				criaficheiro(linha,"", pathres, commandsol);
				
				strcpy(pathlocal, pathres);

			}
			else
			{
				double city_preco_medio = preco_medio(aux);
				free(aux);

				returnquerie4(city_preco_medio, linha, outputstring);
				criaficheiro(linha, outputstring, pathres, commandsol);

				strcpy(pathlocal, pathres);

				strcpy(outputstring,"");
			}

			end = clock();
			
			if(verifytests == 1) {
				valid = compareFiles(pathlocal, pathlocalsol, commandsol);
				printTime(timer(start,end), qnum, valid);
			}
			
			strcpy(commandsol, "");

			strcpy(pathlocalsol,"");

			strcpy(pathlocal,"");

			break;

		case 5: ;

			strcpy(pathlocalsol, pathsol);

			start = clock();

			double aux2 = precoMed_2datas(GetPtrArrayDay(geral), str1, str2);

			if ((aux2 == 0) || conta_viagens_2datas(GetPtrArrayDay(geral), str1, str2) == 0)
			{
				criaficheiro(linha,"", pathres, commandsol);

				strcpy(pathlocal, pathres);
			}
			else
			{
				returnquerie5(aux2, linha, outputstring);
				criaficheiro(linha, outputstring, pathres, commandsol);

				strcpy(pathlocal, pathres);

				strcpy(outputstring,"");
			}

			end = clock();
			
			if(verifytests == 1) {
				valid = compareFiles(pathlocal, pathlocalsol, commandsol);
				printTime(timer(start,end), qnum, valid);
			}
			
			strcpy(commandsol, "");

			strcpy(pathlocalsol,"");

			strcpy(pathlocal,"");

			break;

		case 6: ;

			strcpy(pathlocalsol, pathsol);

			start = clock();

			double aux3 = distMedia_2datas_city(GetPtrArrayDay(geral), str2, str3, str1);

			if ((aux3 == 0) || conta_viagens_2datas_city(GetPtrArrayDay(geral), str2, str3, str1) == 0)
			{
				criaficheiro(linha,"", pathres, commandsol);

				strcpy(pathlocal, pathres);

			}
			else
			{	
				returnquerie6(aux3, linha, outputstring);
				criaficheiro(linha, outputstring, pathres, commandsol);

				strcpy(pathlocal, pathres);

				strcpy(outputstring,"");
			}

			end = clock();
			
			if(verifytests == 1) {
				valid = compareFiles(pathlocal, pathlocalsol, commandsol);
				printTime(timer(start,end), qnum, valid);
			}
			
			strcpy(commandsol, "");

			strcpy(pathlocalsol,"");

			strcpy(pathlocal,"");

			break;

		case 7: ;

			strcpy(pathlocalsol, pathsol);

			start = clock();

			criaficheiro(linha, "case 7", pathres, commandsol);

			end = clock();

			strcpy(pathlocal, pathres);

			strcpy(outputstring,"");
			
			if(verifytests == 1) {
				valid = compareFiles(pathlocal, pathlocalsol, commandsol);
				printTime(timer(start,end), qnum, valid);
			}

			strcpy(commandsol, "");

			strcpy(pathlocalsol,"");

			strcpy(pathlocal,"");

			break;

		case 8: ;

			strcpy(pathlocalsol, pathsol);

			start = clock();

			filter_rides_gender_acc(geral,str1,str2,outputstring);

			end = clock();

			criaficheiro(linha, outputstring, pathres, commandsol);

			strcpy(pathlocal, pathres);

			strcpy(outputstring,"");

			if(verifytests == 1) {
				valid = compareFiles(pathlocal, pathlocalsol, commandsol);
				printTime(timer(start,end), qnum, valid);
			}

			strcpy(commandsol, "");

			strcpy(pathlocalsol,"");

			strcpy(pathlocal,"");

			break;

		case 9: ;

			strcpy(pathlocalsol, pathsol);

			start = clock();

			make_Glista_grojeta_intervalo(geral,str1 ,str2,outputstring);

			end = clock();
			
			criaficheiro(linha, outputstring, pathres, commandsol);

			strcpy(pathlocal, pathres);

			strcpy(outputstring,"");
			
			if(verifytests == 1) {
				valid = compareFiles(pathlocal, pathlocalsol, commandsol);
				printTime(timer(start,end), qnum, valid);
			}

			strcpy(commandsol, "");

			strcpy(pathlocalsol,"");

			strcpy(pathlocal,"");

			break;
		}

		intlinha++;
		sprintf(linha, "%d", intlinha);
	}
}

int compareFiles(char *pathres, char *pathsol, char *commandsoll) {

  	char c1, c2;

  	printf("      ---COMPARE FILES---\n");

   	strcat(pathsol,commandsoll);

   	printf("pathres: %s\n",pathres);

   	printf("pathsol: %s\n\n", pathsol);

	FILE *f1 = fopen(pathres, "r");

  	FILE *f2 = fopen(pathsol, "r");

  	int result = 1;

  	while (!feof(f1) && !feof(f2)) {

  		c1 = getc(f1);
    	c2 = getc(f2);
    	
    	if (c1 != c2) {

    		printf("The error is on the characters:\n ./Resultados: %c  ./sols: %c\n",c1,c2);

    		result = 0;
    		break;
    	}
  	
  	}

  	if(feof(f1) != feof(f2)) result = 0;

  	strcpy(pathsol, "");

  	fclose(f1);
  	fclose(f2);

  	return result;
}

void printTime(double time, int query, int valid) {

	char* useful;
	char* validstr;

	if (valid == 1) validstr = "YES";
	else validstr = "NO ";

	if (time > 10) useful = "NO ";
	else useful = "YES";

	printf("   ________________________ \n");
	printf("  |                        |\n");
	printf("  |    ---Query-%d---       |\n", query);
	printf("  |                        |\n");
	printf("  | Time -> %6f       |\n", time);
	printf("  | Useful Runtime -> %s  |\n", useful);
	printf("  | Valid Output  -> %s   |\n", validstr);
	printf("  |________________________|\n\n");



}

void criaficheiro(char *linha, char *fullstr, char *pathres, char *commandx)
{
	char fullcom[BUFSIZ];
	char *dirresul = "./Resultados";
	char *middlepart = "/command";
	char *finalpart = "_output.txt";

	sprintf(fullcom, "%s%s%s%s",dirresul,middlepart,linha,finalpart);

	sprintf(commandx, "%s%s%s",middlepart,linha,finalpart);

	strcpy(pathres, fullcom);

	FILE *outputtxt = fopen(fullcom, "w");

	fprintf(outputtxt, "%s", fullstr);

	fclose(outputtxt);
}

void criaficheirodouble(char *linha, char *fullstr, char *pathres, char *commandx)
{
	char fullcom[BUFSIZ];
	char *dirresul = "./Resultados";
	char *middlepart = "/command";
	char *finalpart = "_output.txt";

	sprintf(fullcom, "%s%s%s%s",dirresul,middlepart,linha,finalpart);

	sprintf(commandx, "%s%s%s",middlepart,linha,finalpart);

	strcpy(pathres, fullcom);

	char localstr[BUFSIZ];
	strcpy(localstr, fullstr);
	char *doub;
	double resdouble = strtod(localstr, &doub);

	FILE *outputtxt = fopen(fullcom, "w");
	fprintf(outputtxt, "%.3f\n", resdouble);

	fclose(outputtxt);
}