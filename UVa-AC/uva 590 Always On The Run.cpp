/*
  Name: UVa 590 Always on the run
  Copyright: 
  Author: 3T
  Date: 23/07/11 23:06
  Description: DP
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

#define INF 999999999
#define TYPE int

using namespace std;

typedef struct FlightCost{
        int d;
        int Cost[50];
        };

typedef struct Node{
        int Pos; //possible to reach
        TYPE Sum;
        };        
        
Node DP[1005][50];        
FlightCost FC[50][50]; //
int Case(0), n, k, u, Ans;

void genTable(){
     memset(DP, 0, sizeof DP);
     DP[0][1].Sum = 0;
     DP[0][1].Pos = 1;
     }

void runDP(){
     for(int i = 1; i <= k; i++){
             for(int j = 1; j <= n; j++){
                     TYPE Min = INF;
                     for(int v = 1; v <= n; v++){
                             if(v == j) continue;
                             if(DP[i - 1][v].Pos == 0) continue;
                             int l = (i % FC[v][j].d) ? i % FC[v][j].d : FC[v][j].d;
                             if(FC[v][j].Cost[l] == 0) continue;
                             Min = min(Min, DP[i - 1][v].Sum + FC[v][j].Cost[l]);
                             }
                     if(Min == INF){
                            DP[i][j].Pos = 0;
                            }
                     else{
                          DP[i][j].Pos = 1;
                          DP[i][j].Sum = Min;
                          }
                     }
             }
     }

int main () {
    //freopen("590.INP", "r", stdin); freopen("590.OUT", "w", stdout);
    while(scanf("%d%d",&n,&k) && n){
           u = 0;
           while(u != n){
                   u++;
                   for(int i = 1; i <= n; i++){
                           if(i == u) continue;
                           scanf("%d",&FC[u][i].d);
                           for(int j = 1; j <= FC[u][i].d; j++){
                                   scanf("%d",&FC[u][i].Cost[j]);
                                   }
                           }
                   }  
           genTable();
           runDP();   
           Case++;
           //if(Case > 1) printf("\n");
           printf("Scenario #%d\n",Case);
           if(!DP[k][n].Pos) printf("No flight possible.\n");
           else printf("The best flight costs %d.\n",DP[k][n].Sum);  
           printf("\n");            
           }
    
    return 0;
    }
