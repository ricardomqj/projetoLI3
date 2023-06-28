#include "../includes/queries.h"
#include "../includes/structs.h"
#include "../includes/loadGeral.h"
#include "../includes/interactive_mode.h"

int main(int argc, char *argv[])
{
    
    
    if (argc == 1)
    {
        make_menu();
    }

    else
    {
    
        const int verifyTests = 1;
        
        Geral geral = init_geral();
        load_geral(geral, argv[1]);

        printf("fiz o load geral\n");


        percorre_comandos(argv[2], argv[3], verifyTests, geral);

        printf("percorri os comandos\n");
        
        clean_geral(geral);
        free(geral);

    }


    return 0;
}
