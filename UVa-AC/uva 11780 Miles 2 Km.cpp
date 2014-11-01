#include <stdio.h>
#include <stdlib.h>

int N,n;

int main () {
    while(scanf("%d",&N)){
                          if (N == 0) return 0;
//                         n = N % 5;
//                         if(n == 0) printf("0.00\n");
//                         else if(n == 1) printf("0.40\n");
//                         else if(n == 2) printf("0.20\n");
//                         else if(n == 3) printf("0.20\n");
//                         else if(n == 4) printf("0.40\n");
switch (N % 5){
       case 1: printf("0.40\n");break;
       case 2: printf("0.20\n");break;
       case 3: printf("0.20\n");break;
       case 4: printf("0.40\n");break;
       default: printf("0.00\n");break;
       }
       
                         }    
    return 0;
    }
