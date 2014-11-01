#include <stdio.h>

main () {
     int n,f,i,j,a,b,c;
     long sum;
     scanf("%d",&n);
     for(i = 1; i <= n; i++){
           scanf("%d",&f);
           sum = 0;
           for(j = 1; j <= f; j++){
                 scanf("%d%d%d",&a,&b,&c);
                 sum += a*c;
                 }
           printf("%ld\n",sum);
           }
     }
