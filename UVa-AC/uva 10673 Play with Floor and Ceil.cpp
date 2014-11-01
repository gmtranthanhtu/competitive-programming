#include <stdio.h>

int t, x, k, i, q, p;

int main (){
    scanf("%d",&t);
    for(i = 1; i <= t; i++){
          scanf("%d%d",&x,&k);
          //printf("0 %d\n",k);
          q = x % k;
          p = k - q;
          printf("%d %d\n",p,q);
          }
    return 0;
    }
