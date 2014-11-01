/*
  Name: UVa 11843 Guessing Game
  Copyright: 
  Author: 3T
  Date: 20/09/10 16:21
  Description: DP
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
#define BIG 100000000

int N, S, T;
int M[1005][25];

void Init(){
     for(int i = 1; i <= 1005; i++){
             M[i][1] = i;
             }
     for(int i = 2; i <= 25; i++){
             M[1][i] = 1;
             M[2][i] = 2;
             M[3][i] = 2;
             }
     for(int i = 4; i <= 1005; i++){
             for(int j = 2; j <= 25; j++){
                     int Min = BIG;
                     for(int k = 1; k < i - 1; k ++){
                             int Tmp = max(1 + M[k][j - 1], 1 + M[i - k - 1][j]);
                             Min = min (Min, Tmp);
                             }
                     M[i][j] = Min;
                     }
             }
     }


int main () {
    Init();
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            scanf("%d%d",&N,&S);
            printf("%d\n",M[N][S]);
            }
    
    return 0;
    }
