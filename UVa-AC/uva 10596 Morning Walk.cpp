
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    FILE *f = stdin;
    int a,b,N,R,E[210],r = 0;
    while(fscanf(f,"%d%d",&N,&R) == 2){
         r = 0;
         for(int i = 0; i < N; i++){
                 E[i] = 0;
                 }
         for(int i = 1; i <= R; i++){
                 fscanf(f,"%d%d",&a,&b);
                 E[a]++;
                 E[b]++; 
                 }
         if(!E[0]) {printf("Not Possible\n"); r = 1;}
         else{
              for(int i = 0; i < N; i++){
                      if(E[i] % 2){
                              printf("Not Possible\n");
                              r = 1;
                              break;
                              }
                      }
              if(!r) printf("Possible\n");
              }                       
         }
    return 0;
    }
