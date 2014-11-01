/*
  Name: UVa 116 Unidirectional TSP
  Copyright: 
  Author: 3T
  Date: 23/07/11 15:09
  Description: DP
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

#define MAXM 20
#define MAXN 105
#define INF 999999999

typedef struct Cell{
        int Parent;
        int Value;
        int Path[MAXN];
        };

Cell DP[MAXM][MAXN];
int N, M, Ans;
int C[MAXM][MAXN];
int PathAns[MAXN];

int Convert(int a){
    if(a == 0) return M;
    if(a == M + 1) return 1;
    else return a;
    }
    
bool cmpPath(int Patha[MAXN], int Pathb[MAXN], int Last){
     for(int i = 1; i <= Last; i++){
             if(Patha[i] > Pathb[i]) return true;
             if(Patha[i] < Pathb[i]) return false;
             }
     return false;        
     }

void runDP(){
     //gen
     memset(DP, 0, sizeof DP);

     for(int i = 1; i <= M; i++){
             DP[i][1].Parent = -1;
             DP[i][1].Value = C[i][1];
             DP[i][1].Path[1] = i;
             }
                                       
     //run
     for(int j = 2; j <= N; j++){
             for(int i = 1; i <= M; i++){
                     int x;
                     int TmpMin = INF;
                     int v = INF;
                     int TmpP[MAXN];
                     for(int k = -1; k <= 1; k++){
                             x = Convert(i + k);
                             if(DP[x][j - 1].Value < TmpMin){
                                     TmpMin = DP[x][j - 1].Value;
                                     v = x;
                                     for(int p = 1; p <= j - 1; p++){
                                             TmpP[p] = DP[x][j - 1].Path[p];
                                             }
                                             
                                     }
                             else if(DP[x][j - 1].Value == TmpMin && cmpPath(TmpP, DP[x][j - 1].Path, j - 1)){
                                  v = x;
                                  for(int p = 1; p <= j - 1; p++){
                                          TmpP[p] = DP[x][j - 1].Path[p];
                                          }
                                  }
                             }
                     DP[i][j].Value = TmpMin + C[i][j];
                     DP[i][j].Parent = v;
                     for(int p = 1; p <= j - 1; p++){
                             DP[i][j].Path[p] = TmpP[p];
                             }
                     DP[i][j].Path[j] = i;
                     }
             }
     }
     
                   
void findAns2(){
     Ans = INF;
     int TmpP[MAXN];
     for(int i = 1; i <= M; i++){
             if(DP[i][N].Value < Ans){
                               Ans = DP[i][N].Value;
                               for(int p = 1; p <= N; p++){
                                       TmpP[p] = DP[i][N].Path[p];
                                       }
                               }
             else if(DP[i][N].Value == Ans && cmpPath(TmpP, DP[i][N].Path, N)){
                  for(int p = 1; p <= N; p++){
                          TmpP[p] = DP[i][N].Path[p];
                          }
                  }
             }
     for(int p = 1; p <= N; p++){
             PathAns[p] = TmpP[p];
             }
     }

void printResult(){
     for(int i = 1; i <= N; i++){
             if(i > 1) printf(" ");
             printf("%d",PathAns[i]);
             }
     printf("\n");
     printf("%d\n",Ans);
     }
     
void PrintPath(int i, int j){
     for(int t = 1; t <= j; t++) printf("%d ",DP[i][j].Path[t]);
     printf("V = %d\n",DP[i][j].Value);
     }     


int main () {
    //freopen("116.INP", "r", stdin); freopen("116.OUT", "w", stdout);
    while(scanf("%d%d",&M,&N) != EOF){
          for(int i = 1; i <= M; i++){
                  for(int j = 1; j <= N; j++){
                          scanf("%d",&C[i][j]);
                          }
                  }   
          runDP(); 
          findAns2(); 
          printResult();              
          }
    
    return 0;
    }
