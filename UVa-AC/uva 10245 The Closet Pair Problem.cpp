/*
  Name: UVa 10245 The Closet Pair Problem
  Copyright: 
  Author: 3T
  Date: 28/08/10 20:07
  Description: Geometry, devide and conquer, plane sweep
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

#define INP "10245.INP"
#define MAX 10000

typedef struct Point{double x,y;};
Point P[MAX + 10];
const double BIG = 1000000000.99999;
int N, M[MAX + 10];
double R;

bool Op(Point a, Point b){
     return a.x < b.x;
     }

double getDis(Point a, Point b){
       return hypot(a.x - b.x, a.y - b.y);
       }

double callDAQ(int Left, int Right){
       if(Left == Right) return BIG;
       if(Left == Right - 1) return getDis(P[Left], P[Right]);
       if(Left == Right - 2) return min(getDis(P[Left], P[Right]), min(getDis(P[Left], P[Left + 1]), getDis(P[Left + 1], P[Right])));
       int Middle = Left + (Right - Left) / 2;
       double MinL = callDAQ(Left, Middle);
       double MinR = callDAQ(Middle + 1, Right);
       double MinTmp = min(MinL, MinR);
       int k = 1;
       for(int i = Middle; i >= Left; i--){
               if(P[Middle].x - P[i].x < MinTmp) M[k++] = i;
               else break;
               }
       for(int i = Middle + 1; i <= Right; i++){
               if(P[i].x - P[Middle + 1].x < MinTmp) M[k++] = i;
               else break;
               }
       k--;
       for(int i = 1; i <= k - 1; i++){
               for(int j = i + 1; j <= k; j++){
                       if(fabs(P[M[i]].y - P[M[j]].y) <= MinTmp){
                                         MinTmp = min(MinTmp, getDis(P[M[i]], P[M[j]]));
                                         }
                       }
               }  
       return MinTmp; 
       }

int main () {
    //FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    while(fscanf(f,"%d",&N) && N){
           for(int i = 1; i <= N; i++){
                   fscanf(f, "%lf %lf", &P[i].x, &P[i].y);
                   }    
           sort(P + 1, P + N + 1, Op);
           R = callDAQ(1, N);    
           if(R < MAX) printf("%.4lf\n",R);
           else printf("INFINITY\n");         
           }
    fclose(f);
   // getchar();
    return 0;
    }
