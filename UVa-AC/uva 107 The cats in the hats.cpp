/*
  Name: UVa 107 The cat in the hats 
  Copyright: 
  Author: 3T
  Date: 20/07/11 19:16
  Description: math, logarit
*/
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

#define MAX 1000
#define TYPE int

TYPE N, F, H, h, w;

double Fa(double a){
       if(a < 0.0) return a * -1.00000;
       else return a;
       }

bool Check(TYPE c){
     double Tmp = log((double)w) / log((double)c);
     TYPE Tmp2, Tmp9, Tmp8;
     Tmp9 = floor(Tmp);
     Tmp8 = ceil(Tmp); 
     if(Fa((double)Tmp9 - Tmp) <= 1e-9) Tmp2 = Tmp9;
     else if(Fa((double)Tmp8 - Tmp) <= 1e-9) Tmp2 = Tmp8;
     else {
     return false;}
     TYPE Tmp3 = 1;
     for(TYPE i = 1; i <= Tmp2; i++){
             Tmp3 *= c;
             }
     if(Tmp3 - w != 0) {
     return false;}
     Tmp3 = 1;
     for(TYPE i = 1; i <= Tmp2; i++){
             Tmp3 *= (c + 1);
             }     
     if(Tmp3 != h) return false;
     return true;
     }

TYPE findN(){
    for(TYPE i = 2; i <= MAX; i++){
            if(Check(i)) return i;
            }
    return 0;
    }

int main () {
    //freopen("107.INP", "r", stdin); freopen("107.OUT", "w", stdout);
    
    while((cin >> h >> w) && h){
           if(h == 1){
                cout << "0 " << w << endl;
                continue;
                }
           if(w == 1){
                H = 0;
                F = 0;
                TYPE Tmp = w;
                while(Tmp <= h){
                          H += Tmp;
                          if(Tmp != 1) F++;
                          Tmp *= 2;
                          }
                cout << F << " " << H << endl;
                continue;
                }
           N = findN(); 
           if(N == 0) {printf("0 0\n"); continue;}
           H = w;
           F = 0;
           TYPE Tmp = w;
           TYPE Tmp3 = 1;
           while(Tmp != 1){
                     TYPE Tmp2 = Tmp / N;
                     Tmp /= N;
                     Tmp3 = Tmp3 * (N + 1);
                     F += Tmp2;
                     H += (Tmp2 * Tmp3);
                     }                           
           cout << F << " " << H << endl;
           }
    
    return 0;
    }
