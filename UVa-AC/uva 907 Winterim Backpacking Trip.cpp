/*
  Name: UVa 907 Winterim Backpacking Trip
  Copyright: 
  Author: 3T
  Date: 20/07/11 22:40
  Description: DP
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAXN 605
#define MAXK 305
#define INF 999999999

int N, K, C[MAXN][MAXN], DP[MAXK][MAXN];

void runDP(){
     int Min, Tmp;
     for(int j = 0; j <= N + 1; j++){
             DP[1][j] = C[0][j];
             }
             
     for(int i = 2; i <= K; i++){
             for(int j = i; j <= N + 1; j++){
                     Min = INF;
                     Tmp = -INF;
                     for(int t = i - 1; t <= j - 1; t++){
                             Tmp = max(DP[i - 1][t], C[t][j]);
                             Min = min(Min, Tmp);
                             }
                     DP[i][j] = Min;
                     }
             }
     }


int main () {
    //freopen("907.INP", "r", stdin); freopen("907.OUT", "w", stdout);
    while(scanf("%d%d",&N,&K) != EOF){
           for(int i = 0; i <= N; i++){
                   scanf("%d",&C[i][i + 1]);
                   }                   
           //gen
           K++;
           for(int i = 0; i <= N + 1; i++){
                   for(int j = i; j <= N + 1; j++){
                           if(i == j) C[i][j] = 0;
                           else C[i][j] = C[i][j - 1] + C[j - 1][j];
                           }
                   }
           
           //run DP
           runDP();
           cout << DP[K][N + 1] << endl;
           }
    
    return 0;
    }
