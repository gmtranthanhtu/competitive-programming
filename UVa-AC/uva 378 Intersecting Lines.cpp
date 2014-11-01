/*
  Name: UVa 378 Intersectiong Lines
  Copyright: 
  Author: 3T
  Date: 02/08/10 00:42
  Description: Geometry, lines
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define INP "378.INP"
#define OUT "378.OUT"

int N,x1,x2,y2,x3,y3,x4,y4,Ans;
int y11;
char A[3][10] = {"NONE","LINE","POINT "};


bool checkDirect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
     pair <int, int> u1, u2;
     u1 = make_pair(x1 - x2, y1 - y2);
     u2 = make_pair(y3 - y4, x4 - x3);
     if(u1.first * u2.first + u1.second * u2.second == 0) return true;
     else return false;
     }

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

int main () {
   // FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    //freopen(OUT, "w", stdout);
    fscanf(f,"%d",&N);
    printf("INTERSECTING LINES OUTPUT\n");
    for(int i = 1; i <= N; i++){
            fscanf(f,"%d%d%d%d%d%d%d%d",&x1,&y11,&x2,&y2,&x3,&y3,&x4,&y4);
            Ans = 2;
            if(checkDirect(x1,y11,x2,y2,x3,y3,x4,y4)){
                                                     if(checkDirect(x1,y11,x3,y3,x2,y2,x3,y3)) Ans = 1;
                                                     else Ans = 0;
                                                     }
            if(Ans != 2){
                   printf("%s\n",A[Ans]);
                   }
            else{
                 double Xx, Xy;
                 getIntersection(Xx, Xy,(double) x1,(double)y11,(double)x2,(double)y2,(double)x3,(double)y3,(double)x4,(double)y4);
                 printf("%s%.2lf %.2lf\n",A[Ans],Xx,Xy);
                 }
            }
    printf("END OF OUTPUT\n");
    //fclose(stdout);
//    getchar();
    return 0;
    }
