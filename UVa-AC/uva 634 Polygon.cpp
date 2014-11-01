/*
  Name: UVa 634 Polygon 
  Copyright: 
  Author: 3T
  Date: 06/08/10 00:43
  Description: Geometry, point in polygon
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INP "634.INP"
#define MAX 1005

typedef struct Point{
        int x,y;
        };
        
Point Po[MAX],P;
int N;

bool inPolygon(){
     int Count = 0;
     for(int i = 0; i < N; i++){
             if(Po[i].y == P.y){
                        if(Po[i].x >= P.x){
                                   if((Po[(i + N - 1) % N].y > Po[i].y && Po[i].y > Po[(i + N + 1) %N].y)
                                   ||(Po[(i + N - 1) % N].y < Po[i].y && Po[i].y < Po[(i + N + 1) %N].y)) Count++;
                                   if(Po[(i + N + 1) % N].y == P.y){
                                            if((Po[(i + N - 1) % N].y > Po[i].y && Po[i].y > Po[(i + N + 2) % N].y)
                                   ||(Po[(i + N - 1) % N].y < Po[i].y && Po[i].y < Po[(i + N + 2) % N].y)) Count++;
                                            }
                                   }
                        }
             else if((Po[i].y > P.y && P.y > Po[(i + N + 1) % N].y)
                       ||(Po[i].y < P.y && P.y < Po[(i + N + 1) % N].y)){
                                  int a = Po[(i + N + 1) % N].x - Po[i].x;
                                  int b = P.y - Po[i].y;
                                  int c = Po[(i + N + 1) % N].y - P.y;
                                  int x_cut = Po[i].x + (int)round(a * b / c);
                                  if(x_cut > P.x) Count++;
                                  }
             }
     return Count % 2 ? true : false;
     }

int main () {
    //FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    while(fscanf(f,"%d",&N) && N){
         for(int i = 0; i < N; i++){
                 fscanf(f,"%d%d",&Po[i].x,&Po[i].y);
                 }
         fscanf(f,"%d%d",&P.x,&P.y);
         printf("%c\n",inPolygon() ? 'T' : 'F');                
         }
    //getchar();
    return 0;
    }
