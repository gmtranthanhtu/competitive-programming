/*
  Name: UVa 10002 Center of Masses
  Copyright: 
  Author: 3T
  Date: 09/08/10 18:03
  Description: Geometry, polygon, center of masses, convex hull
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define MAX 105
#define INP "10002.INP"

typedef struct Point{
        double x, y;
        };
Point P[MAX];
int N;

double findAngle(Point a, Point b){
    double t;
    double dx = b.x - a.x; a.x = fabs(dx);
    double dy = b.y - a.y; a.y = fabs(dy);
    if(dx == 0 && dy == 0) t = 0;
    else t = dy / (a.x + a.y); 
    if(dx<0) t = 2 - t;
    else if(dy<0) t = 4 + t;
    return t * 90;
      }

double centerTrianglex(Point A, Point B, Point C){
      return (A.x + B.x + C.x) / 3.0;
      }
      
double centerTriangley(Point A, Point B, Point C){
      return (A.y + B.y + C.y) / 3.0;
      }

double findArea(Point A, Point B, Point C){
       double Tmp = (A.x * B.y - B.x * A.y + B.x * C.y - C.x * B.y + C.x * A.y - A.x * C.y);
       if(Tmp < 0) Tmp *= -1.0;
       return Tmp / 2;
       }

Point findCenter(){
      Point R;
      double Sumx(0.0),Sumy(0.0),Sum(0.0);
      for(int i = 2; i <= N - 1; i++){
              double Tmpx = centerTrianglex(P[1], P[i], P[i + 1]);
              double Tmpy = centerTriangley(P[1], P[i], P[i + 1]);
              double TmpS = findArea(P[1], P[i], P[i + 1]);
              Sumx = Sumx + (Tmpx * TmpS);
              Sumy = Sumy + (Tmpy * TmpS);
              Sum += TmpS;
              }
      R.x = Sumx / Sum;
      R.y = Sumy / Sum;
//      printf("Sum:x %.5lf\n",Sumx);
      return R;
      }
      
void Sort(){
     for(int i = 1; i <= N - 2; i++){
             double MinAngle;
             for(int j = i + 1; j <= N; j++){
                     double Tmp = findAngle(P[i], P[j]);
                   //  printf("Angle: (%.2lf, %.2lf) and (%.2lf, %.2lf): %.2lf\n",P[j].x, P[j].y, P[i].x, P[i].y, Tmp);
                     if(j == i + 1){
                          MinAngle = Tmp;
                          }
                     else{
                          if(Tmp < MinAngle){
                                 MinAngle = Tmp;
                                 swap(P[i + 1], P[j]);
                                 }
                          }
                     }
             }
     }

int main () {
 //   FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    while(fscanf(f,"%d",&N) && N >= 3){
          double topleft, topbot;
          for(int i = 1; i <= N; i++){
                  fscanf(f,"%lf%lf",&P[i].x,&P[i].y);
                  if(i == 1){
                       topleft = P[i].x;
                       topbot = P[i].y;
                       continue;
                       }

                  else if(P[i].y < topbot || (P[i].y == topbot && P[i].x < topleft)){
                            topleft = P[i].x;
                            topbot = P[i].y;
                            swap(P[i], P[1]);
                            }
                  }
                  //test
//                            for(int i = 1; i <= N; i++){
//                  printf("%.3lf %.3lf\n",P[i].x,P[i].y);
//                  }
//                  printf("----------------------------\n");
               Sort();
//                    for(int i = 1; i <= N; i++){
//                  printf("%.3lf %.3lf\n",P[i].x,P[i].y);
//                  }
               Point R = findCenter();
          printf("%.3lf %.3lf\n",R.x,R.y);                  
          }
//    getchar();
    return 0;
    }
