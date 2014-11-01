#include <stdio.h>
#include <math.h>

double p, a, b, c, Area;

int main () {
    while(scanf("%lf %lf %lf",&a, &b, &c) == 3){
          p = (a + b + c) / 2;
          Area = p * (p - a) * (p - b) * (p - c);
          if(Area <= 0) Area = -1;
          else if(a <= 0 || b <= 0 || c <= 0) Area = -1;
          else{
               Area = sqrt(Area);
               Area = 4 * Area / 3;
               }           
          printf("%.3lf\n",Area);
          }
    return 0;
    }
