/*
  Name: UVa 369 Combinations
  Copyright: 
  Author: 3T
  Date: 27/10/10 07:31
  Description: math, combination
*/
#include <iostream>
#include <math.h>
using namespace std;

long long C[101][101];
int N, M;

void Generate_Combination(){
     for(int i = 1; i <= 100; i++){
             for(int j = 0; j <= i; j++){
                     if(j == i || j == 0) C[i][j] = 1;
                     else{
                          C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                          }
                     }
             }
     
     }


int main () {
    Generate_Combination();
    while(scanf("%d%d",&N,&M) && N){
            printf("%d things taken %d at a time is ",N,M);
            cout << C[N][M];
            printf(" exactly.\n");                  
            }
    
    return 0;
    }
