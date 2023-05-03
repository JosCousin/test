#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

#include "examFonction.h"

char InfoByTypeEn[1000][1000] = {"Normal", "Fire", "Water", "Grass", "Electric", "Ice", "Fighting", "Poison", "Ground", "Flying", "Psychic", "Bug", "Rock", "Ghost", "Dragon", "Dark", "Steel", "Fairy"};

char InfoByTypeFr[1000][1000] = {"Normal", "Feu", "Eau", "Plante", "Electrik", "Glace", "Combat", "Poison", "Sol", "Vol", "Psy", "Insecte", "Roche", "Spectre", "Dragon", "Tenebre", "Acier", "Fee"};

int result(struct PokeDex info)
{

    printf("Pokémon numéro : %d\n", info.numero);
    printf("Il s'appelle : %s\n", info.nom);
    printf("Il a le type 1 : %s\n", info.type1);
    if (info.type2Temp != 0)
    {
        printf("Il a un total de : %d\n", info.total);
    }
    else
    {
        printf("Il a le type 2 : %s\n", info.type2);
        printf("Il a un total de : %d\n", info.total);
    }

    printf("Il a %d HP\n", info.HP);
    printf("Il a %d d'attaque\n", info.attack);
    printf("Il a %d de defense\n", info.defense);
    printf("Il a un SP attaque de : %d\n", info.spAtt);
    printf("Il a un SP defense de : %d\n", info.spDef);
    printf("Il a %d de speed\n", info.speed);
    printf("Il est de la génération : %d\n", info.generation);

    if (strcmp(info.legendary, "True") == 0)
    {
        printf("Il est légendaire\n");
    }
    else
    {
        printf("Il n'est pas légendaire\n");
    }

    return 0;
}

struct PokeDex informationTotal(int pokemon)
{

    struct PokeDex info;
    FILE *fp;
    fp = fopen("CSV Annexe.csv", "r");
    if (fp == NULL)
    {
        printf("le document se ferme !!");
    }

    char *pstr;
    char line[1000];
    int count = 0;
    int i;

    do
    {
        if (count == pokemon + 1)
        {
            pstr = strtok(line, ",");
            info.numero = atoi(pstr);

            pstr = strtok(NULL, ",");
            strcpy(info.nom, pstr);

            pstr = strtok(NULL, ",");
            strcpy(info.type1, pstr);

            pstr = strtok(NULL, ",");

            if (info.type2Temp = atoi(pstr) != 0)
            {
                info.total = atoi(pstr);
            }
            else
            {
                strcpy(info.type2, pstr);
                pstr = strtok(NULL, ",");
                info.total = atoi(pstr);
            }

            for (i = 0; i < 18; i++)
            {
                if (strcmp(InfoByTypeEn[i], info.type1) == 0)
                {
                    strcpy(info.type1, InfoByTypeFr[i]);
                }
                if (strcmp(InfoByTypeEn[i], info.type2) == 0)
                {
                    strcpy(info.type2, InfoByTypeFr[i]);
                }
            }

            pstr = strtok(NULL, ",");
            info.HP = atoi(pstr);

            pstr = strtok(NULL, ",");
            info.attack = atoi(pstr);

            pstr = strtok(NULL, ",");
            info.defense = atoi(pstr);

            pstr = strtok(NULL, ",");
            info.spAtt = atoi(pstr);

            pstr = strtok(NULL, ",");
            info.spDef = atoi(pstr);

            pstr = strtok(NULL, ",");
            info.speed = atoi(pstr);

            pstr = strtok(NULL, ",");
            info.generation = atoi(pstr);

            pstr = strtok(NULL, "\n");
            strcpy(info.legendary, pstr);

            break;
        }
        count++;

    } while (fgets(line, sizeof(line), fp));

    fclose(fp);
    return info;
}

int infoByNum()
{

    struct PokeDex info;
    int a;
    FILE *fp;
    fp = fopen("CSV Annexe.csv", "r");
    if (fp == NULL)
    {
        printf("le document se ferme !!");
    }

    int error = 1;

    while (error == 1)
    {
        printf("Entrez le numéro : \n");
        scanf("%d", &a);
        fflush(stdin);

        if (a >= 1 && a <= 721)
        {
            error = 0;
        }
        else
        {
            printf("Entrez un nombre entre 1 et 721 et pas un caractère !\n");
        }
    }

    info = informationTotal(a);

    result(info);
    return 0;
}

int infoByType()
{
    char a[1000];
    FILE *fp;
    fp = fopen("CSV Annexe.csv", "r");
    if (fp == NULL)
    {
        printf("le document se ferme !!");
    }

    struct PokeDex info;
    int h = 1;
    int i;
    int problem = 1;

    while (problem == 1)
    {
        printf("Entrez un type : ");
        scanf("%s", &a);

        for (int i = 0; i < strlen(a); i++)
        {
            a[i] = tolower(a[i]);
        }
        a[0] = toupper(a[0]);

        for (int j = 0; j < 18; j++)
        {
            if (strcmp(InfoByTypeFr[j], a) == 0)
            {
                problem = 0;
                break;
            }
        }
        if (problem == 1)
        {
            printf("Ecrivez le en français et sans accents\n");
        }
    }

    while (h <= 721)
    {
        info = informationTotal(h);

        if (strcmp(info.type1, a) == 0 || strcmp(info.type2, a) == 0)
        {
            printf("%s\n", info.nom);
        }
        h++;
    }

    return 0;
}

int InfoByGeneration()
{
    struct PokeDex info;
    int a;
    FILE *fp;
    fp = fopen("CSV Annexe.csv", "r");
    if (fp == NULL)
    {
        printf("le document se ferme !!");
    }

    int h = 0;
    int error = 1;

    while (error == 1)
    {
        printf("Entrez une génération : \n");
        scanf("%d", &a);
        fflush(stdin);

        if (a >= 1 && a <= 6)
        {
            error = 0;
        }
        else
        {
            printf("Entrez un nombre entre 1 et 6 \n");
        }
    }

    do
    {
        info = informationTotal(h);
        int test1 = info.generation;
        if (test1 == a)
        {
            printf("%s\n", info.nom);
        }
        h++;
    } while (h <= 721);
    return 0;
}

int InfoByTotal()

{
    struct PokeDex info;
    int h = 1;
    while (h <= 721)
    {
        info = informationTotal(h);
        if (info.total > 600)
        {
            printf("%s\n", info.nom);
        }
        h++;
    }
    return 0;
}

int infoByNom()
{

    struct PokeDex info;
    char a[1000];

    FILE *fp;
    fp = fopen("CSV Annexe.csv", "r");
    if (fp == NULL)
    {
        printf("le document se ferme !!");
    }

    int error = 1;

    while (error == 1)
    {
        int h = 1;

        printf("Entrez le nom d'un pokémon : \n");
        scanf("%s", &a);
        fflush(stdin);

        for (int i = 0; i < strlen(a); i++)
        {
            a[i] = tolower(a[i]);
        }

        while (h <= 721)
        {
            char temp[1000];
            info = informationTotal(h);

            for (int i = 0; i < strlen(info.nom); i++)
            {
                info.nom[i] = tolower(info.nom[i]);
            }

            if (strcmp(info.nom, a) == 0)
            {
                info.nom[0] = toupper(info.nom[0]);
                error = 0;
                result(info);
                break;
            }
            h++;
        }
        if (error == 1)
        {
            printf("Entrez un nom en majuscule\n");
            h = 0;
        }
    }

    return 0;
}