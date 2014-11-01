/*
  Name: UVa 10369 Arctic Network
  Copyright: 
  Author: 3T
  Date: 05/07/10 12:32
  Description: Prim, MST
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 505
#define MAXE 124760
#define BIG 100000000.01

typedef struct Outpost{
        int x,y;
        };
Outpost O[MAX];
int T,S,P,Trace[MAX],tempi;
double M[MAX][MAX],d[MAX],tempd,Ed[MAXE];
bool Free[MAX];

int main () {
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            scanf("%d%d",&S,&P);
            for(int j = 1; j <= P; j++){
                    scanf("%d%d",&O[j].x,&O[j].y);
                    }
            for(int j = 1; j <= P; j ++){
                    for(int k = 1; k <= P; k++){
                            if(j == k) M[j][k] = 0.0;
                            else{
                                 M[j][k] = hypot((double) O[j].x - O[k].x,(double) O[j].y - O[k].y);
                                 }
                            }
                    }
        //Prim
        //initiate
        d[1] = 0.0;
        for(int j = 2; j <= P; j++){
                d[j] = BIG;
                }
        memset(Free,true,sizeof(Free));
        //process
        for(int j = 1; j <= P; j++){
                int u = 0;
                double Min = BIG;
                for(int k = 1; k <= P; k++){
                        if(Free[k] && d[k] < Min){
                                   Min = d[k];
                                   u = k;
                                   }
                        }
                Free[u] = false;
                for(int k = 1; k <= P; k++){
                        if(Free[k] && d[k] > M[u][k]){
                                   d[k] = M[u][k];
                                   Trace[k] = u;
                                   }
                        }
                }
            //Try!!!!!!!!!!!
            int l = 1;
            for(int k = 2; k <= P; k++){
                 Ed[l] = M[Trace[k]][k];
                 l++; 
                 }
            l--;
            //re-sort ascending 
            for(int j = l; j > 1; j--){
                    for(int k = 1; k <= j - 1; k++){
                            if(Ed[k] < Ed[j]){
                                       tempd = Ed[k];
                                       Ed[k] = Ed[j];
                                       Ed[j] = tempd;                                                                              
                                       }
                            }
                    }
            printf("%.2lf\n",Ed[S]);  //Each satellite connection, we can remove an edge, so choose the longest one to remove                 
            }
    return 0;
    }
