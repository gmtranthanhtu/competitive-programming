/*
  Name: UVa 10462 Is there a second way?
  Copyright: 
  Author: 3T
  Date: 29/06/11 21:46
  Description: Kruscal, 2nd minimum spanning tree
*/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define MAXNODE 110
#define MAXEDGE 210
#define INF 1000000000

typedef struct Edge{
        int s1,s2,w;
        bool Marked;
        };
        
Edge Ed[MAXEDGE];
int n,m,Lab[MAXNODE],a,b,T,Count,SecWay, Cost;
bool Connected;
bool Mark2[MAXEDGE];

int GetRoot(int v){
     while(Lab[v] > 0) {v = Lab[v];}
     return v;
     }
     
void Union(int r1, int r2){
     int x = Lab[r1] + Lab[r2];
     if(Lab[r1] > Lab[r2]){
                   Lab[r1] = r2;
                   Lab[r2] = x;
                   }
     else{
          Lab[r1] = x;
          Lab[r2] = r1;
          }
     }
     
void runKruscal(){
          //Kruscal
          Count = 0;
          Connected = false;
          for(int i = 1; i <= m; i++){
                  int r1 = GetRoot(Ed[i].s1);
                  int r2 = GetRoot(Ed[i].s2);
                  if(r1 != r2){
                        Ed[i].Marked = true;
                        Count++;
                        if(Count == n - 1){
                                 Connected = true;
                                 return;
                                 }
                        Union(r1, r2);
                        }               
                  }     
     }
     
void runKruscal2(int Forbi){
     for(int i = 1; i <= n; i++) Lab[i] = -1;
     for(int i = 1; i <= m; i++) Mark2[i] = false;     
     Count = 0;
     Connected = false;
     
      for(int i = 1; i <= m; i++){
              if(i == Forbi) continue;
              int r1 = GetRoot(Ed[i].s1);
              int r2 = GetRoot(Ed[i].s2);
              if(r1 != r2){
                    //Ed[i].Marked = true;
                    Mark2[i] = true;
                    Count++;
                    if(Count == n - 1){
                             Connected = true;
                             return;
                             }
                    Union(r1, r2);
                    }               
              }     
     }
     
int getWeight(){
    int R = 0;
    for(int i = 1; i <= m; i++){
            if(Mark2[i]) R += Ed[i].w;
            }
    return R;
    }
     
int Cal(){
    int R = INF;
    for(int i = 1; i <= m; i++){
            if(Ed[i].Marked){
                             runKruscal2(i);
                             if(!Connected) continue;
                             int Tmp = getWeight();
                             R = min(R, Tmp);
                             }
            }
    return R;
    }

int main() {
    //freopen("10462.INP", "r", stdin); freopen("10462.OUT", "w", stdout); 
    scanf("%d",&T);
    for(int t = 1; t <= T; t++){
            scanf("%d%d",&n,&m);
            for(int i = 1; i <= m; i++){
                    scanf("%d%d%d",&Ed[i].s1, &Ed[i].s2, &Ed[i].w);
                    }
          //print
          printf("Case #%d : ",t);
          if(m == 0){
               if(n == 1){
                    printf("No second way\n");
                    }
               else printf("No way\n");
               continue;
               }  
          //Init
          for(int i = 1; i <= n; i++) Lab[i] = -1;
          for(int i = 1; i <= m; i++) Ed[i].Marked = false;
          
          //Re-sort
          for(int i = m; i >= 2; i--){
                  for(int j = 1; j <= i - 1; j++){
                          if(Ed[j].w > Ed[i].w){
                                     swap(Ed[j],Ed[i]);
                                     }
                          }
                  } 
            
          //Kruscal
            runKruscal();
            if(!Connected) {printf("No way\n"); continue;}
            
            Cost = Cal();
            if(Cost == INF) {printf("No second way\n"); continue;}
            
            printf("%d\n",Cost);         
            }
    return 0;
    }
