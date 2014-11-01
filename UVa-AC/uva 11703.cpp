#include <stdio.h>
#include <math.h>
#include <string.h>

int i;
int DP[1000005];
   
int getDP(int i){
    if(DP[i] != -1) return DP[i];
    else{
         if(i == 0) return 1;
         long Tmp = getDP((int)i - sqrt(i)) + getDP((int)log(i)) + getDP((int)(i * sin(i) * sin(i)));
         DP[i] = Tmp % 1000000;
         return DP[i];
         }
    }

int main(){
     for(int i = 0; i <= 1000000; i++) DP[i] = -1;
    while(scanf("%d",&i) && i != -1){
            printf("%d\n", getDP(i));             
            }
    return 0;
    }
