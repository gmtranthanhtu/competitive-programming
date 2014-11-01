/*
  Name: UVa 11125 Arrange Some Marbles
  Copyright: 
  Author: 3T
  Date: 05/07/10 15:24
  Description: Recursive, Backtracking, DP, Memoized Table
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 4

int M[5][4][8][8][8][8][5][4],T,Result,N,C[4];

int recursiveDP(int CC, int CS, int AC0, int AC1, int AC2, int AC3, int PC, int PS){
    //CC = current first color, CS = current first size, ACx = number of available color x marble, PC = previous color, PS = previous size
    
    if(M[CC][CS][AC0][AC1][AC2][AC3][PC][PS] != -1) return M[CC][CS][AC0][AC1][AC2][AC3][PC][PS];
    if(AC0 == 0 && AC1 == 0 && AC2 == 0 && AC3 == 0){
           if(PC != CC && PS != CS) {M[CC][CS][AC0][AC1][AC2][AC3][PC][PS] = 1; return 1;}
           else {M[CC][CS][AC0][AC1][AC2][AC3][PC][PS] = 0; return 0;}
          }

    //find any possible marble to put next
    int Count (0);
    for(int i = 0; i < 4; i++){
            if(C[i] == 0 || i == PC) continue;
            for(int j = 1; j <= C[i]; j++){
                    if(j > 3) break;
                    if(j == PS) continue;
                    int tempc;
                    int temps;
                    if(CC == INF){
                             tempc = i;
                             temps = j;
                             }
                    else{
                         tempc = CC;
                         temps = CS;
                         }
                    //backtracking here
                    C[i] -= j; 
                    Count += recursiveDP(tempc, temps, C[0], C[1], C[2], C[3], i, j);
                    C[i] += j;
                    }
            }
    M[CC][CS][AC0][AC1][AC2][AC3][PC][PS] = Count;
    return Count;
    }

int main () {
    memset(M, -1, sizeof M); //init
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            scanf("%d",&N);
            memset(C,0,sizeof C);
            int t = 0;
            for(int j = 0; j < N; j++){
                    scanf("%d",&C[j]);
                    if(C[j] > 0) t++;
                    }
            if(t == 0) printf("1\n");
            else if(t == 1) printf("0\n");
            else{
                 printf("%d\n",recursiveDP(INF,0,C[0],C[1],C[2],C[3],INF,0));
                 }
            }
    }
