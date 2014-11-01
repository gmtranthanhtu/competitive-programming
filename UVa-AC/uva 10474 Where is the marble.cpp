/*
  Name: UVa 10474 Where is the marble
  Copyright: 
  Author: 3T
  Date: 13/11/10 15:36
  Description: DandC, binary search
*/
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX 10000

int Case(1), N, Q, M[MAX + 5], Qu[MAX + 5];

int binarySearch(int m){
    int S, E, Median;
    S = 1;
    E = N;
    while(S <= E){
            if(S == E){
                 if(M[S] == m) return S;
                 }
            Median = (S + E) / 2;
            if(M[Median] == m){
                         E = Median;
                         continue;
                         }
            if(M[Median] < m){
                         S = Median + 1;
                         }
            else E = Median - 1;
            }
    return 0;
    }

int main () {
    while(scanf("%d%d",&N, &Q)){
         if(N == 0 && Q == 0) break;
         for(int i = 1; i <= N; i++){
                 scanf("%d",&M[i]);
                 }                 
         sort(M + 1, M + N + 1);
         for(int i = 1; i <= Q; i++){
                 scanf("%d",&Qu[i]);
                 } 
         printf("CASE# %d:\n",Case++);
         for(int i = 1; i <= Q; i++){
                 int Tmp = binarySearch(Qu[i]);
                 if(!Tmp) printf("%d not found\n",Qu[i]);
                 else printf("%d found at %d\n",Qu[i], Tmp);
                 }
         }
    
    return 0;
    }
