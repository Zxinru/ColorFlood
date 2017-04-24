
/*
 cc     cunit.c   -o cunit -I /usr/local/Cellar/cunit/2.1-3/include/ -lCUnit -L /usr/local/Cellar/cunit/2.1-3/lib/
 */

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int coup;
typedef char color;
int taille = 3;

struct matrix {
    char **t;
    int taille;
};


typedef struct matrix matrix;

color *colors[] ={"B","V","R","J","M","G"};

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
void test_init(void){
    matrix table;
    table = init();
    int i ;
    for(i=0;i<taille;i++){
    CU_ASSERT(table.t[i] != NULL);
    }
}
void init_rand(matrix table){
    int i = 0,j =0;
    for(i=0;i<taille;i++)
        for(j=0;j<taille;j++){
            table.t[i][j] = *colors[(int)rand()%5];
        }
}


void test_init_rand(void){
    matrix table;
    table = init();
    init_rand(table);
    int i = 0,j =0;
    for(i=0;i<taille;i++){
        for(j=0;j<taille;j++){
            CU_ASSERT(table.t[i][j] == 'B'||table.t[i][j] == 'R'||table.t[i][j] == 'V'||table.t[i][j] == 'M'||table.t[i][j] == 'J'||table.t[i][j] == 'G');
        }
    }
}

void emplir(matrix table, int x, int y, color c){
    table.t[x][y] = c;
}

void test_emplir(void){
    matrix table ;
    table = init();
    emplir(table,1,1,'R');
    CU_ASSERT(table.t[1][1]=='R');
    emplir(table,1,2,'M');
    CU_ASSERT(table.t[1][2]=='M');
    emplir(table,0,2,'J');
    CU_ASSERT(table.t[0][2]=='J');
}

void emp(matrix table, int x, int y, color origine, color new){
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

void test_emp(void){
    matrix table ;
    table = init();
    table.t[0][0] = 'R';
    table.t[0][1] = 'R';
    table.t[0][2] = 'R';
    table.t[1][0] = 'B';
    table.t[1][1] = 'V';
    table.t[1][2] = 'M';
    table.t[2][0] = 'B';
    table.t[2][1] = 'V';
    table.t[2][2] = 'M';
    emp(table, 0, 0, 'R', 'V');
    CU_ASSERT(table.t[0][0] == 'V');
    CU_ASSERT(table.t[0][1] == 'V');
    CU_ASSERT(table.t[0][2] == 'V');
    CU_ASSERT(table.t[1][1] == 'V');
    CU_ASSERT(table.t[2][1] == 'V');
}

matrix change(matrix table, color c){
    color origin = table.t[0][0];
    emp(table, 0, 0, origin, c);
    return table;
}

void test_change(void){
    matrix table ;
    table = init();
    init_rand(table);
    table = change(table, 'V');
    CU_ASSERT(table.t[0][0] == 'V');
}

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

void test_etat(void){
    matrix table ;
    table = init();
    table.t[0][0] = 'R';
    table.t[0][1] = 'R';
    table.t[0][2] = 'R';
    table.t[1][0] = 'B';
    table.t[1][1] = 'V';
    table.t[1][2] = 'M';
    table.t[2][0] = 'B';
    table.t[2][1] = 'V';
    table.t[2][2] = 'M';
    CU_ASSERT(etat(table) == 0);
    table.t[0][0] = 'R';
    table.t[0][1] = 'R';
    table.t[0][2] = 'R';
    table.t[1][0] = 'R';
    table.t[1][1] = 'R';
    table.t[1][2] = 'R';
    table.t[2][0] = 'R';
    table.t[2][1] = 'R';
    table.t[2][2] = 'R';
    CU_ASSERT(etat(table)==1);
}
void* liberer(char ** table){
    int i;
    for(i = 0;i<taille;i++){
        free(table[i]);
        table[i] = NULL;
    }
    free(table);
    return NULL;
}

void test_liberer(void){
    matrix table ;
    table = init();
    
    CU_ASSERT(liberer(table.t) == NULL );
   
}

void lecture_ficher(matrix table){
    FILE *p;
    p=fopen("test.txt","r+");
    int i;
    for(i = 0;i <taille; i++){
        fgets(table.t[i],taille+2,p);
    }
    
}

void test_lecture_ficher(void){
    matrix table ;
    table = init();
    lecture_ficher(table);
    int i;
    int j;
    for(i=0;i<taille;i++){
        for(j=0;j<taille;j++){
            CU_ASSERT(table.t[i][j] == 'B'||table.t[i][j] == 'R'||table.t[i][j] == 'V'||table.t[i][j] == 'M'||table.t[i][j] == 'J'||table.t[i][j] == 'G');
        }
    }
}


int main() {
    CU_pSuite pSuite = NULL;
    
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }
    
    pSuite = CU_add_suite("Suite",NULL,NULL);
    
    if (pSuite==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (CU_add_test (pSuite, "test of init()",test_init)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (CU_add_test (pSuite, "test of init_rand()",test_init_rand)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (CU_add_test (pSuite, "test of emplir()",test_emplir)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (CU_add_test (pSuite, "test of emp()",test_emp)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (CU_add_test (pSuite, "test of change()",test_change)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (CU_add_test (pSuite, "test of etat()",test_etat)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (CU_add_test (pSuite, "test of liberer()",test_liberer)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    if (CU_add_test (pSuite, "test of lecture_ficher()",test_lecture_ficher)==NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    //CU_cleanup_registry();
    
    return 0;
}
