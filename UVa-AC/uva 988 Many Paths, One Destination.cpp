/*
  Name: UVa 988 Many Paths, One Destination
  Copyright: 
  Author: 3T
  Date: 24/07/11 04:18
  Description: DP, Topo sort
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 15000

vector<int> V[MAXN];

int N, DP[MAXN], n, a, t, End[MAXN], Sum, stupidline = 0, List[MAXN], Count;
bool Free[MAXN];
     
void runDP2(){
     memset(DP, 0, sizeof DP);
     DP[0] = 1;
     for(int i = 0; i < N; i++){
            for(int j = 0; j < V[List[i]].size(); j++)                         
                DP[V[List[i]][j]] += DP[List[i]];
             }
     }
    
void Visit(int u){
     Free[u] = false;
     for(int i = 0; i < V[u].size(); i++){
             if(Free[V[u][i]]) Visit(V[u][i]);
             }
     List[Count] = u;
     Count--;
     }

void runTopo(){
     memset(Free, true, sizeof Free);
     Count = N - 1;
     for(int i = 0; i < N; i++) if(Free[i]) Visit(i);
     }


int main () {
    //freopen("988.INP", "r", stdin); freopen("988.OUT", "w", stdout);
    while(scanf("%d",&N) != EOF){
          for(int i = 0; i < N; i++) V[i].clear();
          t = 0;
          Sum = 0;
          for(int i = 0 ; i < N; i++){
                  scanf("%d",&n);
                  if(n == 0){
                       t++;
                       End[t] = i;
                       }
                  for(int j = 1; j <= n; j++){
                          scanf("%d",&a);
                          V[i].push_back(a);
                          }
                  }                 
          runTopo();
          runDP2();
          for(int i = 1; i <= t; i++){
                  Sum += DP[End[i]];
                  }
          
          if(stupidline > 0) printf("\n");
          stupidline++;
          printf("%d\n",Sum);  
          }
    
    return 0;
    }
