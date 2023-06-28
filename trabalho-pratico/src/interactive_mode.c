#include "../includes/structs.h"
#include "../includes/loadGeral.h"
#include "../includes/query1.h"

int count_newlines(char *str) {
    int count = 0;
    for(int i = 0; str[i]!='\0'; i++) {
        if(str[i]=='\n') {
            count++;
        }
    }
    return count;
}

void split_lines(char *str, char lines[][100], int *num_lines) {
    int i, j, k, len;

    len = strlen(str);
    *num_lines = 1;

    // contar o número de linhas
    for(i=0; i<len; i++) {
        if(str[i]=='\n') (*num_lines)++;
    }

    // Copiar cada linha para o array
    j = 0; 
    k = 0;
    for(i=0; i<len; i++) {
        if(str[i]!='\n') {
            lines[j][k] = str[i];
            k++;
        } else {
            lines[j][k] = '\0';
            j++;
            k=0;
        }
    }
}

void interactive_query1(Geral geral)
{
    clear();
    echo();
    char id[12];
    char output[BUFSIZ];
    printw("Insira o ID do perfil\n");
    refresh();

    getstr(id);
    noecho();

    define_output_interactive(geral,id,output);
    clear();
    //WINDOW *win_q1 = newwin(4, 60, 3, 2);
    //box(win_q1, 0, 0);
    //mvwprintw(query_win, 1, 1, "Queries disponíveis:");
    printw("Informações sobre o perfil selecionado:\n");
    printw("%s", output);
    refresh();
    
    mvwprintw(stdscr, getmaxy(stdscr)-1, 1, "Pressione tecla Enter para voltar ao menu");
    wrefresh(stdscr);

    getch();
    clear();
    refresh();
}

void interactive_query2(Geral geral) {
    clear();
    echo();
    int i;
    char n[12];
    char output[999999];
    int linesPerPage = 10;

    printw("Insira o número de Condutores\n");
    refresh();

    getstr(n);
    noecho();
    int num = atoi(n);
    char lines[num][100];

    get_top_N_Drivers_interactive(geral,num,output);
    split_lines(output,lines,&num);   
    clear();
    int totalPages = (num + linesPerPage - 1) / linesPerPage;
    int paginaAtual = 0;
    int primeiraLinha = 0;
    
    if(num<=10) {
        //WINDOW *query2_win = newwin(10,70,2,3);
        //box(query2_win, 0, 0);
        //mvwprintw(query_win, 1, 1, "Queries disponíveis:");
        printw("%s", output);
        refresh(); 
    } else if(num>10) {
        while(1) {
            
            for(i=primeiraLinha; i< primeiraLinha + linesPerPage && i<num; i++) {
                mvwprintw(stdscr,1+(i-primeiraLinha), 2, "%s\n", lines[i]);
            }
            wrefresh(stdscr);
            mvwprintw(stdscr, getmaxy(stdscr)-2, 2, "Pagina %d/%d, pressione seta esquerda/direita para navegar", paginaAtual+1, totalPages);
            mvwprintw(stdscr, getmaxy(stdscr)-1, 2, "Pressione tecla Enter para voltar ao menu");
            wrefresh(stdscr);

            int ch = getch();
            if(ch == KEY_LEFT && paginaAtual>0) {
                paginaAtual--;
                primeiraLinha = paginaAtual * linesPerPage;
            } else if (ch == KEY_RIGHT && paginaAtual < totalPages - 1) {
                paginaAtual++;
                primeiraLinha = paginaAtual * linesPerPage;
            } else if(ch != KEY_LEFT && ch != KEY_RIGHT) {
                clear();
                break;
            }
        }
    }
    strcpy(output, "");

    refresh();
}

void interactive_query3(Geral geral) {
    clear();
    echo();
    int i;
    char n[12];
    char output[999999];
    int linesPerPage = 10;

    printw("Insira o número de Utilizadores\n");
    refresh();

    getstr(n);
    noecho();
    int num = atoi(n);
    char lines[num][100];

    Get_Top_User_Dist_interactive(geral,num,output);
    split_lines(output,lines,&num);   
    clear();
    int totalPages = (num + linesPerPage - 1) / linesPerPage;
    int paginaAtual = 0;
    int primeiraLinha = 0;

    if(num<=10) {
        //WINDOW *query2_win = newwin(10,70,2,3);
        //box(query2_win, 0, 0);
        //mvwprintw(query_win, 1, 1, "Queries disponíveis:");
        printw("%s", output);
        refresh(); 
    } else if(num>10) {
        while(1) {
            for(i=primeiraLinha; i< primeiraLinha + linesPerPage && i<num; i++) {
                mvwprintw(stdscr,1+(i-primeiraLinha), 2, "%s\n", lines[i]);
            }
            mvwprintw(stdscr, getmaxy(stdscr)-2, 2, "Pagina %d/%d, pressione seta esquerda/direita para navegar", paginaAtual+1, totalPages);
            mvwprintw(stdscr, getmaxy(stdscr)-1, 2, "Pressione tecla Enter para voltar ao menu");
            wrefresh(stdscr);

            int ch = getch();
            if(ch == KEY_LEFT && paginaAtual>0) {
                paginaAtual--;
                primeiraLinha = paginaAtual * linesPerPage;
            } else if (ch == KEY_RIGHT && paginaAtual < totalPages - 1) {
                paginaAtual++;
                primeiraLinha = paginaAtual * linesPerPage;
            } else if(ch != KEY_LEFT && ch != KEY_RIGHT) {
                break;
            }
        }
    }
    strcpy(output, "");
    refresh();
}

