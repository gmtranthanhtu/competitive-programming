/*
  Name: UVa 10195 The Knights of The Round Table
  Copyright: 
  Author: 3T
  Date: 10/08/10 22:02
  Description: Geometry, r = S/p
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    double a,b,c,r,p,S;
    FILE *f = stdin;
//    while(!feof(f)){
//                   fscanf(f,"%lf%lf%lf",&a,&b,&c);
      while(fscanf(f,"%lf%lf%lf",&a,&b,&c) != EOF){
                   if(a == 0 || b == 0 || c == 0) r = 0;
                   else{
                        p = (a + b + c) / 2;
                        S = sqrt(p * (p - a) * (p - b) * (p - c));
                        r = S / p;
                        }
                   printf("The radius of the round table is: %.3lf\n",r);
                   }
    
    
   // getchar();
    return 0;
    }
