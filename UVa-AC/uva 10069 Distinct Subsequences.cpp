/*
  Name: UVa 10069 Distinct Subsequences
  Copyright: 
  Author: 3T
  Date: 02/06/10 16:58
  Description: DP
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define Max1 10005
#define Max2 105
#define INP "10069.INP"

int N,i,sX,sZ,j,r,len1,len2,MaxLen;
int M[Max2][Max1][Max2+1];
char X[Max1],Z[Max2];


void Add2Cell(int rowD, int colD, int rowS1, int colS1, int rowS2, int colS2){
     int j;
     for(j = Max2; j >= 0; j--){
           if(M[rowS1][colS1][j] != 0) break;
           }     
     len1 = j;
     for(j = Max2; j >= 0; j--){
           if(M[rowS2][colS2][j] != 0) break;
           } 
     len2 = j;
     if(len1 == -1 && len2 >= 0){
             for(j = 0; j <= len2; j++){
                   M[rowD][colD][j] = M[rowS2][colS2][j];
                   }
             for(j = len2 + 1; j <= Max2; j++) M[rowD][colD][j] = 0;
             }
     else if(len2 == -1 && len1 >= 0){
             for(j = 0; j <= len1; j++){
                   M[rowD][colD][j] = M[rowS1][colS1][j];
                   }
             for(j = len1 + 1; j <= Max2; j++) M[rowD][colD][j] = 0;
             }
     else if(len2 == -1 && len1 == -1){
          for(j = 0; j <= Max2; j++){
                M[rowD][colD][j] = 0;
                }
          }
     else if(len2 >= 0 && len1 >= 0){
 //     MaxLen = std::max(len1,len2);
 if(len1 > len2) MaxLen = len1;
 else MaxLen = len2;
//      printf("Test1: %d\n",MaxLen);
     r = 0;
     for(j = 0; j <= MaxLen; j++){
           int temp = M[rowS1][colS1][j] + M[rowS2][colS2][j] + r;
           if(temp < 10) {M[rowD][colD][j] = temp; r = 0;}
           else{
                M[rowD][colD][j] = temp % 10;
                r = 1;
                }
           }
       if(r == 1) M[rowD][colD][MaxLen + 1] = 1;
       else M[rowD][colD][MaxLen + 1] = 0;  
      for(int u = MaxLen + 2; u <= Max2; u++){
              M[rowD][colD][u] = 0;
              }
          }  
     }     

void PrintCell(int row, int col){
     int j;
     for(j = Max2; j >= 0; j--){
           if(M[row][col][j] != 0) break;
           }
     if(j < 0){printf("%d",0);return;}
     else{
     for(int p = j; p >= 0; p--){
             printf("%d",M[row][col][p]);
             }
             }
     }

int main () {
   // FILE *f = fopen(INP, "r");
  //  FILE *f = stdin;   ------------> wrong answer
    scanf("%d ",&N);
//    getchar();
    for(i = 1; i <= N; i++){
//    memset(M,0,sizeof(M));  ----------> time limit
          gets(X);
          sX = strlen(X);
          gets(Z);
          sZ = strlen(Z);
          if(sX == 0 && sZ == 0) printf("1\n");
          else if(sZ > sX) printf("0\n");
          else{
          for(int p = 0; p <= sX; p++){
                  M[0][p][0] = 1;
                  for(j = 1; j <= Max2; j++){
                        M[0][p][j] = 0;
                        }
                  }

          for(int p = 1; p <= sZ ; p++){
                  for(j = 0; j <= Max2; j++){
                        M[p][p - 1][j] = 0;
                        }
                  }
          for(int p = 1; p <= sZ; p++){
                  for(int q = p; q <= sX; q++){
                        if(X[q - 1] == Z[p - 1]){
                               Add2Cell(p,q,p,q - 1,p - 1,q - 1);
                               }
                        else{
                             for(int t = 0; t <= Max2; t++){
                                     M[p][q][t] = M[p][q-1][t];
                                     }
                             } 
                        }
                  }
          PrintCell(sZ,sX);
          printf("\n");
                    }
          }
 //   getchar();
    return 0;
    }
