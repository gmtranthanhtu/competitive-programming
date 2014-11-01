/*
  Name: UVa 11420 Chest of Drawers
  Copyright: 
  Author: 3T
  Date: 31/07/10 22:02
  Description: DP
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

#define INP "11420.INP"
#define OUT "11420.OUT"

int s, n;
long long M[70][70][2];

void Init(){
     memset(M, 0, sizeof M);
     M[1][1][1] = 1;
     M[1][0][1] = 0;
     M[1][0][0] = 1;
     M[1][1][0] = 0;
//     M[2][0][0] = 2;
     for(int i = 2; i <= 65; i++){
             M[i][0][0] = M[i - 1][0][0] + M[i - 1][1][1];
             for(int j = 1; j <= i; j++){
                     M[i][j][0] = M[i - 1][j][0] + M[i - 1][j + 1][1];
                     M[i][j][1] = M[i - 1][j - 1][1] + M[i - 1][j - 1][0];
                     }
             }
     }

int main () {
  //  FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    //freopen(OUT, "w", stdout);
    Init();
    while(fscanf(f,"%d%d",&n,&s) && n > 0){
          cout << M[n][s][0] + M[n][s][1] << endl;                       
          }
    //fclose(f);
    //fclose(stdout);
 //   getchar();
    return 0;
    }
