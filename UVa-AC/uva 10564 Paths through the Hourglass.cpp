/*
  Name: UVa 10564 
  Copyright: 
  Author: 3T
  Date: 31/08/10 12:58
  Description: DP
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define INP "10564.INP"
#define MAXS 505
#define MAXN 25
#define Left 1
#define Right 2

int N,S,Input[MAXN * 2][MAXN],sx,sy,Direction[MAXN * 2][MAXN][MAXS],ssy;
long long DP[MAXN * 2][MAXN][MAXS],Result;
char D[MAXN * 2];

void Transform(){
     for(int i = 1; i <= N - 1; i++){
             for(int j = 1; j <= N; j++){
                     int Tmp = Input[i][j];
                     Input[i][j] = Input[2 * N - i][j];
                     Input[2 * N - i][j] = Tmp;
                     }
             }
     }

long long calDP(){
     for(int i = 1; i <= N; i++){
             DP[1][i][Input[1][i]] = 1;
             }
     //top triangle 1 -> N
     for(int i = 2; i <= N; i++){
             for(int j = 1; j <= N - i + 1; j++){
                     for(int k = 0; k <= S; k++){
                             int Tmp = k - Input[i][j];
                             if(Tmp >= 0){
                                  DP[i][j][k] = DP[i - 1][j][Tmp] + DP[i - 1][j + 1][Tmp];
                                  //store direct
                                  if(DP[i - 1][j][Tmp] > 0) Direction[i][j][k] = Left;
                                  else if(DP[i - 1][j + 1][Tmp] > 0) Direction[i][j][k] = Right;
                                  }
                             }
                     }
             }
     //bottom
     for(int i = N + 1; i <= 2 * N -1; i++){
             for(int j = 1; j <= i - N + 1; j++){
                     for(int k = 0; k <= S; k++){
                             int Tmp = k - Input[i][j];
                             if(Tmp >= 0){
                                    if(j == 1){
                                         DP[i][j][k] = DP[i - 1][j][Tmp];
                                         if(DP[i - 1][j][Tmp] > 0) Direction[i][j][k] = Right;
                                         }
                                    else if(j == i - N + 1){
                                         DP[i][j][k] = DP[i - 1][j - 1][Tmp];
                                         if(DP[i - 1][j - 1][Tmp] > 0) Direction[i][j][k] = Left;
                                         }
                                    else {
                                         DP[i][j][k] = DP[i - 1][j - 1][Tmp] + DP[i - 1][j][Tmp];
                                         if(DP[i - 1][j - 1][Tmp] > 0) Direction[i][j][k] = Left;
                                         else if(DP[i - 1][j][Tmp] > 0) Direction[i][j][k] = Right;
                                         }
                                    }
                             }
                     }
             }
     
     long long Count = 0;
     for(int i = 1; i <= N; i++){
             Count = Count + DP[2 * N - 1][i][S];
             }
     return Count;
     }

char DtoC(int d){
     if(d == Left) return 'L';
     if(d == Right) return 'R';
     }

void getPath(){
     for(int i = 1; i <= N; i++){
             if(DP[2 * N - 1][i][S] > 0){
                     sx = 2 * N - 1;
                     sy = i;
                     break;
                     }
             }
     ssy = sy;
     int loop = 0;
     int TmpS = S;
     for(int i = 2 * N - 1; i >= 2; i--){
             int Tmp = Direction[i][sy][TmpS];
             char TmpC = DtoC(Tmp);
             D[loop++] = TmpC;
             TmpS -= Input[i][sy];
             if(i <= 2 * N - 1 && i >= N + 1){
                  if(Tmp == Left) sy = sy - 1;
                  }
             else{
                  if(Tmp == Right) sy = sy + 1;
                  }
             }
     }

int main () {
    //FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    while(fscanf(f, "%d %d", &N, &S) && N){
            memset(DP, 0, sizeof DP);
            memset(D, '\0', sizeof D);
            for(int i = 1; i <= N; i++){
                    for(int j = 1; j <= N - i + 1; j++){
                            fscanf(f,"%d", &Input[i][j]);
                            }
                    }
                    
            for(int i = N + 1; i <= 2 * N - 1; i++){
                     for(int j = 1; j <= i - N + 1; j++){
                              fscanf(f, "%d", &Input[i][j]);      
                              }
                     }
            //DP
            Transform();         
            Result = calDP();
            getPath();
            cout << Result << endl;
            if(Result == 0) cout << endl;
            else{
                 cout << ssy - 1 << " " << D << endl;
                 }
            }
            
    //getchar();
    return 0;
    }