void interactive_query4(Geral geral) {
    clear();
    char city[124];
    char output[BUFSIZ];
    echo();
    printw("Insira o nome da cidade\n");
    refresh();

    getstr(city);
    noecho();
    City aux = lookupCity(GetHashCity(geral),city);
    if((aux==NULL)|| (get_City_viagens(aux)==0)) {
        free(aux);
        printw("Cidade não econtrada!\n");
    } else {
        double city_preco_medio = preco_medio(aux);
        free(aux);

        returnquery4_interactive(city_preco_medio, output);
    }

    printw("Este é o output:\n%s\n", output);
    refresh();

    mvwprintw(stdscr, getmaxy(stdscr)-1, 1, "Pressione tecla Enter para voltar ao menu");
    wrefresh(stdscr);

    getch();
    clear();
    refresh();
}

void interactive_query5(Geral geral) {
    clear();
    char dataA[100], dataB[100];
    char output[BUFSIZ];
    echo();
    printw("Insira a primeira data\n");
    refresh();

    getstr(dataA);
    //printw("\n");

    printw("Insira a segunda data\n");
    refresh();
    getstr(dataB);
    noecho();
    double aux2 = precoMed_2datas(GetPtrArrayDay(geral),dataA,dataB);
    if((aux2==0)|| conta_viagens_2datas(GetPtrArrayDay(geral),dataA,dataB)==0) {
        printw("Erro!\n");
    } else {
        returnquerie5_interactive(aux2,output);
        printw("Este é o output:\n%s\n", output);
        refresh();
    }

    mvwprintw(stdscr, getmaxy(stdscr)-1, 1, "Pressione tecla Enter para voltar ao menu");
    wrefresh(stdscr);

    getch();
    clear();
    refresh();
}

void interactive_query6(Geral geral) {
    clear();
    char dataA[100], dataB[100], city[100];
    char output[BUFSIZ];
    echo();
    printw("Insira a primeira data\n");
    refresh();
    getstr(dataA);

    printw("Insira a segunda data\n");
    refresh();
    getstr(dataB);

    printw("Insira o nome da cidade\n");
    refresh();
    getstr(city);
    noecho();

    double aux3 = distMedia_2datas_city(GetPtrArrayDay(geral),dataA,dataB,city);

    returnquerie6_interactive(aux3,output);
    printw("Este é o output:\n%s\n", output);
    mvwprintw(stdscr, getmaxy(stdscr)-1, 1, "Pressione tecla Enter para voltar ao menu");
    wrefresh(stdscr);

    getch();
    clear();
    refresh();
    
}

void interactive_query8(Geral geral) {
    clear();
    echo();
    char output[1000000];
    char genero[100], idadePerfil[100];
    int i, num;
    int linesPerPage = 10;

    printw("Insira o gênero(M ou F)\n");
    refresh();
    getstr(genero);

    printw("Insira a idade do perfil\n");
    refresh();
    getstr(idadePerfil);
    noecho();
    clear();

    filter_rides_gender_acc(geral, genero, idadePerfil, output);
    num = count_newlines(output);

    char lines[num][100];
    split_lines(output, lines, &num);
    int totalPages = (num + linesPerPage - 1) / linesPerPage;
    int paginaAtual = 0;
    int primeiraLinha = 0;

    if(num<=10) {
        mvwprintw(stdscr, 1, 1, "%s", output);
        mvwprintw(stdscr, getmaxy(stdscr-1), 2, "Pressione tecla Enter para voltar ao menu");
        wrefresh(stdscr);
        getch();
        clear();    
    } else if (num>10) {
        while(1) {
            for(i=primeiraLinha; i<primeiraLinha+linesPerPage && i<num; i++) {
                mvwprintw(stdscr, 1+(i-primeiraLinha), 2, "%s\n", lines[i]);
            }
            mvwprintw(stdscr, getmaxy(stdscr)-2, 2, "Pagina %d/%d, pressiona seta esquerda/direita para navegar", paginaAtual+1, totalPages);
            mvwprintw(stdscr, getmaxy(stdscr)-1, 2, "Pressione tecla Enter para voltar ao menu");
            wrefresh(stdscr);

            int ch = getch();
            if(ch == KEY_LEFT && paginaAtual>0) {
                paginaAtual--;
                primeiraLinha = paginaAtual * linesPerPage;
            } else if(ch == KEY_RIGHT && paginaAtual < totalPages -1) {
                paginaAtual++;
                primeiraLinha = paginaAtual * linesPerPage;
            } else if(ch != KEY_LEFT && ch != KEY_RIGHT) {
                clear();
                break;
            }
        }
    }
    refresh();
}

