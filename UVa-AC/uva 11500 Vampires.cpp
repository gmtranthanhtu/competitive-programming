/*
  Name: UVa 11500 Vampires
  Copyright: 
  Author: 3T
  Date: 12/07/10 00:56
  Description: gambling algorithm
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    int EV1,EV2,AT,D;
    double R;
    while(scanf("%d%d%d%d",&EV1,&EV2,&AT,&D) && EV1){
          double p = (double)AT / 6;
          double n1 = ceil(EV1 / (float) D); //printf("n1: %.2lf\n",n1);
          double n2 = ceil(EV2 / (float) D); //printf("n2: %.2lf\n",n2);
          //printf("P: %.2lf\n",p);
          if(p == 0.5){
               R =  n1 / (n1 + n2);
               }
          else{
               double d1 = 1 - (pow((1-p)/p,n1));
               double d2 = 1 - (pow((1-p)/p,n1 + n2));
               R = d1 / d2;
               }
               R = R * 100.0;
          printf("%.1lf\n",R);
          }
    return 0;
    }
