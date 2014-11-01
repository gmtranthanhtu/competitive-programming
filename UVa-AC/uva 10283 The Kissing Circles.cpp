/*
  Name: UVa 10283 The Kissing Circles
  Copyright: 
  Author: 3T
  Date: 13/09/10 03:47
  Description: math, geometry
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INP "10283.INP"
#define OUT "10283.OUT"

const double MyPi = 2 * acos(0);
double R, r, I, E, Anglea, Angleb;
int N;

int main () {
    //freopen(INP, "r", stdin);
   // freopen(OUT, "w", stdout);
    while(scanf("%lf %d",&R, &N) != EOF){
           if(N == 1){
                r = R;
                I = 0.0;
                E = 0.0;
                } 
           else if(N == 2){
                r = R / 2;
                I = 0.0;
                E = MyPi * (R * R - 2 * r * r);
                }         
           else{
                Anglea = (N - 2) * 180.0 / (double) N;
                Anglea = Anglea / 2.0;
                Angleb = 180 - 2.0 * Anglea;
                r = R / (2 * sin(Anglea * MyPi / 180) / sin(Angleb * MyPi / 180) + 1);
                //
                double Area1 = (N * 4 * r * r) / (4 * tan(MyPi / N));
                double Area2 = r * r * MyPi;
                double Area3 = N * (Area2 * Anglea / 180);
                I = Area1 - Area3;
                E = R * R * MyPi - N * Area2 - I;
                }
           
           printf("%.10lf %.10lf %.10lf\n",r, I, E);
           }
    return 0;
    }
