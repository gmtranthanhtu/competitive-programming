/*
  Name: UVa 10305 Odering Task
  Copyright: 
  Author: 3T
  Date: 14/09/10 01:56
  Description: Topology Sorting
*/
#include <stdio.h>
#include <stdlib.h>

int m, n, a, b, Count;
int C[110][110], List[110];
bool Free[110];

void Visit(int u){
     Free[u] = false;
     for(int v = 1; v <= n; v++){
             if(Free[v] && C[u][v]) Visit(v);
             }
     List[Count--] = u;
     }

void topoNumbering(){
     Count = n;
     for(int i = 1; i <= n; i++){
             if(Free[i]) Visit(i);
             }
     }

int main () {
    while(scanf("%d%d", &n, &m) && n){
          for(int i = 1; i <= n; i++){
                  Free[i] = true;
                  for(int j = 1; j <= n; j++){
                          C[i][j] = 0;
                          }
                  }
          for(int i = 1; i <= m; i++){
                  scanf("%d%d",&a, &b);
                  C[a][b] = 1;
                  }
          topoNumbering();  
        //  if(n == 1) printf("%d\n",List[1]);
          if(n == 1){
               printf("%d\n",List[1]);
               continue;
               }
          for(int i = 1; i < n; i++){
                  printf("%d ",List[i]);
                  }            
          printf("%d\n",List[n]);
          }
    return 0;
    }
