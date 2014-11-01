/*
  Name: UVa 10297 Beavergnaw
  Copyright: 
  Author: 3T
  Date: 28/08/10 22:08
  Description: Geometry, area, frustum of a cone, cylinder
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const double MyPi = 2 * acos(0.0);
double D,V,d;

int main () {
    FILE *f = stdin;
    while(fscanf(f,"%lf %lf",&D,&V) && D){
           d = pow(D * D * D - 6 * V / MyPi, 1.0 / 3);
           printf("%.3lf\n",d);              
           }
    return 0;
    }
