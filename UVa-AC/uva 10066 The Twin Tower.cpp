/*
  Name: UVa 10066 The Twin Tower
  Copyright: 
  Author: 3T
  Date: 23/10/10 09:50
  Description: DP, LCS
*/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

int F[105][105], T1[105], T2[105],  N1, N2, Case(1);

int main () {

    while(scanf("%d%d",&N1,&N2) && N1){
          for(int i = 1; i <= N1; i++){
                  scanf("%d",&T1[i]);
                  }   
          for(int i = 1; i <= N2; i++){
                  scanf("%d",&T2[i]);
                  }        
          //DP
          memset(F, 0, sizeof F);
          for(int i = 1; i <= N1; i++){
                  for(int j = 1; j <= N2; j++){
                          if(T1[i] == T2[j])F[i][j] = F[i - 1][j - 1] + 1;
                          else F[i][j] = max(F[i - 1][j], F[i][j - 1]);
                          }
                  }                              
          printf("Twin Towers #%d\n",Case++);
          printf("Number of Tiles : %d\n\n",F[N1][N2]);
          }
    
    return 0;
    }
