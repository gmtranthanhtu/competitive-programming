#include <stdio.h>

int main () {
    int n, k, total;
    while(scanf("%d%d",&n, &k) != EOF){
         total = n;
         while(n >= k){
                 total += n / k;
                 n = n / k + n % k;
                 }      
          printf("%d\n",total);            
         }
    return 0;
    }
