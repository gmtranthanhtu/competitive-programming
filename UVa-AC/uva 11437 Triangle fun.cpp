/*
  Name: UVa 11437 Triangle fun
  Copyright: 
  Author: 3T
  Date: 13/07/10 02:04
  Description: Heron's formula, line intersection
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define INP "11437.INP"

int T;
double Ax,Ay,Bx,By,Cx,Cy,Ex,Ey,Dx,Dy,Fx,Fy,Area;

double get23(double a, double b){
       double d = (a - b)/3.0;
       return d + b;
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
    
double getLength(double x1, double y1, double x2, double y2){
       return hypot(x1 - x2, y1 - y2);
       }

int main () {
//    FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    fscanf(f,"%d",&T);
    for(int i = 1; i <= T; i++){
            fscanf(f,"%lf %lf %lf %lf %lf %lf",&Ax,&Ay,&Bx,&By,&Cx,&Cy);
            //test
//            printf("%.3lf %.3lf %.3lf %.3lf %.3lf %.3lf\n",Ax,Ay,Bx,By,Cx,Cy);   
                     
            Ex = get23(Ax, Cx);
            Ey = get23(Ay, Cy);
            Dx = get23(Cx, Bx);
            Dy = get23(Cy, By);
            Fx = get23(Bx, Ax);
            Fy = get23(By, Ay);
            //test
//            printf("%.3lf %.3lf %.3lf %.3lf %.3lf %.3lf\n",Ex,Ey,Dx,Dy,Fx,Fy); 
//            double d,e,f;
//            d = getLength(Bx,By,Dx,Dy);
//            e = getLength(Dx,Dy,Cx,Cy);
//            f = e / d;
 //           printf("Ratio: %.2lf\n",f);
            double Rx,Ry,Px,Py,Qx,Qy;
            getIntersection(Rx,Ry,Ax,Ay,Dx,Dy,Cx,Cy,Fx,Fy);
            getIntersection(Px,Py,Ax,Ay,Dx,Dy,Bx,By,Ex,Ey);
            getIntersection(Qx,Qy,Cx,Cy,Fx,Fy,Bx,By,Ex,Ey);
            //test
//            printf("%.3lf %.3lf %.3lf %.3lf %.3lf %.3lf\n",Rx,Ry,Px,Py,Qx,Qy); 
            double a,b,c,s;
            a = getLength(Rx,Ry,Px,Py);
            b = getLength(Px,Py,Qx,Qy);
            c = getLength(Qx,Qy,Rx,Ry);
            s = (a + b + c) / 2.0;
            Area = sqrt(s * (s - a) * (s - b) * (s - c));
            printf("%.0lf\n",Area);
            }
//    getchar();
    return 0;
    }
