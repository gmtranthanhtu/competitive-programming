#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;
double xg, yg, xd, yd, xh, yh, xch, ych;
bool Can;

void Calc(){
     if(2.0 * hypot(xg - xh, yg - yh) <= hypot(xd - xh, yd - yh)){
                 Can = true;
                 xch = xh;
                 ych = yh;
                 }
     else Can = false;
     }

int main (){
    while(scanf("%d %lf %lf %lf %lf", &n, &xg, &yg, &xd, &yd) != EOF){
           Can = false;
           for(int i = 1; i <= n; i++){
                   scanf("%lf %lf",&xh, &yh);
                   if(!Can) Calc();    
                   }     
           if(Can) printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",xch,ych);    
           else printf("The gopher cannot escape.\n");
           }
    return 0;
    }
