#include <stdio.h>
#include <math.h>

double N,a,dx;

int main () {
    FILE *f = stdin;
    while(fscanf(f,"%lf",&N) && N){
         a = pow(N,1.0/3);
         a = floor(a);
         if((a + 1) * (a + 1) * (a + 1) <= N) a++;
         dx = (N - a * a * a)/(a * a * 3);
         printf("%.4lf\n",a + dx); 
                             
         }
    return 0;
    }
