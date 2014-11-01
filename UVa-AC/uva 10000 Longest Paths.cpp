/*
  Name: UVa 10000 Longest Paths
  Copyright: 
  Author: 3T
  Date: 22/09/10 01:30
  Description: Floyd, longest path, print two endl after each test case
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
#define SMALL -100000000

int n, s, a, b,Case(1), Index, L;
int M[105][105];

bool No(int s){
     for(int i = 1; i <= n; i++){
             if(i != s){
                  if(M[s][i] != SMALL) return false;
                  }
             }
     return true;
     }

int main () {
    while(scanf("%d",&n) && n){
         scanf("%d",&s);
         for(int i = 1; i <= n; i++){
                 for(int j = 1; j <= n; j++){
                         M[i][j] = SMALL;
                         }
                 }
         while(scanf("%d%d",&a,&b)){
                       if(a == 0 && b == 0) break;
                        M[a][b] = 1;                               
                       }            
         if(No(s)){
                   //if(Case > 1) printf("\n");
                   printf("Case %d: The longest path from %d has length 0, finishing at %d.\n\n",Case++,s,s);
                   continue;
                   }    
         else{
              for(int i = 1; i <= n; i++){
                      for(int j = 1; j <= n; j++){
                              for(int k = 1; k <= n; k++){
                                      if(i != j && j != k){
                                           M[j][k] = max(M[j][i] + M[i][k], M[j][k]);
                                           }
                                      }
                              }
                      }
              L = SMALL;
              for(int i = 1; i <= n; i++){
                      if(M[s][i] > L){
                                 L = M[s][i];
                                 Index = i;
                                 }
                      else if(M[s][i] == L && i < Index){
                           Index = i;
                           }
                      }
              //if(Case > 1) printf("\n");
              printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",Case++,s,L,Index);
              }
         }
    return 0;
    }
