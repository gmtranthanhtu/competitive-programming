/*
  Name: UVa 11833 Route Change
  Copyright: 
  Author: 3T
  Date: 20/09/10 10:12
  Description: Dijsktra
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define BIG 1999999999

int N, M, C, K, a, b, c, R;
int P[260][260], DC[260], d[260];
bool Free[260];

void Init(){
     DC[C - 1] = 0;
     for(int i = C - 2; i >= 0; i--){
             DC[i] = DC[i + 1] + P[i][i + 1];
             }
    // for(int i = 0; i < C; i++) printf("%d ",DC[i]);
    // printf("\n");
     }
     
bool inRoute(int u){
     if(u >= 0 && u < C) return true;
     else return false;
     }
     
int Dijsktra(int S, int D){
    for(int i = 0; i < N; i++) {d[i] = BIG; Free[i] = true;}
    d[S] = 0;
    int u, v, w;
    do{
        u = -1;
        w = BIG;
        for(int i = 0; i < N; i++){
                if(Free[i] && d[i] < w && !inRoute(i)){
                           w = d[i];
                           u = i;
                           } 
                }
        if(u == -1 || u == D) break;
        Free[u] = false;
        for(v = 0; v < N; v++){
              if(Free[v] && (!inRoute(v) || v == D) && d[v] > d[u] + P[u][v]){
                         d[v] = d[u] + P[u][v];
                         }
              }
        }while(1);
    return d[D];
    }

int main () {
    //freopen("D.INP", "r", stdin);
    //freopen("D.OUT", "w", stdout);
    while(scanf("%d%d%d%d",&N,&M,&C,&K) && N){
           for(int i = 0; i < N; i ++){
                   for(int j = 0; j < N; j++){
                           P[i][j] = BIG;
                           }
                   P[i][i] = 0;
                   }           
           for(int i = 1; i <= M; i++){
                   scanf("%d%d%d",&a,&b,&c);
                   P[a][b] = P[b][a] = c;
                   }        
           Init();
           if(inRoute(K)){
                          printf("%d\n",DC[K]);
                          continue;
                          }
           R = BIG;
           for(int i = 0; i < C; i++){
                   int Temp = Dijsktra(K, i) + DC[i];
                   R = min(Temp, R);
                   }
           printf("%d\n",R);
           }
    
    return 0;
    }
