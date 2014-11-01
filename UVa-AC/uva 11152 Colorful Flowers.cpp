/*
  Name: UVa 11451 
  Copyright: 
  Author: 3T
  Date: 03/10/10 21:51
  Description: Area, duong tron ngoai tiep, noi tiep tam giac
*/
#include <stdio.h>
#include <math.h>

const double MyPi = 2 * acos(0);

double a, b, c, S, V, Ro;

int main () {
    while(scanf("%lf %lf %lf",&a,&b,&c) == 3){
                     double p = (a + b + c) / 2;
                     double Area = sqrt(p * (p - a) * (p - b) * (p - c));
                     double r = Area / p;
                     Ro = r * r * MyPi;
                     V = Area - Ro;
                     double R = a * b * c / (4 * Area);
                     double TmpS = R * R * MyPi;
                     S = TmpS - Area;
                     printf("%.4lf %.4lf %.4lf\n",S,V,Ro);
                     }
    
    return 0;
    }
