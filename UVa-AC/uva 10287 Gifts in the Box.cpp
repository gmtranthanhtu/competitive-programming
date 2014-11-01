/*
  Name: UVa 10287 Gifts in Hexagon Box
  Copyright: 
  Author: 3T
  Date: 13/09/10 03:00
  Description: math, geometry
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define INP "10287.INP"
#define OUT "10287.OUT"

const double MyPi = 2 * acos(0);
//const double Can3 = sqrt(3.0);
const double Sin60 = sqrt(3.0) / 2;
const double Sin150 = 0.5;
const double Sin15 = sin(MyPi * 15 / 180);
const double Sin75 = sin(MyPi * 75 / 180);
const double A4 = (sqrt(1008.0) - 14 * sqrt(3.0)) / 20;

double a, r1,r2,r3,r4;

int main () {
   // freopen(INP, "r", stdin);
    //freopen(OUT, "w", stdout);

    while(scanf("%lf",&a)!= EOF){
          r1 = a * Sin60;
          r3 = r1 / 2;
          r2 = a * Sin60 / Sin75 * Sin15 / Sin150;
          r4 = a * A4;
          printf("%.10lf %.10lf %.10lf %.10lf\n",r1,r2,r3,r4);                
          }
    //getchar();
    return 0;
    }
