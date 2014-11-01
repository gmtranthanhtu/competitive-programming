/*
  Name: UVa 10051 - Tower of Cubes
  Copyright: 
  Author: 3T
  Date: 12/04/10 02:34
  Description: Dynamic Programming
*/

#include <stdio.h>
#include <stdlib.h>

#define Max 501

struct Cell{
       int height;
       int select;
       int parent;
       };
       
Cell F[Max][100];
int N,i,j,k,c,p,q,tallest;
int Cube[Max][6];
int Opposite[6]={1,0,3,2,5,4};
char kq[][10]={"front","back","left","right","top","bottom"};


 
int main () {
    int Case = 1;
    while(scanf("%d",&N) && N != 0){
       for(i = 0;i < N; i++){
          for(j = 0; j < 6;j++){
                scanf("%d",&Cube[i][j]);
                }
          }
          
          //Generate memoized table
       for(i = 0;i < 100;i++) F[N][i].height = 0;
       
       for(i = N - 1; i >= 0;i--)
           for(j = 0; j < 100;j++){
           // Skip the i-th cube...
              F[i][j].height = F[i+1][j].height;
              F[i][j].select = 0;
              F[i][j].parent = j;
              
           //...Or get it, choose the best choice (max height)
           for(k = 0;k < 6; k++)
               if(Cube[i][k] == j){
                       c = Cube[i][Opposite[k]];
                       if(F[i + 1][c].height + 1 > F[i][j].height){
                              F[i][j].height = F[i + 1][c].height + 1;
                              F[i][j].select = 1;
                              F[i][j].parent = c;
                              }
                       }
        }
        //Tracing
        tallest = 0;
        for(j = 0; j < 100;j++){
              if (F[0][j].height > tallest){
                    tallest = F[0][j].height;
                    p = j;
                    }
              }
        if(Case > 1) printf("\n");
        printf("Case #%d\n",Case++);
        printf("%d\n",tallest);
        
        //Look for the first selected cube frome the top...
        q = 0;
        while(F[q][p].select == 0) q++;
//        printf("Test q and p: %d %d\n",q,p);
        
        //...print it
        for(k = 0; k < 6; k++){
              if(Cube[q][k] == F[q][p].parent){
                             printf("%d %s\n",q + 1,kq[Opposite[k]]);
                             p = F[q][p].parent;
                             break;
                             }
              }
    
        //print all other selected cubes
        for(i = q + 1; i < N; i++){
              if(F[i][p].select){
                                 for(k = 0; k < 6; k++){
                                       if(Cube[i][k] == p && Cube[i][Opposite[k]] == F[i][p].parent){
                                                      printf("%d %s\n",i + 1,kq[k]);
                                                      p = F[i][p].parent;
                                                      break;
                                                      }
                                       }
                                 }
              }
       }

    return 0;
    }
