#include <stdio.h>
#include <math.h>

int N, T;

void getFac(){
     int ans = 0;
     for(int i = 2; i * i <= N && ans < 2; i++){
             if(N % i == 0){
                  printf("%d * %d", i, N / i);
                  ans++;
                  if(ans == 1) printf(" = ");
                  }
             }
     }

int main () {
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            scanf("%d",&N);
            printf("Case #%d: %d = ",i,N);
            getFac();
            printf("\n");
            }
    return 0;
    }
