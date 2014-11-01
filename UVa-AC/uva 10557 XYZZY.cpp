/*
  Name: UVa 10557 XYZZY
  Copyright: 
  Author: 3T
  Date: 01/09/10 03:21
  Description: Graph
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INP "10557.INP"
#define BIG 100000000
#define MAX 9910
#define MAXN 105
#define LOOP 25000

typedef struct Node{
        int Energy, Pos;
        };
Node No[MAXN];

typedef struct Edge{
       int u, v;
       };
Edge Ed[MAX];
int N, k;

bool runLoop(){
     for(int i = 2; i <= N; i++){
             No[i].Energy = BIG;
             }
     No[1].Energy = -100;
     for(int i = 1; i <= LOOP; i++){
             for(int j = 1; j <= k; j++){
                     int u = Ed[j].u;
                     int v = Ed[j].v;
                     if(No[u].Energy >= 0) continue;
                     No[v].Energy = min(No[v].Energy, No[u].Energy + No[v].Pos);
                     if(No[N].Energy < BIG) return true;
                     }
             }
     return false;
     }


int main(){
   // FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    while(fscanf(f, "%d", &N) && N != -1){
          k = 1;
          for(int i = 1; i <= N; i++){
                  fscanf(f,"%d",&No[i].Pos);
                  No[i].Pos *= -1;
                  int v, j;

                  fscanf(f,"%d",&j);
                  while(j--){
                             fscanf(f,"%d",&v);
                             Ed[k].u = i;
                             Ed[k++].v = v;
                             }
                  }
          k--;
          No[N].Pos = No[1].Pos = 0;
          printf("%s\n",runLoop() ? "winnable" : "hopeless");          
          }
    //getchar();
    return 0;
    }
