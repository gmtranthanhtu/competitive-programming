/*
  Name: UVa 10432 Polygon inside a circle
  Copyright: 
  Author: 3T
  Date: 14/09/10 19:17
  Description: Geometry
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double MyPi = 2 * acos(0);
double r, n, Area, Anglea, Angleb, t;

int main () {
    while(scanf("%lf %lf",&r,&n) != EOF){
            Anglea = (n - 2) * 180.0 / n;
            Angleb = 180 - Anglea;
            Anglea = Anglea / 2.0;
            t = r / sin(MyPi * Anglea / 180.0) * sin(MyPi * Angleb / 180.0);
            Area = n * t * t / (4 * tan(MyPi / n));
            printf("%.3lf\n",Area);         
            }
    return 0;
    }
