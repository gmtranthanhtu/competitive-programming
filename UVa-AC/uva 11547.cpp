#include <stdio.h>

int main () {
    int T,N;
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            scanf("%d",&N);
            N = 315 * N + 36962;
            N = (N > 0) ? N : N * -1; 
            N = N % 100;
            N = N / 10;
            printf("%d\n",N);
            }
    return 0;
    }
