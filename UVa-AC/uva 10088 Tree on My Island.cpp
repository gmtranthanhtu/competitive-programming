/*
  Name: UVa 10088 Trees on My Island
  Copyright: 
  Author: 3T
  Date: 10/08/10 23:48
  Description: Geometry, Pick's theorem: I = (2A - B + 2) / 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

#define MAX 1005
#define INP "10088.INP"
//#define long long i64

typedef long long i64;

typedef struct Point{
        i64 x,y;
        };
Point P[MAX];
int N;

i64 getAbs(i64 a){
    if(a < 0) a = a * -1;
    return a;
    }

i64 GCD(i64 a, i64 b){
    if(!b) return a;
    if(b > a) return GCD(b, a);
    return GCD(b, a % b);
    //return !b ? a : GCD(b, a % b);
    }

i64 Area(){
    i64 A(0);
    for(int i = 1; i <= N; i++){
            i64 Tmp = P[i].x * P[i + 1].y - P[i + 1].x * P[i].y;
            A += Tmp;
            }
    return getAbs(A);
    }
    
i64 Boundary(){
    i64 B(0);
    B -= N;
    for(int i = 1; i <= N; i++){
            i64 X = P[i].x - P[i + 1].x;
            i64 Y = P[i].y - P[i + 1].y;
            X = getAbs(X);
            Y = getAbs(Y);
            i64 Tmp = GCD(X, Y) + 1;
            B += Tmp;
            }
    return B;
    }

int main () {
    //FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    while(fscanf(f,"%d",&N) && N){
        for(int i = 1; i <= N; i++){
                fscanf(f,"%lld %lld",&P[i].x,&P[i].y);
                }
        P[N + 1] = P[1];
        cout << (Area() - Boundary() + 2)/2 << endl;                    
        }
   // getchar();
    return 0;
    }
