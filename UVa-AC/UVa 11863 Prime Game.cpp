/*
  Name: UVa 11863 Prime Game
  Copyright: 
  Author: 3T
  Date: 10/10/10 03:47
  Description: DP
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 1000005

bool prime[Max];

void Generate_Primes(){
     prime[1] = false;
     for( int i = 2; i < Max; ++i){
          prime[i] = true;
          }
     for( int i = 2; i < Max; ++i){
while(i < Max && !prime[i]){i++;}
          for( int j = 2; i * j < Max; ++j){
               prime[i * j] = false;
               } 
          }
     }

int F[105][105], T, N, K, M[105], DP[105][105], WW;
bool W;

int findDP(int s, int d){
    if(DP[s][d] != -1) return DP[s][d];
    if(F[s][d] > 0 && prime[F[s][d]]){
                       DP[s][d] = 1;
                       return 1;
                       }
    for(int i = s; i <= d - 1; i++){
            if(F[s][i] > 0 && prime[F[s][i]]){
                               if(findDP(i + 1, d) == 0){
                                           DP[s][d] = 1;
                                           return 1;
                                           }
                               }
            }
    for(int i = d; i >= s + 1; i--){
            if(F[i][d] > 0 && prime[F[i][d]]){
                               if(findDP(s, i - 1) == 0){
                                            DP[s][d] = 1;
                                            return 1;
                                            }
                               }
            }
    DP[s][d] = 0;
    return 0;
    }

int main () {
    Generate_Primes();
    scanf("%d",&T);
    for(int c = 1;  c <= T; c++){
            scanf("%d%d",&N,&K);
            W = false;
            for(int g = 1; g <= N; g++){
                    scanf("%d",&M[g]);
                    if(M[g] == 42) W = true;
                    }
            if(W){
                  printf("Case %d: Soha\n",c);
                  continue;
                  }
            //build triangle
            for(int i = 1; i <= N; i++){
                    for(int j = i; j <= N; j++){
                            if(i == j) F[i][j] = M[i];
                            else F[i][j] = F[i][j - 1] + M[j];
                            }
                    }
            if(F[1][N] > 0 && prime[F[1][N]]){
                  printf("Case %d: Soha\n",c);
                  continue;
                               }
                               
            //DP
            for(int i = 1; i <= N; i++)
              for(int j = i; j <= N; j++) DP[i][j] = -1;
              
            WW = findDP(1, N);
            printf("Case %d: %s",c, WW ? "Soha\n" : "Tara\n");
       
            }
    return 0;
    }
