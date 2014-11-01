/*
  Name: UVa 10209 Is this Integration
  Copyright: 
  Author: 3T
  Date: 27/08/10 17:17
  Description: Geometry
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double MyPi = 2 * acos(0);

double a,x,y,z;

int main () {
    FILE *f = stdin;
    while(fscanf(f,"%lf",&a) != EOF){
         if(!a){
                x = y = z = 0.0;
                }
         else{
              z = (1 - MyPi / 6.0 - sqrt(3) / 4) * a * a;
              y = a * a * (1 - MyPi / 4) - 2 * z;
              x = a * a - 4 * y - 4 * z;
              z = 4 * z;
              y = 4 * y;
              }
         printf("%.3lf %.3lf %.3lf\n",x,y,z);                    
         }
    return 0;
    }
