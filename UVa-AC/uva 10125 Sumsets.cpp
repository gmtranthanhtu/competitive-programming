/*
  Name: UVa 10125 Sumsets
  Copyright: 
  Author: 3T
  Date: 02/11/10 08:55
  Description: brute force, (need optimizing later) 
*/
#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 536870950

int N;
int M[1005];

int findSum(){
    if(N <= 3) return INF;
    for(int i = N; i >= 1; i--){
            for(int j = N; j >= 1; j--){
                    for(int k = N; k >= 1; k--){
                            for(int m = N; m >= 1; m--){
                                    if(m == k || k == j ||  j == i || m == j || m == i || k == i) continue;
                                    if(M[m] + M[k] + M[j] == M[i]) return M[i];
                                    }
                            }
                    }
            }
    return INF;
    }

int main () {
    while(scanf("%d",&N) && N){
          for(int i = 1; i <= N; i++) scanf("%d",&M[i]);
          sort(M + 1, M + N + 1);
          int R = findSum();         
          if(R == INF) printf("no solution\n");
          else printf("%d\n",R);      
          }
    
    return 0;
    }
