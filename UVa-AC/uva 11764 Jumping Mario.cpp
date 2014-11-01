#include <stdio.h>

int main () {
    int N, H, L,a,b,T;
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
            H = L = 0;
            scanf("%d",&T);
            scanf("%d",&a);
            if(T == 1){
                 printf("Case %d: 0 0\n", i);
                 }
            else{
                 for(int j = 2; j <= T; j++){
                         scanf("%d",&b);
                         if(b > a) H++;
                         else if (b < a) L++;
                         a = b;
                         }
                 printf("Case %d: %d %d\n",i,H,L);
                 }
            }
    return 0;
    }
