/*
  Name: UVa 11792 Krochanska is here
  Copyright: 
  Author: 3T
  Date: 30/06/11 03:05
  Description: BFS with danh sach ke
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define MAXNODE 10005
#define MAXS 105
#define INF 100000000

int N, S, T, Tmp, Pre, a, INum, Ans, Min;
int Impo[MAXNODE], Impo2[MAXS], ImpoV[MAXS], Cost[MAXNODE];
vector <int> Edge[MAXNODE];

int Cal(int Cur){
    for(int i = 1; i <= N; i++){
            Cost[i] = INF;
            }
    Cost[Cur] = 0;
    queue <int> q;
    q.push(Cur);
    
    while(!q.empty()){
         int p = q.front();
         q.pop();
         
         for(size_t i = 0; i < Edge[p].size(); i++){
                    if(Cost[Edge[p].at(i)] == INF){
                            Cost[Edge[p].at(i)] = Cost[p] + 1;
                            q.push(Edge[p].at(i));              
                            }
                    }             
         }
    int R = 0;
    for(int i = 1; i <= INum; i++){
            R += Cost[Impo2[i]];
            }
    return R;
    }


int main () {
    //freopen("11792.INP", "r", stdin); freopen("11792.OUT", "w", stdout);
    scanf("%d",&T);
    for(int t = 1; t <= T; t++){
            scanf("%d%d",&N,&S);
             memset(Impo, 0, sizeof Impo);
             for(int i = 1; i <= N; i++) Edge[i].clear();
                    
            Tmp = 0;
            while(Tmp < S){
                      Pre = 0;
                      while(scanf("%d",&a) && a){
                                           Impo[a]++;
                                           if(Pre != 0){
                                                  Edge[Pre].push_back(a);
                                                  Edge[a].push_back(Pre);
                                                  }
                                           Pre = a;
                                           }
                      Tmp++;
                      } 
 
             INum = 0;
             for(int i = 1; i <= N; i++){
                     if(Impo[i] > 1){
                                INum++;
                                Impo2[INum] = i;
                                }
                     }
             //cout << INum; 
             Min = INF;
             for(int i = 1; i <= INum; i++){
                     int c = Cal(Impo2[i]);
                     if(c < Min){
                          Min = c;
                          Ans = Impo2[i];
                          }
                     }
             printf("Krochanska is in: %d\n",Ans);               
             }
    return 0;
    }
