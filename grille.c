/**
 * \file grille.c
 * \brief Les fonctions pour le grille pour le jeux flood_color
 * \author girl's power
 * \date 22/04/2017
 */

#include "grille.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/**
 * \fn matrix init()
 * \brief Fonction de création d'une nouvelle instance de type matrix.
 *allocation dynamique pour une matrice et définir la taille
 *
 * \return Instance nouvelle allouée de type matrix.
 */
matrix init(){
    int i = 0;
    srand( (unsigned)time( NULL));
    matrix table;
    table.taille = taille;
    table.t=(char **)malloc(taille*sizeof(char *));
    for(i=0;i<taille;i++)
        table.t[i]=(char *)malloc(taille*sizeof(char));
    return table;
}

/**
 * \fn void init_rand(matrix table)
 * \brief Fonction pour initialiser les valeurs d'une matrice.
 * l'initialisation se fait avec la fonction rand()
 * \param un table de type matrix pour initialiser ses champs aléatoirement.
 * \return rien mais remplie le champs t de table
 */
void init_rand(matrix table){
    int i = 0,j =0;
    for(i=0;i<taille;i++)
        for(j=0;j<taille;j++){
            table.t[i][j] = *colors[(int)rand()%5];
        }
}

/**
 * \fn void lecture_ficher(matrix table)
 * \brief Fonction pour initialiser les valeurs dans un ficher d'une matrice
 *  l'initialisation se fait avec la fonction fopen(const char *restrict filename, const char *restrict mode) et fgets(char * restrict str, int size, FILE * restrict stream)
 * \param un table de type matrix pour initialiser ses champs dans un ficher.
 * \return rien mais remplie le champs t de table
 */

void lecture_ficher(matrix table){
    FILE *p;
    p=fopen("test.txt","r+");
    int i;
    for(i = 0;i <taille; i++){
        fgets(table.t[i],taille+2,p);
    }
    fclose(p);
}

/**
 * \fn void aff_grille(matrix table)
 * \brief fonction qui affiche la matrice
 * \param un table de type matrix à afficher
 */
void aff_grille(matrix table){
    int i, j;
    for(i=0;i<taille;i++){
        for(j=0;j<taille;j++){
            printf("%c ",table.t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


