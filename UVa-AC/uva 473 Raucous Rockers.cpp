/*
  Name: UVa 473 Raucous Rockers
  Copyright: 
  Author: 3T
  Date: 24/07/11 02:33
  Description: DP, memoization
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAXN 1005
#define MAXT 105
#define MAXM 105

int C, T, N, M, Time[MAXN];
int DP[MAXN][MAXM][MAXT];

int Memo(int i, int m, int t){
    if(i > N) return 0;
    if(DP[i][m][t] != -1) return DP[i][m][t];
    
    if(Time[i] <= t){
               if(m > 0){
                    DP[i][m][t] = max(1 + Memo(i + 1, m, t - Time[i]), max(1 + Memo(i + 1, m - 1, T - Time[i]), Memo(i + 1, m, t)));
                    return DP[i][m][t];
                    }
               else{
                    DP[i][m][t] = max(1 + Memo(i + 1, m, t - Time[i]), Memo(i + 1, m, t));
                    return DP[i][m][t];
                    }
               }
    else{
         if(m > 0){
              DP[i][m][t] = max(Memo(i + 1, m, t), 1 + Memo(i + 1, m - 1, T - Time[i]));
              return DP[i][m][t];
              }
         else{
              DP[i][m][t] = Memo(i + 1, m, t);
              return DP[i][m][t];
              }
         }
    }

int main () {
    //freopen("473.INP", "r", stdin); freopen("473.OUT", "w", stdout);
    scanf("%d",&C);
    while(C--){
               scanf("%d%d%d",&N,&T,&M);
               for(int i = 1; i <= N; i++){
                       scanf("%d,",&Time[i]);
                       }
               memset(DP, -1, sizeof DP);
               printf("%d\n", Memo(1, M, 0));
               if(C) printf("\n");
               }
    
    return 0;
    }
