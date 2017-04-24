# ColorFlood

Installation du jeu
------------------------

Vous pouvez installer ColorFlood avec le ficher Makefile

### Installation avec le Makefile

Lancez simplement la commande suivant dans un terminal :
```
make
```

Lancement de jeu
------------------------
Démarrez le jeu après l'avoir installé avec la command : 
```
edit
```

1.Vous entrez la taille de la grille ( > 0 )

2.Vous choisissez la couleur pour jouer

3.Vous etes gagnant si vous reussissez a avoir une grille de meme couleur sans depasser le nombre du coups autorises


Voir Doxygen
------------------------
Entrer dans le dossier html
Ouvrir index.html qui contient la documentation avec doxygen

CUnit
------------------------
pour voir les tests unitaire veuillez enter la commande
```
 cc cunit.c   -o cunit -I /usr/local/Cellar/cunit/2.1-3/include/ -lCUnit -L /usr/local/Cellar/cunit/2.1-3/lib/
```

apres tapez 
```
./cunit
```

Travailler sur le projet
-------------------------

### Pour installer le projet
```
git clone git@gitlab.com:projet_infor/ColorFlood.git
```
### Avant de commencer à travailler
``` 
$ git pull
```

### Pour uploads les changements
```
1. git add (pour voir ce qui a été changé)
2. git commit -a "décrire les changements"
3. git push (upload fichier）

```
