/*
  Name: UVa 191 Intersection
  Copyright: 
  Author: 3T
  Date: 02/08/10 10:27
  Description: Geometry, line
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define INP "191.INP"
#define OUT "191.OUT"

typedef struct Line{
        int xs,xe,ys,ye;
        };
Line L[5];
int N,x1,y1,x2,y2,xleft,ytop,xright,ybot;
    
double getY(double x, double x1, double y1, double x2, double y2){
       if(x == x1) return y1;
       if(x == x2) return y2;
       double a = (x2 - x1) / (x - x1);
       return (y2 - y1) / a + y1;
       }
    

void getIntersection(double& Xx, double& Xy, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
     double a1, a2;
     if(x1 > x2){
        swap(x1, x2);
        swap(y1, y2);
         }
    if(x3 > x4){
        swap(x3, x4);
        swap(y3, y4);
         }
         if(x1 == x2){
               Xx = x1;
               Xy = getY(x1, x3, y3, x4, y4);
               return;
               }
         else if(x3 == x4){
              Xx = x3;
              Xy = getY(x3, x1, y1, x2, y2);
              return;
              }
         
    a1 = (y1 - y2)/(x1 - x2); //slope of the line contains segment 1
    a2 = (y3 - y4)/(x3 - x4); //slope of the line contains segment 2
    /*!
        the line function
            y = a*x - a*xo + yo
            solve for x where two lines intersect
    !*/
        Xx = (a1 * x1 - a2 * x3 - y1 + y3) / (a1 - a2);
        Xy = a1 * (Xx - x1) + y1;
     }

bool checkDirect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
     pair <int, int> u1, u2;
     u1 = make_pair(x1 - x2, y1 - y2);
     u2 = make_pair(y3 - y4, x4 - x3);
     if(u1.first * u2.first + u1.second * u2.second == 0) return true;
     else return false;
     }

bool checkIntersect(int x1, int y11, int x2, int y2, int x3, int y3, int x4, int y4){
     if(checkDirect(x1,y11,x2,y2,x3,y3,x4,y4)){
                                               if(checkDirect(x1,y11,x3,y3,x2,y2,x3,y3)){
                                                                                         if((min(x1, x2) <= x3 && x3 <= max(x1, x2) && min(y11, y2) <= y3 && y3 <= max(y11, y2))
                                                                                            || (min(x1, x2) <= x4 && x4 <= max(x1, x2) && min(y11, y2) <= y4 && y4 <= max(y11, y2)) ){
                                                                                                        return true;
                                                                                                        }
                                                                                         else return false;
                                                                                         }
                                               else return false;
                                               }
     else{
                 double Xx, Xy;
                 getIntersection(Xx, Xy,(double) x1,(double)y11,(double)x2,(double)y2,(double)x3,(double)y3,(double)x4,(double)y4);
                 if((min(x1, x2) <= Xx && Xx <= max(x1, x2) && min(y11, y2) <= Xy && Xy <= max(y11, y2)) 
                     && (min(x3, x4) <= Xx && Xx <= max(x3, x4) && min(y3, y4) <= Xy && Xy <= max(y3, y4)) ) return true;
                 else return false;
          }
     }

bool checkInside(int x, int y,
                  int x0, int y0, int x1, int y1){
  return min(x0, x1) <= x && x <= max(x0, x1) && min(y0, y1) <= y && y <= max(y0, y1);
}

int main () {
 //   FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    //freopen(OUT, "w", stdout);
    fscanf(f,"%d",&N);
    for(int i = 1; i <= N; i++){
            fscanf(f,"%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&xleft,&ytop,&xright,&ybot);
            if(checkInside(x1, y1, xleft, ytop, xright, ybot) || checkInside(x2, y2, xleft, ytop, xright, ybot)) {
                              printf("T\n");
                              }
            else {
                 L[1].xs = xleft; L[1].xe = xright; L[1].ys = L[1].ye = ytop;
                 L[2].xs = L[2].xe = xright; L[2].ys = ytop; L[2].ye = ybot;
                 L[3].xs = xright; L[3].xe = xleft; L[3].ys = L[3].ye = ybot;
                 L[4].xs = L[4].xe = xleft; L[4].ys = ybot; L[4].ye = ytop;    
                 
                 bool Test = false;
                 for(int j = 1; j <= 4; j++){ 
                 if(checkIntersect(x1,y1,x2,y2,L[j].xs,L[j].ys,L[j].xe,L[j].ye)){
                                      printf("T\n");
                                      Test = true;
                                      break;
                                      } 
                              }
                   if(!Test) printf("F\n");                                         
                 }
            
            }
    //fclose(stdout);
  //  getchar();
    return 0;
    }
