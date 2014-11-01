/*
  Name: UVa 10891 Game of Sum 
  Copyright: 
  Author: 3T
  Date: 10/10/10 16:10
  Description: maximin game, DP
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;


int F[105][105], N, M[105], DP[105][105];


int findDP(int s, int d){
    if(DP[s][d] != -1) return DP[s][d];
    int Max = -1999999999;
    
    for(int i = s; i <= d - 1; i++){
            Max = max(Max, F[s][i] - findDP(i + 1, d));
            }
    for(int i = d; i >= s + 1; i--){
            Max = max(Max, F[i][d] - findDP(s, i - 1));
            }
    Max = max(Max, F[s][d]);
    
    DP[s][d] = Max;
    return DP[s][d];
    }

int main () {
    while(scanf("%d",&N) && N){
            for(int i = 1; i <= N; i++){
                    scanf("%d",&M[i]);
                    }    
            //
            for(int i = 1; i <= N; i++){
                    for(int j = i; j <= N; j++){
                            if(i == j) F[i][j] = M[i];
                            else F[i][j] = F[i][j - 1] + M[j];
                            }
                    }
            //
            for(int i = 1; i <= N; i++)
              for(int j = i; j <= N; j++) DP[i][j] = -1;
              
            printf("%d\n",findDP(1, N));                     
            }
    return 0;
    }
