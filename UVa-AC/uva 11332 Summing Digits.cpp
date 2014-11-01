#include <stdio.h>

int n, r;

int main () {
    while(scanf("%d",&n) && n){
          while(n >= 10){
                  r = 0;
                  while(n >= 10){
                          r += n % 10;
                          n = n / 10;
                          }
                  r += n;
                  n = r;
                  }
          printf("%d\n",n);               
          }
    return 0;
    }
