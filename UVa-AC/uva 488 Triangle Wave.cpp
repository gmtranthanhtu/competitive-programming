#include <stdio.h>
#include <stdlib.h>

int N, A, F;

void printTriangle(int A){
     for(int i = 1; i <= A; i++){
             for(int j = 1; j <= i; j++) printf("%d", i);
             printf("\n");
             }
     for(int i = A - 1; i >= 1; i--){
             for(int j = 1; j <= i; j++) printf("%d", i);
             printf("\n");
             }
     }

void printWave(int A, int F){
     for(int i = 1; i <= F; i++){
             if(i > 1) printf("\n");
             printTriangle(A);
             }
     }

int main () {
    FILE *f = stdin;
    fscanf(f,"%d",&N);
    for(int i = 1; i <= N; i++){
            fscanf(f,"%d%d",&A,&F);
            if(i > 1) printf("\n");
            printWave(A, F);
            }
    return 0;
    }
