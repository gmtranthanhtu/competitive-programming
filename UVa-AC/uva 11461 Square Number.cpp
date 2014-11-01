/*
  Name: UVa 11461 Square Number
  Copyright: 
  Author: 3T
  Date: 28/10/10 02:41
  Description: square
*/
#include <math.h>
#include <stdio.h>

int a, b, S[100005];

bool isSquare(int i){
     if(sqrt(i) == (int)sqrt(i)) return true;
     else return false;
     }

void Init(){
     S[1] = 1;
     for(int i = 2; i <= 100000; i++){
             if(isSquare(i)) S[i] = S[i - 1] + 1;
             else S[i] = S[i - 1];
             }
     }

int main () {
    Init();
    while(scanf("%d%d",&a,&b) && a){
          if(a == 1) printf("%d\n",S[b]);
          else{
               int R = S[b] - S[a];
               if(isSquare(a)) R++;
               printf("%d\n",R);
               }                    
          }
    return 0;
    }
