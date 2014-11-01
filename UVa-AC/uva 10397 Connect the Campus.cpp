/*
  Name: UVa 10397 Connect the Campus
  Copyright: 
  Author: 3T
  Date: 25/06/10 02:49
  Description: Minimum Spanning Tree, Prim
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define INP "10397.INP"
#define MAXH 755
#define BIG 100000000.01

typedef struct Home{
        int x;
        int y;
        };
Home H[MAXH];
int N,M,a,b,Trace[MAXH];
double C[MAXH][MAXH],d1,d2,d[MAXH],Result;
bool Free[MAXH];

int main () {
   // FILE *f = fopen(INP, "r");
    FILE *f  = stdin;
    while(fscanf(f,"%d",&N) == 1){
        Result = 0.0;
        for(int i = 1; i <= N; i++){
                fscanf(f,"%d",&H[i].x);
                fscanf(f,"%d",&H[i].y);
                }
                for(int j = 1; j <= N; j++){
                        for(int k = 1; k <= N; k++){
                                if(j == k) C[j][k] = 0.0;
                                else{
                                     d1 = (H[j].x - H[k].x) * (H[j].x - H[k].x);
                                     d2 = (H[j].y - H[k].y) * (H[j].y - H[k].y);
                                     C[j][k] = sqrt(d1 + d2);
                                     }
                                }
                        }
        fscanf(f,"%d",&M);
        for(int i = 1; i <= M; i++){
                fscanf(f,"%d%d",&a,&b);
                C[a][b] = C[b][a] = 0.0;
                }
        
        //Prim
        //initiate
        d[1] = 0.0;
        for(int i = 2; i <= N; i++){
                d[i] = BIG;
                }
        memset(Free,true,sizeof(Free));
        //process
        for(int i = 1; i <= N; i++){
                int u = 0;
                double Min = BIG;
                for(int k = 1; k <= N; k++){
                        if(Free[k] && d[k] < Min){
                                   Min = d[k];
                                   u = k;
                                   }
                        }
                Free[u] = false;
                for(int k = 1; k <= N; k++){
                        if(Free[k] && d[k] > C[u][k]){
                                   d[k] = C[u][k];
                                   Trace[k] = u;
                                   }
                        }
                }
        //trace and calculate the result
         for(int k = 2; k <= N; k++){
                 Result = Result + C[Trace[k]][k];
                 }
         printf("%.2lf\n",Result);                    
        }
 //   getchar();
    return 0;
    }
