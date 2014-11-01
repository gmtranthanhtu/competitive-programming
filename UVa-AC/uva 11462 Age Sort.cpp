/*
  Name: UVa 11462 Age Sort
  Copyright: 
  Author: 3T
  Date: 28/10/10 08:36
  Description: ad hoc
*/
#include <stdio.h>
#include <stdlib.h>
int main () {
    int i, j, n, Count;
    int M[2000005];
    while(scanf("%d",&n) && n){
         for(i = 1; i <= n; i++){
               scanf("%d",&M[i]);
               }                
         Count = 0;
         for(i = 1; i <= 100; i++){
               for(j = 1; j <= n; j++){
                     if(M[j] == i){
                             if(Count == 0) printf("%d", i);
                             else printf(" %d", i);
                             Count++;
                             }
                     if(Count == n) break;
                     }
               }
         printf("\n");
         }
    
    
    return 0;
    }
