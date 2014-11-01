/*
  Name: UVa 10502 Counting Rectangle
  Copyright: 
  Author: 3T
  Date: 27/08/10 20:39
  Description: DP, brute force
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define INP "10502.INP"
#define MAX 110

int Input[MAX][MAX],n,m,DP[MAX][MAX],R;
char line[200];

int main () {
    //FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    memset(DP, 0, sizeof DP);
    while(fscanf(f,"%d",&n) && n){
          fscanf(f,"%d",&m);
          fgets(line, 200, f);
          for(int i = 1; i <= n; i++){
                  for(int j = 1; j <= m; j++){
//                          fscanf(f,"%d",&Input[i][j]);
                          DP[i][j] = 0;
                          }
                  }  
           for(int i = 1; i <= n; i++){
                   fgets(line, 200, f);
                   for(int j = 1; j <= m; j++){
                           Input[i][j] = line[j - 1] - '0';
                           }
                   }
          //DP
          for(int i = 1; i <= n; i++){
                  for(int j = 1; j <= m; j++){
                          if(j == 1){
                               DP[i][j] = DP[i - 1][j] + Input[i][j];
                               }
                          else if(i == 1){
                               DP[i][j] = DP[i][j - 1] + Input[i][j];
                               }
                          else{
                               DP[i][j] = DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1] + Input[i][j];
                               }
                          }
                  }
          //cal
          R = 0;
          for(int i = 1; i <= n; i++)
             for(int j = 1; j <= m; j++)
                for(int k = i; k <= n; k++)
                   for(int l = j; l <= m; l++){
                           int Tmp = (k - i + 1) * (l - j + 1);
                           if(i == k && j == l && Input[i][j]) R++;
                           else{
                           int Tmp2 = DP[k][l] - DP[k][j - 1] - DP[i - 1][l] + DP[i - 1][j - 1];
                           if(Tmp == Tmp2) {R++;}
                           }
                           }                
          printf("%d\n",R);
          }
    //getchar();
    return 0;
    }
