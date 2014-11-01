/*
  Name: UVa 193 Graph Coloring
  Copyright: 
  Author: 3T
  Date: 23/07/11 16:37
  Description: backtracking
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define INF 999999999
#define MAXN 105
#define BLACK 2
#define WHITE 1

int T, C[MAXN][MAXN], N, K, a, b, Color[MAXN], Ans, ColorAns[MAXN];

bool Valid(int Node, int Co){
     if(Co == WHITE) return true;
     for(int i = 1; i <= N; i++){
             if(C[Node][i] != 1) continue;
             if(Color[i] == BLACK) return false;
             }
     return true;
     }
     
void updateResult(){
     int Sum = 0;
     for(int i = 1; i <= N; i++){
             if(Color[i] == BLACK) Sum++;
             }
     if(Sum > Ans){
            Ans = Sum;
            for(int i = 1; i <= N; i++) ColorAns[i] = Color[i];
            }
     }

void runBacktrack(int u){
     if(u > N) return;
     for(int i = 1; i <= 2; i++){
             if(!Valid(u, i)) continue;
             Color[u] = i;
             if(u == N) updateResult();
             runBacktrack(u + 1);
             Color[u] = 0;
             }
     }

int main(){
    //freopen("193.INP", "r", stdin); freopen("193.OUT", "w", stdout);
    scanf("%d",&T);
    while(T--){
               scanf("%d%d",&N,&K);
               memset(C, 0, sizeof C);
               for(int i = 1; i <= K; i++){
                       scanf("%d%d",&a,&b);
                       C[a][b] = C[b][a] = 1;
                       }
               Ans = -INF;        
               memset(Color, 0, sizeof Color);
               runBacktrack(1);
               printf("%d\n",Ans);
               int a = 0;
               for(int i = 1; i <= N; i++){
                       if(ColorAns[i] == BLACK){
                                      if(a > 0) printf(" ");
                                      printf("%d",i);
                                      a++;
                                      }
                       }
               printf("\n");
               }
    
    return 0;
    }
