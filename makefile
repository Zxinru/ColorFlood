edit: grille.o main.o
	gcc -Wall -Wextra -ansi -o edit grille.o main.o
grille.o: grille.c grille.h
	gcc -Wall -Wextra -ansi -c grille.c
main.o: main.c grille.h
	gcc -Wall -Wextra -ansi -c main.c
.PHONY:clean
clean:
	-rm edit main.o
