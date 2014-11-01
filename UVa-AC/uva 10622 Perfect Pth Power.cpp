/*
  Name: UVa 10622 Perfect Pth Power
  Copyright: 
  Author: 3T
  Date: 05/11/10 07:48
  Description: GCD, Factorize
*/
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

typedef long long mt;

mt GCD(mt a, mt b){
          if(a % b) return (b, a % b);
          return b;
          }

mt N;

mt Find(){
    //mt TmpN = N
    mt F = 0;
    for(mt i = 2; i * i <= N; i++){
           if(N % i == 0){
                mt Tmp = 0;
                while(N % i == 0){
                        Tmp++;
                        N /= i;
                        }
                if(!F) F = Tmp;
                else{
                     F = GCD(F, Tmp);
                     if(F == 1) return 1;     
                     }
                }
           }
    if(!F) return 1;
    if(F && N != 1) return 1;
    else return F;
    }
    
mt Find2(){
    mt F = 0;
    for(mt i = 2; i * i <= N; i++){
           if(N % i == 0){
                mt Tmp = 0;
                while(N % i == 0){
                        Tmp++;
                        N /= i;
                        }
                //if(Tmp % 2 == 0) return 1;
                if(!F) F = Tmp;
                else{
                     F = GCD(F, Tmp);
                     if(F == 1) return 1;    
                     } 
                }
           }
    if(!F) return 1;
    if(F && N != 1) return 1;
    else{
         if(F && N == 1 && F % 2) return F;
         if(F && N == 1 && F % 2 == 0){
              while(F % 2 == 0) F = F / 2;
              return F;
              }
         }           
           }

int main () {
    while(cin >> N && N != 0){
              //printf("%d\n", Find());
              if(N > 0)
              cout << Find() << endl;
              else{
              N = N * (-1);
              cout << Find2() << endl;
              }
              }
    return 0;
    }
