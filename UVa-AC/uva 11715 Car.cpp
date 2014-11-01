#include <stdio.h>
#include <math.h>

double a,b,c,d,e;

int main () {
    int n, Case(1);
    while(scanf("%d",&n) && n){
         scanf("%lf%lf%lf",&a,&b,&c);
         if(n == 1){
              e = (b - a) / c;
              d = (b * b - a * a) / (2 * e);
              }
         else if(n == 2){
              e = (b - a) / c;
              d = (b * b - a * a) / (2 * c);
              }                
         else if(n == 3){
              d = sqrt(2 * b * c + a * a);
              e = (d - a) / b;
              }
         else if(n == 4){
              d = sqrt(  a * a - 2 * b * c);
              e = (a - d) / b;
              }
         printf("Case %d: %.3lf %.3lf\n", Case++, d, e);
         }
    
    return 0;
    }
