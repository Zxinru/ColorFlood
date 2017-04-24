
/**
 * \file main.c
 * \brief le lot A pour le jeux flood_color
 * \author girl's power
 * \date 22/04/2017
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "grille.h"

int coup;
int taille;
color *colors[] ={"B","V","R","J","M","G"};




/**
 * \fn int etat (matrix table)
 * \brief Fonction pour vérifier si toutes les cases sont du même couleur.
 *
 * \param un table de type matrix.
 * \return 1 si le joueur reussi à avoir la même couleur , 0 sinon
 */


int etat (matrix table){
    int c  = table.t[0][0];
    int i,j;
    for(i=0;i<taille;i++)
        for(j=0;j<taille;j++){
            if(table.t[i][j] != c){
                return 0;
            }
            else{
                continue;
            }
        }
    return 1;
}

/**
 * \fn void emplir(matrix table, int x, int y, color c)
 * \brief Fonction qui permet de changer la couleur d'une seule case de la matrice .
 *
 * \param table de type matrix , les indices du case à changer x et y , la couleur à mettre dans la case de type color.
 *
 */

void emplir(matrix table, int x, int y, color c){
    table.t[x][y] = c;
}

/**
 * \fn void  emp(matrix table, int x, int y, color origine, color new)
 * \brief Fonction cherche les cases du méme couleur d'origine et en voisinnage de la case donnée en param
 * la fonction fait appel à la fonction emplir et récursivement la fonction emp pour les voisins du case entrée.
 *à partir de la case demandés , on cherche déja si elle porte la couleur d'origine
 *la zone à colorer  commence par l'indice x,y .
 *la fonction cherche les voisins du meme couleur que cette zones pour changer leur couleur to new color
 *\param table de type matrix , indices de la case , l'ancienne couleur , et la nouvelle couleur.
 *
 
 */


void  emp(matrix table, int x, int y, color origine, color new){
    if(x >= 0 && x < taille && y >= 0 && y < taille
       && table.t[x][y] == origine && table.t[x][y] != new)
    {
        emplir(table, x, y, new);
        emp(table, x + 1, y, origine, new);
        emp(table, x - 1, y, origine, new);
        emp(table, x , y + 1, origine, new);
        emp(table, x , y - 1, origine, new);
    }
}

/**
 * \fn matrix change(matrix table, color c)
 * \brief Fonction qui change la couleur du composante connexe du meme couleur à partir de la case gauche en haut(0.0).
 * \param un table de type matrix et la nouvelle couleur c
 * \return un table final aprés la coloration du couleur demandée
 */
matrix change(matrix table, color c){
    color origin = table.t[0][0];
    emp(table, 0, 0, origin, c);
    return table;
}


/**
 * \fn void* liberer(char ** table)
 * \brief fonction qui libere la mémoire allouée d'un tableau de deux dimension
 * \param un table de deux dimension
 *\return Null
 */

void* liberer(char ** table){
    int i;
    for(i = 0;i<taille;i++){
        free(table[i]);
        table[i] = NULL;
    }
    free(table);
    table = NULL;
    return NULL;
}





/**  \fn int main ()
 * \brief Entrée du programme.
 *l'utilisateur choisi la taille du matrice
 *appel les fonction init(),init_rand(),aff_grille()
 *nombre du coups possible  est taille *2
 *l'utilisateur choisi une couleur tantque qu'il a encore les coups pour jouer
 *appel à la fonction change(),et affiche la matrice aprés coloration
 *vérifie l'etat du table , si gagnant sort de la boucle qui compte les coups sinon continue
 *libération du mémoire allouer
 *\return 0
 */
int main() {
    matrix table;
    int i = 1 ;
    int c;
    
    printf("choisir une taille de grille : \n");
    scanf("%i", &taille);
    printf("Tu a %d coups\n",(int)(taille*2));
    coup = taille*2;
    
    
    
    printf("C'est le grille avec les champs dans ficher test.txt\n");
    matrix table1;
    table1 = init();
    lecture_ficher(table1);
    aff_grille(table1);
    
    printf("C'est le grille avec les champs aléatoirement\n");
    table = init();
    init_rand(table);
    aff_grille(table);
    
    
    
    while(i<= taille*2){
        printf("choisir une couleur(entre le numero de couleur):\n 1.B, 2.V, 3.R, 4.J, 5.M, 6.G\n");
        scanf("%i", &c);
        
        if(c>6 || c<1){
            printf("erreur de couleur!");
            printf("choisir encore une couleur(entre le numero de couleur):\n 1.B, 2.V, 3.R, 4.J, 5.M, 6.G\n");
            scanf("%i", &c);
        }
        
        printf("C'est la table après changer le couleur\n");
        table = change(table, *colors[c-1]);
        aff_grille(table);
        if(etat(table)){
            printf("win!\n");
            break;
        }
        printf("%i/%i\n",i,coup);
        i=i+1;
    }
    
    if(i > taille*2)
        printf("lose\n");
    
    liberer(table.t);
    liberer(table1.t);
    return 0;
}
