/*
  Name: UVa 11267 The Hire-a-coder business model
  Copyright: 
  Author: 3T
  Date: 29/06/11 23:29
  Description: Kruscal
*/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXNODE 210
#define MAXEDGE 11005
#define INF 1000000000

typedef struct Edge{
        int s1,s2,w;
        bool Marked;
        };
        
Edge Ed[MAXEDGE];
int n,m,Lab[MAXNODE],a,b,c,T,Count,SecWay, Cost;
bool Connected, Smart;
int Buy[MAXNODE];



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
     
    

int main() {
    //freopen("11267.INP", "r", stdin); freopen("11267.OUT", "w", stdout); 
    while(scanf("%d",&n) && n){
        //gen
        for(int i = 1; i <= n; i++) Buy[i] = 0;
        Smart = true;
        scanf("%d",&m);
        for(int i = 1; i <= m; i++){
             scanf("%d%d%d",&a, &b, &c);
             if(Buy[a] == -1 || Buy[b] == 1) Smart = false;
             if(!Smart) continue;
             Buy[a] = 1;
             Buy[b] = -1;
             Ed[i].s1 = a; Ed[i].s2 = b; Ed[i].w = c;
             }  
        if(!Smart){
                    printf("Invalid data, Idiot!\n");
                    continue;
                    }       
        //printf("Processing\n"); 
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
            if(!Connected){
                           printf("Invalid data, Idiot!\n");
                           continue;
                           }      
            int Sum = 0;
            for(int i = 1; i <= m; i++){
                    if(Ed[i].Marked || Ed[i].w < 0) Sum += Ed[i].w;
                    }      
            printf("%d\n",Sum);           
        }
    return 0;
    }
