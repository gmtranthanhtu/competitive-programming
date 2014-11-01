#include <stdio.h>

int n, P, N, So[50];

void findParity(){
     P = 0;
     n = 0;
     while(N > 0){
             int Tmp = N % 2;
             if(Tmp) P++;
             n++;
             So[n] = Tmp;
             N /= 2;
             }
     }

int main () {
    while(scanf("%d",&N) && N){
           findParity();
           printf("The parity of ");             
           for(int i = n; i >= 1; i--) printf("%d",So[i]);
           printf(" is %d (mod 2).\n",P); 
           }
    return 0;
    }
