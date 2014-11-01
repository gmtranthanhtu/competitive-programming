/*
  Name: UVa 10573 Geometry Paradox
  Copyright: 
  Author: 3T
  Date: 26/08/10 11:18
  Description: Geometry, Circle Area
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

const double MyPi = 2 * acos(0);

int t,r1,r2,N;
double Result;
char line[100];

int main (){
    FILE *f = stdin;
    fscanf(f,"%d",&N);
    fgets(line, 100, f);
    for(int i = 1; i <= N; i++){
            r1 = r2 = t = 0;
            fgets(line, 100, f);
            sscanf(line,"%d %d",&r1, &r2);     
            if(!r2){
                    Result = MyPi * r1 * r1 / 8;
                    } 
            else{
                 Result = 2 * MyPi * r1 * r2;
                 }
            printf("%.4lf\n",Result);
//            cout << r1 << ends << r2 << endl;      
            }
    return 0;
    }
