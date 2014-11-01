/*
  Name: UVa 986 How many        
  Copyright: 
  Author: 3T
  Date: 22/07/11 20:00
  Description: DP
*/


#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 45
#define MAXR 45 

int N, R, K;
int DP[MAXR][MAXN][MAXN][5]; // DP[i][j][k][m]: num of ways to have exactly i peaks, at point (j,k)
                             // m = 1: last move is (1, 1); m = 2: last move is (1, - 1)

void runDP(){
     memset(DP, 0, sizeof DP);
     N *= 2;
     DP[0][0][0][1] = 1;
     for(int i = 0; i <= R; i++){
             for(int j = 1; j <= N; j++){
                     for(int k = 0; k <= N; k++){
                             //process
                             if(k != K - 1){//neu k khac K - 1
                                  if(k != 0){
                                       DP[i][j][k][1] = DP[i][j - 1][k - 1][1] + DP[i][j - 1][k - 1][2];
                                       } 
                                  else{
                                       DP[i][j][k][1] = 0;
                                       }
                                       
                                  DP[i][j][k][2] = DP[i][j - 1][k + 1][1] + DP[i][j - 1][k + 1][2];
                                  }
                             
                             else{//k bang K - 1
                                  if(i == 0){// i bang 0
                                       if(k != 0){
                                            DP[i][j][k][1] = DP[i][j - 1][k - 1][1] + DP[i][j - 1][k - 1][2];
                                            }
                                       else{
                                            DP[i][j][k][1] = 0;
                                            }
                                            
                                       DP[i][j][k][2] = DP[i][j - 1][k + 1][2];                              
                                       }
                                  else{//i khac 0
                                       if(k != 0){
                                            DP[i][j][k][1] = DP[i][j - 1][k - 1][1] + DP[i][j - 1][k - 1][2];
                                            }
                                       else{
                                            DP[i][j][k][1] = 0;
                                            }
                                       
                                       DP[i][j][k][2] = DP[i][j - 1][k + 1][2] + DP[i - 1][j - 1][k + 1][1];
                                       }
                                  }
                             
                             
                             
                             
                             
                             
                             //
                             }
                     }
             }
     }

int main () {
    //freopen("986.INP", "r", stdin); freopen("986.OUT", "w", stdout);
    while(scanf("%d%d%d",&N,&R,&K) != EOF){      
           runDP();      
           printf("%d\n",DP[R][N][0][2]);            
           }
    
    return 0;
    }
