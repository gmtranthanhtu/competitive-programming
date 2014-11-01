/*
  Name: UVa 10451
  Copyright: 
  Author: 3T
  Date: 03/10/10 21:43
  Description: regular polygons, circle
*/
#include <stdio.h>
#include <math.h>

const double MyPi = 2 * acos(0);

int N, Case(1);
double A;

int main () {
    while(scanf("%d %lf",&N,&A) && N >= 3){
          double t = sqrt(4.0 * A * tan(MyPi / (double) N) / (double) N);
          double a = 2 * A / ((double) N * t);
          double S1 = a * a * MyPi;
       //   printf("%.5lf\n",A - S1);          
          double Angle = ((double)N - 2) * 180.0 / (double)N / 2.0;
          Angle = Angle * MyPi / 180;
          double R = a / sin(Angle);
          double S2 = R * R * MyPi;
          if(A == 0){
               printf("Case %d: %.5lf %.5lf\n",Case++, 0.0, 0.0);
               }
               else
          printf("Case %d: %.5lf %.5lf\n",Case++, S2 - A, A - S1);
         // printf("%.5lf\n",S2 - A); 
          
                    
          }
    return 0;
    }
