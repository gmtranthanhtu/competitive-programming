/*
  Name: UVa 167 The Sultan's Successors
  Copyright: 
  Author: 3T
  Date: 23/07/11 16:08
  Description: 8-queen, backtracking
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define N 8
#define INF 999999999

const int Dif = 10;

int k, Board[N + 5][N + 5], Ans, Queen[N + 5];
bool FreeCol[N + 5], FreeD1[50], FreeD2[50];

void updateSum(){
     int Sum = 0;
     for(int i = 1; i <= N; i++){
             Sum += Board[i][Queen[i]];
             }
     if(Sum > Ans) Ans = Sum;
     }

void runBacktrack(int i){
     for(int j = 1; j <= N; j++){
             if(!FreeCol[j] || !FreeD1[i + j] || !FreeD2[i - j + Dif]) continue;
             Queen[i] = j;
             if(i == N) updateSum();
             FreeCol[j] = false; FreeD1[i + j] = false; FreeD2[i - j + Dif] = false;
             runBacktrack(i + 1);
             FreeCol[j] = true; FreeD1[i + j] = true; FreeD2[i - j + Dif] = true;
             }
     }

int main(){
    //freopen("167.INP", "r", stdin); freopen("167.OUT", "w", stdout);
    scanf("%d",&k);
    while(k--){
               for(int i = 1; i <= N; i++){
                       for(int j = 1; j <= N; j++) scanf("%d",&Board[i][j]);
                       }
               Ans = -INF;        
               memset(FreeCol, true, sizeof FreeCol);
               memset(FreeD1, true, sizeof FreeD1);
               memset(FreeD2, true, sizeof FreeD2);
               runBacktrack(1);
               printf("%5d\n",Ans);
               }
    
    return 0;
    }
