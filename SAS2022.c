#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>

typedef struct Products
{
    char nom[20];
    char code[20];
    float prixHT;
    int quantite;
}P ; P product[1000];
int tProducts;

//__________________________________________

typedef struct Logs
{
    char dateTIME[30];
    char nom[20];
    char code[20];
    float PrixUniteTtc;
    int quantite;
} L;L logg[1000];
int numberSOLD;

#include "fonctions.c"
//__________________________________________


int main()
{  
    do
    {   
        MENU();
    } while (1);
    return 0;
}
