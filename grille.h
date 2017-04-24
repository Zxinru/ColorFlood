/**
 * \file grille.h
 * \brief creater le grille pour le jeux flood_color
 * \author girl's power
 * \date 22/04/2017
 */

#ifndef grille_h
#define grille_h

#include <stdio.h>

/**
 * \struct matrix
 * \brief structure pour la matrice des couleurs.
 *
 *matrix contient un tableau de deux dimensions
 * connait la taille de tableau contient , c''est une matrice carre de taille*taille
 *une case de matrix est représentée sous forme du char dans la memoire
 */
struct matrix {
    char **t;
    int taille;
};


typedef char color;





typedef struct matrix matrix;

extern color *colors[];
extern int coup;
extern int taille;

/**
 * \fn matrix init()
 * \brief Fonction de création d'une nouvelle instance de type matrix.
 *allocation dynamique pour une matrice et définir la taille
 *
 * \return Instance nouvelle allouée de type matrix.
 */
matrix init();

/**
 * \fn void init_rand(matrix table)
 * \brief Fonction pour initialiser les valeurs d'une matrice.
 * l'initialisation se fait avec la fonction rand()
 * \param un table de type matrix pour initialiser ses champs aléatoirement.
 * \return rien mais remplie le champs t de table
 */
void init_rand(matrix table);


/**
 * \fn void lecture_ficher(matrix table)
 * \brief Fonction pour initialiser les valeurs dans un ficher d'une matrice
 *  l'initialisation se fait avec la fonction fopen(const char *restrict filename, const char *restrict mode) et fgets(char * restrict str, int size, FILE * restrict stream)
 * \param un table de type matrix pour initialiser ses champs dans un ficher.
 * \return rien mais remplie le champs t de table
 */

void lecture_ficher(matrix table);

/**
 * \fn void aff_grille(matrix table)
 * \brief fonction qui affiche la matrice
 * \param un table de type matrix à afficher
 */
void aff_grille(matrix table);

/**
 * \fn void* liberer(char ** table)
 * \brief fonction qui libere la mémoire allouée d'un tableau de deux dimension
 * \param un table de deux dimension
 *\return Null
 */

void* liberer(char ** table);

#endif /* grille_h */
