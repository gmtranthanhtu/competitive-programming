/*
  Name: UVa 313 Intervals
  Copyright: 
  Author: 3T
  Date: 26/08/11 06:46
  Description: geometry
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define INP "313.INP"
#define OUT "313.OUT"

typedef struct Circle{
        double x, y, R;
        };
        
typedef struct Segment{
        double xS, xE;
        };

//Circle C[1000];
Circle C;
double bx, by;
const double Pi = 2 * acos(0);
const double eps = 1e-10;
int N;

Segment Seg[1000];

void getIntersection(int i){
     double Tmp = (by - C.y) / (bx - C.x);
     double Angle1 = atan(Tmp);
     double Tmp2 = hypot(bx - C.x, by - C.y);
     double Sin2 = C.R / Tmp2;
     double Angle2 = asin(Sin2);
     double Angle3 = Pi - Angle1 - Angle2;
     double Angle4 = Pi - (Pi - Angle1) - Angle2;
     //double Angle4 = Pi - 2 * Angle2;
     
     double Tan3 = tan(Pi - Angle3);
     double Tan4 = tan(Angle4);
     //cout << Tan3 << " " << Tan4 << "tan" << endl;
     
     double b3 = by - Tan3 * bx;
     double b4 = by - Tan4 * bx;
     
     double x3 = -b3 / Tan3;
     double x4 = -b4 / Tan4;
     
     Seg[i].xS = min(x3, x4);
     Seg[i].xE = max(x3, x4);
     }
     
//void Test(){
//     for(int i = 1; i <= N; i++){
//             printf("%.2lf %.2lf\n",Seg[i].xS, Seg[i].xE);
//             }
//     cout << endl;
//     }

bool cmp(const Segment &S1, const Segment &S2){
     return S1.xS < S2.xS;
     }

bool isBigger(double a, double b){
     if(b - a >= eps) return false;
     if(a - b <= eps) return false;
     if(a - b > eps) return true;
     }

void Process(){
     double L = Seg[1].xS, R = Seg[1].xE;
     for(int i = 2; i <= N; i++){
             if(isBigger(Seg[i].xS, R)){
                          printf("%.2lf %.2lf\n",L - eps, R - eps);
                          L = Seg[i].xS;
                          R = Seg[i].xE;
                          }
             else{
                  R = max(R, Seg[i].xE);
                  }
             }
     printf("%.2lf %.2lf\n",L - eps, R - eps);
     printf("\n");
     }

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    
    while(scanf("%d",&N) && N){
           scanf("%lf %lf",&bx,&by);
           for(int i = 1; i <= N; i++){
                   scanf("%lf %lf %lf",&C.x, &C.y, &C.R);
                   getIntersection(i);
                   }  
                   
           //Test(); 
           sort(Seg + 1, Seg + N + 1, cmp); 
           Process();          
           }
    
    return 0;
    }