void interactive_query9(Geral geral) {
    clear();
    echo();
    char output[1000000];
    char dataA[100], dataB[100];
    int i,num;
    int linesPerPage = 10;
    
    printw("Insira a primeira data\n");
    refresh();
    getstr(dataA);

    printw("Insira a segunda data\n");
    refresh();
    getstr(dataB);
    noecho();
    clear();
    
    make_Glista_grojeta_intervalo(geral, dataA, dataB, output);
    num = count_newlines(output);


    char lines[num][100];

    split_lines(output,lines,&num);
    int totalPages = (num + linesPerPage - 1) / linesPerPage;
    int paginaAtual = 0;
    int primeiraLinha = 0;

    if(num<=10) {
        printw("%s", output);
        //refresh();
        mvwprintw(stdscr, getmaxy(stdscr-1), 2, "Pressione tecla Enter para voltar ao menu");
        wrefresh(stdscr);
        getch();
        clear();
    } else if(num>10) {
        while(1) {
            for(i=primeiraLinha; i<primeiraLinha+linesPerPage && i<num; i++) {
                mvwprintw(stdscr,1+(i-primeiraLinha), 2, "%s\n", lines[i]);
            }
            mvwprintw(stdscr, getmaxy(stdscr)-2, 2, "Pagina %d/%d, pressione seta esquerda/direita para navegar", paginaAtual+1, totalPages);
            mvwprintw(stdscr, getmaxy(stdscr)-1, 2, "Pressione tecla Enter para voltar ao menu");
            wrefresh(stdscr);

            int ch = getch();
            if(ch == KEY_LEFT && paginaAtual>0) {
                paginaAtual--;
                primeiraLinha = paginaAtual * linesPerPage;
            } else if (ch == KEY_RIGHT && paginaAtual < totalPages - 1) {
                paginaAtual++;
                primeiraLinha = paginaAtual * linesPerPage;
            } else if(ch != KEY_LEFT && ch != KEY_RIGHT) {
                clear();
                break;
            }
        }
    }
    refresh();
}

void make_menu() {
    char path[100];
    
    initscr();
    cbreak();

    printw("Escolha o caminho para a data a ser utilizada:\n");
    refresh();
    getstr(path);
    Geral geral = init_geral();
    load_geral(geral, path);

    clear();
    noecho();

    char *infoQ1 = "1: Listar resumo de um perfil através do seu identificador.\n";
    char *infoQ2 = "2: Top N condutores com maior avaliação média.\n";
    char *infoQ3 = "3: Top N utilizadores com maior distância viajada.\n";
    char *infoQ4 = "4: Preço médio das viagens numa determinada cidade.\n";
    char *infoQ5 = "5: Preço médio das viagens num dado intervalo de tempo.\n";
    char *infoQ6 = "6: Distância média percorrida, num intervalo de tempo, numa cidade.\n";
    char *infoQ7 = "7: Top de condutores com maior avaliação média, numa cidade.\n";
    char *infoQ8 = "8: Viagens em que o utilizador são do género passado e com perfis com uma certa idade.\n";
    char *infoQ9 = "9: Viagens nas quais o passageiro deu gorjeta, num intervalo de tempo.\n";
    //char *infoQ6 = "6 -> Distância média percorrida, numa determinada cidade, num dado intervalo de tempo.\n";
    //char *infoQ9 = "9 -> Lista as viagens nas quais o passageiro deu gorjeta, num dado intervalo de tempo.\n";

    keypad(stdscr, true);
    char *choices[9] = {infoQ1, infoQ2, infoQ3, infoQ4, infoQ5, infoQ6, infoQ7, infoQ8,infoQ9};
    int choice;
    int highlight = 0;
    int flagWhile = 1;

    while(flagWhile==1) {
        mvwprintw(stdscr,1,1,"Queries disponíveis");
        for(int i = 0; i<9; i++) {
            if(i==highlight)
                wattron(stdscr, A_REVERSE);
            mvwprintw(stdscr, i+2, 1, "%s",choices[i]);
            wattroff(stdscr, A_REVERSE);
        }
        choice = wgetch(stdscr);

        switch(choice) {
            case KEY_UP:
                highlight--;
                if(highlight==-1)
                    highlight = 0;
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight==9)
                    highlight = 8;
                break;
            default:
                break;
        }
        if((choice==10)&&(highlight==0)) {
            interactive_query1(geral);
        } else if((choice == 10) && (highlight==1)) {
            interactive_query2(geral);
        } else if ((choice == 10)&&(highlight==2)) {
            interactive_query3(geral);
        } else if((choice == 10)&&(highlight==3)) {
            interactive_query4(geral);
        } else if((choice == 10)&&(highlight == 4)) {
            interactive_query5(geral);
        } else if((choice == 10)&&(highlight == 5)) {
            interactive_query6(geral);
        } else if((choice == 10) && (highlight==7)) {
            interactive_query8(geral);
        } else if((choice == 10)&&(highlight == 8)) {
            interactive_query9(geral);
        }               
    }
    getch();
    endwin();
}