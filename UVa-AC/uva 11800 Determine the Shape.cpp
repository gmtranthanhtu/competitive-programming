/*
  Name: UVa 11800 Determine the Shape
  Copyright: 
  Author: 3T
  Date: 28/06/10 15:42
  Description: Geometry, Polygon
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iostream>
//using namespace std;
 
#define INP "g.INP"

typedef struct Point{
        int x;
        int y;
        };
int T,Result;
Point P[5];
char Shape[7][25]={"Haha","Square","Rectangle","Rhombus","Parallelogram","Trapezium","Ordinary Quadrilateral"};
bool Used[5];

bool check90(Point S1, Point E1, Point S2, Point E2){
     if((S1.x - E1.x)*(S2.x - E2.x) + (S1.y - E1.y)*(S2.y - E2.y) == 0) return true;
     else return false;
     }

bool checkEqual(Point S1, Point E1, Point S2, Point E2){
     double d1 = (S1.x - E1.x) * (S1.x - E1.x);
     double d2 = (S1.y - E1.y) * (S1.y - E1.y);
     double temp1 = sqrt(d1 + d2);
     d1 = (S2.x - E2.x) * (S2.x - E2.x); 
     d2 = (S2.y - E2.y) * (S2.y - E2.y);
     double temp2 = sqrt(d1 + d2);
     if(temp1 == temp2) return true;
     else return false;
     }

bool checkParallel(Point S1, Point E1, Point S2, Point E2){
     pair <int, int> u1, u2;
     u1 = make_pair(S1.y - E1.y, E1.x - S1.x);
     u2 = make_pair(S2.x - E2.x, S2.y - E2.y); 
     if(u1.first*u2.first + u1.second*u2.second == 0) return true;
     else return false;
     }
     
void whatIsIt(Point A, Point B, Point C, Point D){
     //AB song song CD
     //AC song song BD
     if(checkEqual(A,B,A,C)){
                             Result = 3;
                             if(check90(A,B,A,C)) Result = 1;
                             }
     else{
          if(check90(A,B,A,C)) Result = 2;
          }
     }

int main () {
  //  FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    fscanf(f,"%d",&T);
    for(int i = 1; i <= T; i++){
            for(int j = 1; j <= 4; j++){
                    fscanf(f,"%d%d",&P[j].x,&P[j].y);
                    }
            //process
            Result = 6;
            memset(Used,false,sizeof Used);
            Used[1] = true;
            for(int j = 2; j <= 4; j++){
                    if(Result != 6) break;
                    Used[j] = true;
                    pair <int, int> line (0,0);
                    for(int k = 2; k <= 4; k++){
                            if(!Used[k]){
                                         if(line.first == 0) line.first = k;
                                         else line.second = k;
                                         }
                            }
                    if(!checkParallel(P[1],P[j],P[line.first],P[line.second])) {Used[j] = false; continue;}
                    else{
                         Result = 5;
                         if(checkParallel(P[1],P[line.first],P[j],P[line.second])){
                                Result = 4;
                                whatIsIt(P[1],P[line.first],P[j],P[line.second]);                                      
                                }
                         else{
                              if(checkParallel(P[1],P[line.second],P[j],P[line.first])){
                                                           Result = 4;
                                                           whatIsIt(P[1],P[line.second],P[j],P[line.first]);  
                                                           }
                              else break;
                              }
                         }
                    
                    
                    Used[j] = false;
                    }
            //output
            printf("Case %d: %s\n",i,Shape[Result]);
            }
 //   getchar();
    return 0;
    }
