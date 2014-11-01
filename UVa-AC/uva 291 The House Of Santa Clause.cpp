/*
  Name: UVa The House of Santa Clause
  Copyright: 
  Author: 3T
  Date: 08/11/10 15:46
  Description: backtracking
*/
#include <stdio.h>
#include <string.h>

int X[]= {1, 1, 1, 2, 2, 3, 3, 4};
int Y[]= {2, 3, 5, 3, 5, 4, 5, 5};
int Checked[10][10];
int M[10][10];
int Out[10];

void Init(){
     for(int i = 1; i <= 5; i++){
             for(int j = 1; j <= 5; j++){
                     Checked[i][j] = 0;
                     M[i][j] = 0;
                     }
             Checked[i][i] = 1;
             }
     for(int i = 0; i < 8; i++){
             M[X[i]][Y[i]] = M[Y[i]][X[i]] = 1;
             }
     Out[1] = 1;
     }
     
void Print(){
     for(int i = 1; i <= 9; i++) printf("%d",Out[i]);
     printf("\n");
     }

void backtrack(int s, int n){
     if(n == 8){
          Print();
          return;
          }
     for(int i = 1; i <= 5; i++){
             if(!Checked[s][i] && M[i][s]){
                                Checked[s][i] = Checked[i][s] = true;
                                Out[n + 2] = i;
                                backtrack(i, n + 1);
                                Checked[s][i] = Checked[i][s] = false;
                                }
             }
     }


int main () {
    //freopen("291.OUT", "w", stdout);
    Init();
    backtrack(1, 0);
    
    return 0;
    }
