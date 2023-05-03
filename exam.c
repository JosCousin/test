#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

#include "examFonction.h"

int main()
{
    int menu = 0;
    int continuer = 1;
    char choix[1000];

    while (continuer == 1)
    {
        int error = 1;
        while (menu < 1 || menu > 5)
        {

            printf("1 Information général du pokémon par le numéro\n2 Nom du pokémon selon le type entré\n3 Nom du pokémon selon sa génération\n4 Tout les pokémons ayant plus de 600 de total\n5 Information générale d'un pokémon par son nom\nVotre choix : ");
            scanf("%d", &menu);
            fflush(stdin);
        }

        switch (menu)
        {
        case 1:
        {
            infoByNum();
        }
        break;

        case 2:
        {
            infoByType();
        }
        break;
        case 3:
        {
            InfoByGeneration();
        }
        break;
        case 4:
        {
            InfoByTotal();
        }
        break;
        case 5:
        {
            infoByNom();
        }
        break;

        default:
            break;
        }

        while (error == 1)
        {
            printf("\nVoulez-vous continuer ? oui/non\n-->");
            scanf("%s", &choix);

            if (strcmp(choix, "non") == 0)
            {
                continuer = 0;
                error = 0;
            }
            else if (strcmp(choix, "oui") != 0)
            {
                printf("sélectionnez sois oui ou sois non");
            }
            else
            {
                error = 0;
                menu = 0;
            }
        }
    }
}
