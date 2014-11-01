/*
  Name: UVa 922 Rectangle by The Ocean
  Copyright: 
  Author: 3T
  Date: 30/08/10 01:41
  Description: Geometry, Area of rectangle
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define INP "922.INP"
#define MAX 260
#define BIG 100000000000.0

typedef struct Point{double x,y;};
Point P[MAX];
int Case,N;
double Area;
Point LowLeft, UpRight;

double findArea(){
       double r = 0.0;
       for(int i = 1; i <= N; i++){
               r = r + P[i].x * P[i + 1].y - P[i + 1].x * P[i].y;
               }
       return 0.5 * fabs(r);
       }
       
bool checkExist(Point P1, Point P2){
     for(int i = 1; i <= N; i++){
             if((P[i].x == P1.x && P[i].y == P1.y) || (P[i].x == P2.x && P[i].y == P2.y)) return true;
             }
     return false;
     }

bool Cmp(Point P1, Point P2, Point P3, Point P4){
     if(P1.x > P3.x) return true;
     else if(P1.x == P3.x && P1.y > P3.y) return true;
     else if(P1.x == P3.x && P1.y == P3.y && P2.x > P4.x) return true;
     else if(P1.x == P3.x && P1.y == P3.y && P2.x == P4.x && P2.y > P4.y) return true;
     return false;
     }

void findRectangle(){
     double Diff = BIG;
     LowLeft.x = LowLeft.y = BIG;
     UpRight.y = UpRight.x = -BIG;
     for(int i = 1; i <= N; i++){
             for(int j = 1; j <= N; j++){
                     if(P[j].x > P[i].x && P[j].y > P[i].y)
                     {
                     Point P1 = {P[i].x, P[j].y};
                     Point P2 = {P[j].x, P[i].y};
                     if(!checkExist(P1, P2)) continue;
                     double Tmp = fabs((P[j].x - P[i].x) * (P[j].y - P[i].y) - Area);
                     if(Tmp < Diff){
                            Diff = Tmp;
                            LowLeft = P[i];
                            UpRight = P[j];
                            }
                     else if(Tmp == Diff){
                          if(Cmp(LowLeft, UpRight, P[i], P[j])){
                                          LowLeft = P[i];
                                          UpRight = P[j];
                                          }
                          }
                     }
                     else if(P[i].y == P[j].y && P[j].x > P[i].x){
                          for(int t = 1; t <= N; t++){
                                  if(P[t].y != P[i].y && (P[t].x == P[i].x || P[t].x == P[j].x)){
                                            double LLy = min(P[i].y, P[t].y);
                                            double URy = max(P[i].y, P[t].y);
                                            Point TmpLL = {P[i].x, LLy};
                                            Point TmpUR = {P[j].x, URy};
                                            double Tmp = fabs((TmpUR.x - TmpLL.x) * (TmpUR.y - TmpLL.y) - Area);
                                            if(Tmp < Diff){
                                                   Diff = Tmp;
                                                   LowLeft = TmpLL;
                                                   UpRight = TmpUR;
                                                   }
                                            else if(Tmp == Diff){
                                                 if(Cmp(LowLeft, UpRight, TmpLL, TmpUR)){
                                                                 LowLeft = TmpLL;
                                                                 UpRight = TmpUR;
                                                                 }
                                                 }
                                            }
                                  }
                          }
                     
                     }
             }
     }

int main () {
   // FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    fscanf(f,"%d",&Case);
    for(int i = 1; i <= Case; i++){
            fscanf(f,"%d",&N);
            for(int j = 1; j <= N; j++){
                    fscanf(f,"%lf %lf",&P[j].x,&P[j].y);
                    }
            P[N + 1] = P[1];
            Area = findArea();
            //printf("%.1lf\n",Area);
            findRectangle();
            printf("%.1lf %.0lf %.0lf %.0lf %.0lf\n",Area,LowLeft.x,LowLeft.y,UpRight.x,UpRight.y);
            }
    
   // getchar();
    return 0;
    }
