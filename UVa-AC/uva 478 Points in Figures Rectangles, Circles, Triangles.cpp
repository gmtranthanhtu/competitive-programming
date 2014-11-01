/*
  Name: UVa 478 Points in Figures: Rectangles, Circles, Triangles
  Copyright: 
  Author: 3T
  Date: 26/08/11 02:45
  Description: geometry
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define INP "478.INP"
#define OUT "478.OUT"

typedef struct Figure{
        double a, b, c, d, e, f;
        char h;
        };
Figure F[100];

char line[1000], Tmp;
int N, NP;
double X, Y;

bool isIn(int i){
     if(F[i].h == 'r'){
               if(X < max(F[i].a, F[i].c) && X > min(F[i].a, F[i].c) && Y < max(F[i].b, F[i].d) && Y > min(F[i].b, F[i].d)) return true;
               return false;
               }
     if(F[i].h == 'c'){
               if(hypot(X - F[i].a, Y - F[i].b) < F[i].c) return true;
               return false;
               }
     if(F[i].h == 't'){
               double Tmp1 = (F[i].c - F[i].a) * (Y - F[i].d) - (X - F[i].c) * (F[i].d - F[i].b);
               double Tmp2 = (F[i].e - F[i].c) * (Y - F[i].f) - (X - F[i].e) * (F[i].f - F[i].d);
               double Tmp3 = (F[i].a - F[i].e) * (Y - F[i].b) - (X - F[i].a) * (F[i].b - F[i].f);
               if(Tmp1 * Tmp2 >= 0 && Tmp2 * Tmp3 >= 0) return true;
               return false;
               }
     }

void Process(){
     int a = 0;
     for(int i = 1; i <= N; i++){
             if(isIn(i)) {printf("Point %d is contained in figure %d\n", NP, i); a++;}
             }
     if(a == 0) printf("Point %d is not contained in any figure\n",NP);
     }

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    N = NP = 0;
    while(gets(line)){
                      if(line[0] == '*') break;
                      N++;
                      if(line[0] == 'r'){
                                 sscanf(line, "%c %lf %lf %lf %lf",&F[N].h,&F[N].a,&F[N].b,&F[N].c,&F[N].d);
                                 }
                      if(line[0] == 'c'){
                                 sscanf(line, "%c %lf %lf %lf",&F[N].h, &F[N].a, &F[N].b, &F[N].c);
                                 }
                      if(line[0] == 't'){
                                 sscanf(line, "%c %lf %lf %lf %lf %lf %lf", &F[N].h,&F[N].a,&F[N].b,&F[N].c,&F[N].d,&F[N].e, &F[N].f);
                                 }
                      }
    while(scanf("%lf %lf",&X, &Y)){
                     if(X == 9999.9 && Y == 9999.9) break;
                     NP ++;
                     Process();
                     }
    return 0;
    }
