/*
  Name: UVa 11805 Bafana Bafana
  Copyright: 
  Author: 3T
  Date: 28/06/10 15:48
  Description: 
*/
#include <stdio.h>
#include <stdlib.h>

int main () {
    int T,N,K,P,result;
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            scanf("%d%d%d",&N,&K,&P);
            if(P == N) result = K;
            else if(P < N){
                 result = K - (N - P);
                 if(result <= 0) result += N;
                 }
            else{
                 int k = P % N;
                 if(k == N) result = K;
            else if(k < N){
                 result = K - (N - k);
                 if(result <= 0) result += N;
                 }
                 }
            printf("Case %d: %d\n",i,result);
            }
    return 0;
    }
