/*
  Name: UVa 11866 Triangle
  Copyright: 
  Author: 3T
  Date: 10/10/10 22:32
  Description: DP
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

typedef long long MyType;

int X, Y, T;
MyType R;
MyType M[1000010];
MyType MM[1000010];
MyType MMM[1000010];

void Init(){
     M[1] = 1;
     MM[1] = 3;
    // MMM[1] =  6;
     MMM[1] = 2;
     MyType mm = 6;
     MyType m = 4;
     MyType t = 2, tt = 0;
     int d = 0;
     for(int i = 2; i <= 1000000; i++){
             tt = tt + t;         
             if(d == 2){
                  t++;
                  d = 0;
                  }
             M[i] = M[i - 1] + tt;
                  MMM[i] = MMM[i - 1] + t;
             d++;

                  MM[i] = MM[i - 1] + mm;
                  mm = mm + m;
                  m++;
             }     
     MMM[0] = 0;
     for(int i = 1; i <= 1000000; i++){
             MMM[i] = MMM[i] + MMM[i - 1];
             }
     }

int main () {
    //freopen("H.INP","r",stdin);
   // freopen("H.OUT", "w", stdout);
    Init();
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            scanf("%d%d",&X,&Y);
            if(X == 1){
                 cout << M[Y] << endl;
                 continue;
                 }            
            int Tmp = Y - X;
            if(!Tmp) R = 1;
            else{
                 if(X == Tmp) R = MM[Tmp];
                 else if (X > Tmp){
                      R = MM[Tmp] + 1;
                      }
                 else {
                    int H = Tmp - X;
                    R = MM[Tmp] - MMM[H];
                    }
                 }            
            
            cout << R << endl;
            }
    return 0;
    }
