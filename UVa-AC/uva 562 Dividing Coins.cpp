/*
  Name: UVa 562 Dividing coins
  Copyright: 
  Author: 3T
  Date: 23/07/11 21:35
  Description: DP, knapsack 
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAXW 50005
#define MAXN 205

int N, T, DP[MAXN][MAXW], W, We[MAXN], WW, Ans;

void runDP(){
     for(int i = 0; i <= WW; i++) {DP[0][i] = 0;}
     //for(int i = 0; i <= N; i++) DP[i][0] = 0;

     for(int i = 1; i <= N; i++){
             for(int j = 0; j <= WW; j++){
                     if(We[i] <= j){
                              DP[i][j] = max(DP[i - 1][j], We[i] + DP[i - 1][j - We[i]]);                              
                              }
                     else DP[i][j] = DP[i - 1][j];
                     }
             }
     int Tmp = W - DP[N][WW];
     if(Tmp > DP[N][WW]) Ans = Tmp - DP[N][WW];
     else Ans = DP[N][WW] - Tmp;
     }

int main () {
    //freopen("562.INP", "r", stdin); freopen("562.OUT", "w", stdout);
    scanf("%d",&T);
    for(int t = 1; t <= T; t++){
               W = 0;
               scanf("%d",&N);
               for(int i = 1; i <= N; i++){
                       scanf("%d",&We[i]);
                       W += We[i];
                       WW = W / 2;
                       }
               if(N == 0){
                    printf("0\n");
                    continue;
                    }
               if(N == 1){
                    printf("%d\n",We[1]);
                    continue;
                    }

               runDP();
               printf("%d\n",Ans);
               }
    
    
    return 0;
    }
