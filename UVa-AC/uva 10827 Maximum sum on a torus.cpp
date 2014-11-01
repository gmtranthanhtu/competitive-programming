/*
  Name: UVa 10827 Maximum sum on a torus
  Copyright: 
  Author: 3T
  Date: 10/10/10 17:28
  Description: DP
*/
#include <stdio.h>
#include <algorithm>
using namespace std;

int T, N, S[80][80], M[80][80][80], F[80][80][80][80];


int main () {
    scanf("%d",&T);
    for(int c = 1; c <= T; c++){
            scanf("%d",&N);
            for(int i = 1; i <= N; i++){
                    for(int j = 1; j <= N; j++){
                            scanf("%d",&S[i][j]);
                            }
                    }
            //
            for(int i = 1; i <= N; i++){
                    for(int j = 1; j <= N; j++){
                            for(int k = 1; k <= N; k++){
                                    if(j == k) M[i][j][k] = S[i][j];
                                    else if(j < k){
                                         M[i][j][k] = M[i][j][k - 1] + S[i][k];
                                         }
                                    else{
                                         if(j - k == 1) M[i][j][k] = M[i][1][N];
                                         else M[i][j][k] = M[i][j - 1][k] - S[i][j - 1];
                                         }
                                    }
                            }
                    }
            for(int i = 1; i <= N; i++)
                for(int j = 1; j <= N; j++)
                    for(int k = 1; k <= N; k++)
                        for(int t = 1; t <= N; t++){
                                if(k == t) F[i][j][k][t] = M[k][i][j];
                                else if(k < t){
                                     F[i][j][k][t] = F[i][j][k][t - 1] + M[t][i][j];
                                     }
                                else{
                                     if(k - t == 1) F[i][j][k][t] = F[i][j][1][N];
                                     else F[i][j][k][t] = F[i][j][k - 1][t] - M[k - 1][i][j];
                                     }
                                }
                                
            int R = -1999999999;
            for(int i = 1; i <= N; i++)
                for(int j = 1; j <= N; j++)
                    for(int k = 1; k <= N; k++)
                        for(int t = 1; t <= N; t++)
                           R = max(R, F[i][j][k][t]);
                                       
            printf("%d\n",R);
            }
    
    return 0;
    }
