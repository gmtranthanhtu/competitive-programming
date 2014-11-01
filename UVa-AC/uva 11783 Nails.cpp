/*
  Name: UVa 11783 Nails
  Copyright: 
  Author: 3T
  Date: 11/07/10 12:40
  Description: line intersection
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Line{
        int x1,x2,y1,y2;
        };
Line L[1005];
int N,Intersect[1005];

long pointSide(int x, int y, int x1, int y1, int x2, int y2){
    return (y - y1) * (x2 - x1) - (x - x1) * (y2 - y1);
    }

int main () {
    while(scanf("%d",&N) && N){
          for(int i = 1; i <= N; i++){
                  scanf("%d%d%d%d",&L[i].x1,&L[i].y1,&L[i].x2,&L[i].y2);
                  Intersect[i] = 0;
                  }
          if(N == 1) printf("%d\n",2);  
          else{
               int Result = 0;
               for(int j = 1; j < N; j++){
                       for(int k = j + 1; k <= N; k++){
                               if(pointSide(L[j].x1,L[j].y1,L[k].x1,L[k].y1,L[k].x2,L[k].y2) * pointSide(L[j].x2,L[j].y2,L[k].x1,L[k].y1,L[k].x2,L[k].y2)<= 0 
                               && pointSide(L[k].x1,L[k].y1,L[j].x1,L[j].y1,L[j].x2,L[j].y2) * pointSide(L[k].x2,L[k].y2,L[j].x1,L[j].y1,L[j].x2,L[j].y2) <= 0){
                                     Intersect[j]++;
                                     Intersect[k]++; 
                                     Result++;                                                      
                                     }
                               }
                       }

               for(int j = 1; j <= N; j++){
                       if(Intersect[j] == 0){
                       Result += 2;}
                       }
               printf("%d\n",Result);
               }
                
          }
    return 0;
    }
