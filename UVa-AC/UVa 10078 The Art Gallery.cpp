/*
  Name: UVa 10078 The Art Gallery
  Copyright: 
  Author: 3T
  Date: 10/08/10 20:16
  Description: Geometry, Convex Hull
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INP "10078.INP"

typedef struct Point{
        int x,y;
        };
Point P[55];
int N;

long CP(Point a, Point b){ //cross product of vector a and vector b
    return a.x * b.y - a.y * b.x;
    }

bool ConvexHull(){
     int C(0),CC(0);
     for(int i = 1; i <= N; i++){
             Point Tmp1 = {P[i].x - P[i + 1].x, P[i].y - P[i + 1].y};
             Point Tmp2 = {P[i + 1].x - P[i + 2].x, P[i + 1].y - P[i + 2].y};
             long TmpCP = CP(Tmp1, Tmp2);
             if(TmpCP >= 0) C++;
             else CC++;
                  }
     if(C == N || CC == N) return true;
     else return false;
     }

int main (){
   // FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    while(fscanf(f,"%d",&N) && N){
           for(int i = 1; i <= N; i++){
                   fscanf(f,"%d%d",&P[i].x,&P[i].y);
                   }
           P[N + 1] = P[1];
           P[N + 2] = P[2];                 
           printf("%s\n", ConvexHull() ? "No" : "Yes");
           }
   // getchar();
    return 0;
    }
