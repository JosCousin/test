#ifndef examFonction_h
#define examFonction_h

struct PokeDex
{
    int numero;
    char nom[100];
    char type1[100];
    int type2Temp;
    char type2[100];
    int total;
    int HP;
    int attack;
    int defense;
    int spAtt;
    int spDef;
    int speed;
    int generation;
    char legendary[100];
};

int infoByNum();
int infoByType();
int InfoByGeneration();
int InfoByTotal();
struct PokeDex informationTotal(int pokemon);

int result(struct PokeDex info);
int infoByNom();

#endif /* examFonction_h */