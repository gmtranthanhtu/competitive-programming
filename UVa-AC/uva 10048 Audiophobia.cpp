/*
  Name: UVa 10048 Audiophobia
  Copyright: 
  Author: 3T
  Date: 16/06/10 13:17
  Description: Shortest Path, Floyd
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INP "10048.INP"
#define MAXNODE 105
#define MAXINT 100000

int C,S,Q,Case(1),a,b,c;
int M[MAXNODE][MAXNODE];

int main () {
   // FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    while(fscanf(f,"%d%d%d",&C,&S,&Q) && C){
           if(Case != 1) cout << endl;
           printf("Case #%d\n",Case++);
           //iniate
           for(int i = 0; i < MAXNODE; i++){
                   for(int j = 0; j < MAXNODE; j++){
                           M[i][j] = MAXINT;
                           }
                   }
           for(int i = 0; i < S; i++){
                   fscanf(f,"%d%d%d",&a,&b,&c);
                   M[a][b] = M[b][a] = c;                    
                   }
           //Floyd
           for(int j = 1; j <= C; j++){
                for(int k = 1; k <= C; k++){
                      for(int m = 1; m <= C; m++){
                            if(j != k && k != m){
                                 M[k][m] = min(M[k][m],max(M[k][j],M[j][m]));
                                 }
                            }
                      }
                }
                
           for(int i = 0; i < Q; i++){
            int S,D;
            fscanf(f,"%d%d",&S,&D);
            if(M[S][D] != MAXINT)
                printf("%d\n",M[S][D]);
            else puts("no path");
               }                         
           }
//    getchar();
    return 0;
    }
