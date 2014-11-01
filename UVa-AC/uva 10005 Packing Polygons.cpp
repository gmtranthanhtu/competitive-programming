/*
  Name: UVa 10005 Packing Polygons
  Copyright: 
  Author: 3T
  Date: 27/08/10 22:43
  Description: Geometry, find the center through 2 points on the parameter and given radius
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INP "10005.INP"

typedef struct Point{double x,y;};
Point P[110];
int n,Result;
double R;

bool packCircle(){
     for(int i = 1; i <= n - 1; i++){
             for(int j = i + 1; j <= n; j++){
                     double Dist = hypot(P[j].x - P[i].x, P[j].y - P[i].y);
                     if(Dist > 2 * R) continue;
                     else{
                          double Dist2 = Dist / 2;
                          double xc, yc, xm = (P[i].x + P[j].x) / 2, ym = (P[i].y + P[j].y) / 2;
                          xc = xm + sqrt(R * R - Dist2 * Dist2) * (P[i].y - P[j].y) / Dist;
                          yc = ym + sqrt(R * R - Dist2 * Dist2) *(P[j].x - P[i].x) / Dist;
                          int Count = 0;
                          for(int k = 1; k <= n ; k++){
                                  if(hypot(xc - P[k].x, yc - P[k].y) <= R) Count++;
                                  else break;
                                  }
                          if(Count == n) return true;
                          else{
                               Count = 0;
                               xc = xm - sqrt(R * R - Dist2 * Dist2) * (P[i].y - P[j].y) / Dist;
                               yc = ym - sqrt(R * R - Dist2 * Dist2) *(P[j].x - P[i].x) / Dist;
                               for(int k = 1; k <= n ; k++){
                                  if(hypot(xc - P[k].x, yc - P[k].y) <= R) Count++;
                                  else break;
                                  }  
                               if(Count == n) return true;                             
                               }
                          }
                     }
             }
     return false;
     }

int main () {
   // FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    while(fscanf(f,"%d",&n) && n){
        for(int i = 1; i <= n; i++){
                fscanf(f,"%lf %lf",&P[i].x,&P[i].y);
                }                    
        fscanf(f,"%lf",&R);
        if(packCircle()) printf("The polygon can be packed in the circle.\n");
        else printf("There is no way of packing that polygon.\n");
        }
    //getchar();
    return 0;
    }
