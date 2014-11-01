/*
  Name: UVa 11848 Cargo Trains
  Copyright: 
  Author: 3T
  Date: 20/09/10 16:57
  Description: Dijsktra
*/
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX 105
#define BIG 1999999999

int n, ma, mb, k, a, b, c;
int A[MAX][MAX], B[MAX][MAX];
double M[MAX][MAX], t, d[MAX]; 
bool Free[MAX];

double Dijsktra(){
       for(int i = 0; i < n; i++) {d[i] = BIG; Free[i] = true;}
       d[0] = 0.0;
       int u, v;
       double Min;
       do{
           u = -1;
           Min = BIG;
           for(int i = 0; i < n; i++){
                   if(Free[i] && d[i] < Min){
                              Min = d[i];
                              u = i;
                              }
                    }
                   if(u == -1 || u == n - 1) break;
                   Free[u] = false;
                   for(v = 0; v < n; v++){
                         if(Free[v] && d[v] > d[u] + M[u][v]){
                                    d[v] = d[u] + M[u][v];
                                    }
                         }
           }while(1);
           
       return d[n - 1];
       }

int main (){
    while(scanf("%d%d%d%d",&n,&ma,&mb,&k)){
         if(n == -1 && ma == -1 && mb == -1 && k == -1) break;
         for(int i = 0; i < n; i++){
                 for(int j = 0; j < n; j++){
                         A[i][j] = BIG;
                         B[i][j] = BIG;
                         }
                 A[i][i] = 0;
                 B[i][i] = 0;
                 }           
         for(int i = 1; i <= ma; i++){
                 scanf("%d%d%d",&a,&b,&c);
                 A[a][b] = A[b][a] = c;
                 }       
         for(int i = 1; i <= mb; i++){
                 scanf("%d%d%d",&a,&b,&c);
                 B[a][b] = B[b][a] = c;
                 } 
                 
         for(int i = 1; i <= k; i++){
                 scanf("%lf",&t);
                 for(int j = 0; j < n; j++){
                         for(int l = 0; l < n; l++){
                                 if(A[j][l] == BIG && B[j][l] == BIG) M[j][l] = BIG;
                                 else if(A[j][l] == BIG) M[j][l] = B[j][l];
                                 else if(B[j][l] == BIG) M[j][l] = A[j][l];
                                 else M[j][l] = t * A[j][l] + (1 - t) * B[j][l];
                                 }
                         }
                 //printf("duoc");
                 double Tmp = Dijsktra();
                 int R = (int) Tmp;
                 printf("%d\n",R);
                 }                
         }
    
    return 0;
    }
