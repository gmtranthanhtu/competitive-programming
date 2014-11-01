/*
  Name: UVa 926 Walking around wisely
  Copyright: 
  Author: 3T
  Date: 20/07/11 21:32
  Description: DP
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define MAXN 35

int T, N, Sx, Sy, Ex, Ey, W, Px, Py;
char D;
char line[100];
bool Connect[MAXN][MAXN][MAXN][MAXN];
ll DP[MAXN][MAXN];

void Update(int Px, int Py, int D){
     if(D == 'S'){
          int y = Py - 1;
          if(y >= 1 && y <= N){
               Connect[Px][Py][Px][y] = Connect[Px][y][Px][Py] = false;
               } 
          }
     if(D == 'W'){
          int x = Px - 1;
          if(x >= 1 && x <= N){
               Connect[Px][Py][x][Py] = Connect[x][Py][Px][Py] = false;
               } 
          }
     if(D == 'N'){
          int y = Py + 1;
          if(y >= 1 && y <= N){
               Connect[Px][Py][Px][y] = Connect[Px][y][Px][Py] = false;
               } 
          }
     if(D == 'E'){
          int x = Px + 1;
          if(x >= 1 && x <= N){
               Connect[Px][Py][x][Py] = Connect[x][Py][Px][Py] = false;
               } 
          }                              
     }

bool Check(){
     if(Sx > Ex || Sy > Ey) return false;
     return true;
     }
     
bool Valid(int x, int y){
     if(x < Sx || y < Sy) return false;
     return true;
     }

void Print(){
             for(int i = Sy; i <= Ey; i++){
                  for(int j = Sx; j <= Ex; j++){
                          cout << "DP[][] " << i << " " << j << " ---- "<< DP[i][j] << " ";
                          }
                  cout << endl;           
                  }     
     }
     
void runDP(){
     int x, y;
     for(int i = Sy; i <= Ey; i++){
             for(int j = Sx; j <= Ex; j++){
                     x = j - 1;
                     y = i;
                     if(Valid(x, y)){
                                 if(Connect[j][i][x][y]) DP[j][i] += DP[x][y];
                                 }
                     
                     x = j;
                     y = i - 1;
                     if(Valid(x, y)){
                                 if(Connect[j][i][x][y]) DP[j][i] += DP[x][y];
                                 }              
                     }
             }
     }



int main () {
    //freopen("926.INP", "r", stdin); freopen("926.OUT", "w", stdout);
    scanf("%d",&T);
    for(int t = 1; t <= T; t++){
            scanf("%d",&N);
            memset(Connect, true, sizeof Connect);
            memset(DP, 0, sizeof DP);
            scanf("%d%d",&Sx,&Sy);
            scanf("%d%d",&Ex,&Ey);
            scanf("%d",&W);
            scanf(" ");
            for(int i = 1; i <= W; i++){
                    gets(line);
                    sscanf(line, "%d %d %c",&Px, &Py, &D);
                    Update(Px, Py, D);
                    }
            if(!Check()){
                         printf("0\n");
                         continue;
                         }
            DP[Sx][Sy] = 1;
            runDP();
            cout << DP[Ex][Ey] << endl;
            }
    
    return 0;
    }
