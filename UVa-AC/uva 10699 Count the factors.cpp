#include <stdio.h>

int N, Ans;

int Count(){
    int Tmp = N;
    int C = 0;
    for(int i = 2; i * i <= Tmp; i++){
            if(Tmp % i == 0){
                   C++;
                   while(Tmp % i == 0) Tmp /= i;
                   }
            }
    if(Tmp > 1) C++;
    return C;
    }

int main () {
    while(scanf("%d",&N) && N){
             printf("%d : %d\n",N, Count());            
             }
    return 0;
    }
