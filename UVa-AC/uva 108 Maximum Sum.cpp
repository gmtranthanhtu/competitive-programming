/*
  Name: UVa 108 Maximum Sum     
  Copyright: 
  Author: 3T
  Date: 16/10/10 09:16
  Description: Maximum Sum, DP
*/
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <algorithm>
using namespace std;

int N, M[105][105], R, F[105][105][105][105];


int main () {
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                    scanf("%d",&M[i][j]);
                    }
            }
    
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            for(int m = i; m <= N; m++)
                for(int n = j; n <= N; n++){
                        if(i == m && n == j) F[i][j][m][n] = M[i][j];
                        else if(i == m) F[i][j][m][n] = F[i][j][m][n - 1] + M[m][n];
                        else if(j == n) F[i][j][m][n] = F[i][j][m - 1][n] + M[m][n];
                        else{
                             F[i][j][m][n] = F[i][j][m][n - 1] + F[i][j][m - 1][n] - F[i][j][m - 1][n - 1] + M[m][n];
                             }
                        }
    R = -1999999999;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            for(int m = i; m <= N; m++)
                for(int n = j; n <= N; n++){
                        R = max(R, F[i][j][m][n]);
                        }
    printf("%d\n",R);
  //  printf("%d\n",F[2][1][4][2]);
  //  printf("%d %d %d\n",F[2][1][4][1],F[2][2][3][2], M[4][2]);
   // getch();
    return 0;
    }
