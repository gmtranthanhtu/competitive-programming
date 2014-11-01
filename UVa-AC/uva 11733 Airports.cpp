/*
  Name: UVa 11733 Airports
  Copyright: 
  Author: 3T
  Date: 06/07/10 16:28
  Description: Kruscal
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAXN 10005
#define MAXE 100005
#define INP "11733.INP"

typedef struct Edge{
        int s1,s2,w;
        bool Marked;
        };
Edge Ed[MAXE];
int n,m,Lab[MAXN],a,b,T,A,c,mm,NumE,NumA,Cost;


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

void AdjustHeap(int root, int last){
     Edge Key;
     int child;
     
     Key = Ed[root];
     while (root * 2 <= last){
           child = root * 2;
           if(child < last && Ed[child + 1].w < Ed[child].w) child++;
           if(Key.w <= Ed[child].w) break;
           Ed[root] = Ed[child];
           root = child;
           }
     Ed[root] = Key;
     }

int main(){
//    FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    fscanf(f,"%d",&T);
    for(int t = 1; t <= T; t++){
          fscanf(f,"%d%d%d",&n,&m,&A);
          mm = 1;    
          NumE = n - 1; //an ordinary MST will have this number of edge
          Cost = 0;
          for(int i = 1; i <= m; i++){
                  fscanf(f,"%d%d%d",&a,&b,&c);
                  if( c < A){ //if building roads cost >= airport construction cost, we should build an airport
                       Ed[mm].s1 = a;
                       Ed[mm].s2 = b;
                       Ed[mm].w = c;
                       mm++;
                       Ed[i].Marked = false;
                       }
                  }
          mm--;
          //Init
          for(int i = 1; i <= n; i++) Lab[i] = -1;
//          for(int i = 1; i <= mm; i++) Ed[i].Marked = false;
          
                  
          //Kruscal
          int Count = 0;
          Edge Temp;
          for(int i = mm / 2; i >= 1; i--) AdjustHeap(i,mm);
          for(int i = mm - 1; i >= 0; i--){
                  Temp = Ed[1]; Ed[1] = Ed[i + 1]; Ed[i + 1] = Temp;
                  AdjustHeap(1,i); 
                  int r1 = GetRoot(Ed[i + 1].s1);
                  int r2 = GetRoot(Ed[i + 1].s2);
                  if(r1 != r2){
                        Ed[i + 1].Marked = true;
                        Count++;
                        Union(r1, r2);
                        Cost += Ed[i + 1].w;
                        }
                  }

          if(Count != NumE){
          NumA = (NumE - Count + 1);} //with (NumE - Count) lost, the MST will be divided into (NumE - Count) + 1 connected components
                                      //so that we add (NumE - Count) + 1 airports
          else NumA = 1; 
          Cost += (NumA * A);
          printf("Case #%d: %d %d\n",t,Cost,NumA);               
          }
//   getchar();
    return 0;
    }
