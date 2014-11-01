/*
  Name: UVa 10656 Maximum Sum (II)
  Copyright: 
  Author: 3T
  Date: 01/11/10 15:57
  Description: ad hoc
*/
#include <stdio.h>

int N, a, First, M[1005];

int main () {
   // freopen("10656.INP", "r", stdin);
   // freopen("10656.OUT", "w", stdout);
    while(scanf("%d",&N) && N){
         First = 0;
         for(int i = 1; i <= N; i++){
                 scanf("%d",&M[i]);
                 }
          for(int i = 1; i <= N; i++){       
                 if(M[i]){
                       First++;
                       if(First == 1) printf("%d", M[i]);
                       else printf(" %d",M[i]);
                       }
                 }        
         if(!First) printf("0");
         printf("\n");
         }
    return 0;
    }
