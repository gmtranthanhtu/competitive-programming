/*
  Name: UVa 10286
  Copyright: 
  Author: 3T
  Date: 12/09/10 18:00
  Description: math, sine theorem
*/
#include <stdio.h>
#include <math.h>

const double MyPi = 2 * acos(0);
const double Sin108 = sin(MyPi * 108 / 180);
const double Sin63 = sin(MyPi * 63 / 180);

int main () {
    double N;
    while(scanf("%lf",&N) != EOF){
           printf("%.10lf\n", N * Sin108 / Sin63);               
           }
    return 0;
    }
