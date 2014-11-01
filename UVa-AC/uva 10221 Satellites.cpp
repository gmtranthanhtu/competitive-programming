/*
  Name: UVa 10221 Satellites
  Copyright: 
  Author: 3T
  Date: 27/08/10 18:09
  Description: Geometry, arc, chord, Pythagore
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

const double MyPi = 2 * acos(0);
char line[100],Type[4];
int s;
double aa,Arc,Chord,a;

int main () {
    FILE *f = stdin;
    while(fgets(line,100,f)){
          sscanf(line, "%d %lf %s",&s,&a,&Type);
          s += 6440;
          if(!strcmp(Type,"min")) a = a / 60.0;
          //a = a % 360;
          while(a >= 360){a -= 360;} 
          if(a > 180) a = 360 - a;
          Arc = 2 * MyPi * s * (a / 360.0);
          aa = (double)a / 2.0;
          aa = MyPi * aa / 180;
          Chord = 2 * s * sin(aa);
          printf("%.6lf %.6lf\n",Arc,Chord);           
          }
    return 0;
    }
