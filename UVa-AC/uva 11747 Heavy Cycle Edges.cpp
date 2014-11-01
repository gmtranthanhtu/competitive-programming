/*
  Name: UVa 11747 Heavy Cycle Edges
  Copyright: 
  Author: 3T
  Date: 05/07/10 20:15
  Description: Kruscal
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 1005
#define MAXE 499505
#define INP "11747.INP"

typedef struct Edge{
        int s1,s2,w;
        bool Marked;
        };
Edge Ed[MAXE];
int n,m,Lab[MAXN],a,b;
queue <int> Q;

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

int main(){
//    FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    while(fscanf(f,"%d%d",&n,&m) && n){
          for(int i = 1; i <= m; i++){
                  fscanf(f,"%d%d%d",&a,&b,&Ed[i].w);
                  Ed[i].s1 = a + 1;
                  Ed[i].s2 = b + 1;
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
          int Count = 0;
          for(int i = 1; i <= m; i++){
                  int r1 = GetRoot(Ed[i].s1);
                  int r2 = GetRoot(Ed[i].s2);
                  if(r1 != r2){
                        Ed[i].Marked = true;
                        Count++;
                        Union(r1, r2);
                        }
                  else{ Q.push(Ed[i].w);}                  
                  }
          if(Q.empty()) printf("forest\n");
          else{
               int si = Q.size();
               if(si == 1){
                     printf("%d\n",Q.front());
                     Q.pop();
                     }
               else{
                    printf("%d",Q.front());
                    Q.pop();
                    while(!Q.empty()){
                                      printf(" %d",Q.front());
                                      Q.pop();
                                      }
                    printf("\n");
                    }
               }                 
          }
//    getchar();
    return 0;
    }
