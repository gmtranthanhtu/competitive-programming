/*
  Name: UVa 10593 Kites
  Copyright: 
  Author: 3T
  Date: 30/08/10 17:51
  Description: DP
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define INP "10593.INP"
#define MAX 510

int N; 
char line[MAX];
int Input[MAX][MAX], DP[MAX][MAX], Up[MAX][MAX], Left[MAX][MAX], Down[MAX][MAX], Right[MAX][MAX];

void getDP(){
               for(int i = 1; i <= N; i++){
                  for(int j = 1; j <= N; j++){
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
     }
     
void getRight(){
     for(int i = 1; i <= N; i++){
             Right[i][N + 1] = 0;
             }
     for(int i = 1; i <= N; i++){
             for(int j = N; j >= 1; j--){
                     Right[i][j] = Right[i][j + 1] + Input[i][j];
                     if(!Input[i][j]) Right[i][j] = 0;
                     }
             }
     }

void getLeft(){
     for(int i = 1; i <= N; i++){
             for(int j = 1; j <= N; j++){
                     Left[i][j] = Left[i][j - 1] + Input[i][j];
                     if(!Input[i][j]) Left[i][j] = 0;
                     }
             }
     }
     
void getUp(){
     for(int i = 1; i <= N; i++){
             for(int j = 1; j <= N; j++){
                     Up[i][j] = Up[i - 1][j] + Input[i][j];
                     if(!Input[i][j]) Up[i][j] = 0;
                     }
             }
     }

void getDown(){
     for(int i = 1; i <= N; i++){
             Down[N + 1][i] = 0;
             }
     for(int i = N; i >= 1; i--){
             for(int j = 1; j <= N; j++){
                     Down[i][j] = Down[i + 1][j] + Input[i][j];
                     if(!Input[i][j]) Down[i][j] = 0;
                     }
             }
     }
     
bool isSquare(int i, int j, int k, int l){
     int Tmp = (k - i + 1) * (l - j + 1);
     int Tmp2 = DP[k][l] - DP[k][j - 1] - DP[i - 1][l] + DP[i - 1][j - 1];
     if(Tmp == Tmp2) return true;
     return false;
     }
     
bool isDiamond(int i, int j, int k){
     for(int t = 1; t <= k - 1; t++){
             if(Right[i - k + t][j - t + 1] < 2 * t - 1) return false;
             if(Right[i + k - t][j - t + 1] < 2 * t - 1) return false;
             }
     return true;
     }

long cal(){
     long Count = 0;
     for(int i = 1; i <= N; i++){
             for(int j = 1; j <= N; j++){
                     if(!Input[i][j]) continue;
                     //count square
                     int M = min(Down[i][j], Right[i][j]);
                     for(int k = M; k >= 2; k--){
                             if(isSquare(i, j, i + k - 1, j + k - 1)){
                                            Count += (k - 1);
                                            break;
                                            }
                             }
                     //count diamond
                     M = min(M, min(Up[i][j], Left[i][j]));
                     for(int k = M; k >= 2; k--){
                             if(isDiamond(i , j, k)){
                                             Count += (k - 1);
                                             break;
                                             }
                             }
                     }
             }
     return Count;
     }     

int main () {
    //FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    memset(DP, 0, sizeof DP);
    for(int i = 0; i <= MAX; i++) Left[i][0] = 0;
    for(int i = 0; i <= MAX; i++) Up[0][i] = 0;
    while(fscanf(f,"%d",&N) == 1){
          fgets(line, MAX, f);
          for(int i = 1; i <= N; i++){
                  fgets(line, MAX, f);
                  for(int j = 1; j <= N; j++){
                          if(line[j - 1] == 'x') Input[i][j] = 1;
                          else Input[i][j] = 0;
                          }
                  }
                  getDP();
                  getRight();
                  getUp();
                  getLeft();
                  getDown();
                  long Count = cal();
                  cout << Count << endl;                 
          }
    //getchar();
    return 0;
    }
