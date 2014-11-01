/*
  Name: UVa 10589 Area
  Copyright: 
  Author: 3T
  Date: 27/08/10 21:08
  Description: simple Geometry
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INP "10589.INP"

int N,a,M;
double x,y,R;

bool check(double x, double y){
     if(hypot(x, y) <= a && hypot(x - a, y) <= a && hypot(x, y - a) <= a && hypot(x - a, y - a) <= a) return true;
     else return false;
     }

int main () {
    //FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    while(fscanf(f,"%d%d",&N,&a) && N){
            M = 0;
            for(int i = 1; i <= N; i++){
                    fscanf(f,"%lf %lf",&x, &y);
                    if(check(x, y)) M++;
                    }  
            R = (double) M * a * a / (double) N;
            printf("%.5lf\n",R);                   
            }
    //getchar();
    return 0;
    }
