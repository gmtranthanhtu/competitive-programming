#include <stdio.h>
#include <math.h>

int main () {
    double Ans, n, p;
    while(scanf("%lf %lf", &n, &p) == 2){
                     Ans = pow(p, 1/n);
                     printf("%.0lf\n",Ans);
                     }
    
    return 0;
    }
