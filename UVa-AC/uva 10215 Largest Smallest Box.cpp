/*
  Name: UVa 10215 Largest Smallest Box
  Copyright: 
  Author: 3T
  Date: 27/08/10 17:56
  Description: Geometry, da thuc bac 3, tim cuc tri, them epsilon vao ket qua de tranh sai so
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define eps 1e-7

double L,W,x1;

int main () {
    FILE *f = stdin;
    while(fscanf(f,"%lf %lf",&L,&W) == 2){
         if(W > L) swap(L,W);
         x1 = ((L + W) - sqrt(L * L + W * W - L * W)) / 6.0;  
         printf("%.3lf %.3lf %.3lf\n",x1 + eps,0.0,(W * 0.5) + eps);
                    
         }
    return 0;
    }
