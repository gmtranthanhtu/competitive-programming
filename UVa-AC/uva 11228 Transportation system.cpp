/*
  Name: UVa 11228 Transportation system
  Copyright: 
  Author: 3T
  Date: 30/06/11 00:30
  Description: Prim, Connected component
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <queue>
using namespace std;

#define MAX 1005
#define MAXE 500000
#define BIG 100000000.01

typedef struct City{
        int x,y;
        };
City O[MAX];
int T,S,P,Trace[MAX],tempi, NumState;
double M[MAX][MAX],d[MAX],tempd,Ed[MAXE], Rail, Road, R;
bool Free[MAX];
bool Visited[MAX];

void Visit(int Cur){
     Visited[Cur] = true;
     for(int i = 1; i <= P; i++){
             if(M[i][Cur] <= R && !Visited[i]){
                          Visit(i);
                          }
             }
     return;
     }

int CountCity(){
     int Num = 0;
     for(int i = 1; i <= P; i++) Visited[i] = false;
     for(int i = 1; i <= P; i++){
             if(!Visited[i]){
                             Num++;
                             Visit(i);
                             }
             }
     return Num;
     }

int main () {
    //freopen("11228.INP", "r", stdin); freopen("11228.OUT", "w", stdout);
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            cin >> P >> R;
            for(int f = 1; f <= P; f++){
                    scanf("%d%d",&O[f].x,&O[f].y);
                    }
            for(int j = 1; j <= P; j ++){
                    for(int k = 1; k <= P; k++){
                            if(j == k) M[j][k] = 0.0;
                            else{
                                 M[j][k] = hypot((double) O[j].x - O[k].x,(double) O[j].y - O[k].y);
                                 }
                            }
                    }
        //Tim so state
        NumState = CountCity();
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

            Rail = Road = 0.0;
            for(int j = 1; j <= l; j++){
                    if(Ed[j] <= R) Road += Ed[j];
                    else Rail += Ed[j];
                    }
            printf("Case #%d: %d %.0lf %.0lf\n",i,NumState,Road,Rail);
            }
    return 0;
    }
