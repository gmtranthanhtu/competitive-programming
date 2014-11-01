/*
  Name: UVa 495 fibonacci Freeze
  Copyright: 
  Author: 3T
  Date: 22/10/10 16:44
  Description: bignum
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int F[5005][1500];
int N;

void Init(){
     memset(F, 0, sizeof F);
     F[1][1] = 1; F[1][0] = 1;
     F[2][1] = 1; F[2][0] = 1;
     for(int i = 3; i <= 5000; i++){
             int len = max(F[i - 1][0], F[i - 2][0]);
             int du = 0;
             for(int j = 1; j <= len; j++){
                     int Tmp = F[i - 1][j] + F[i - 2][j] + du;
                     if (Tmp < 10){
                             F[i][j] = Tmp;
                             du = 0;
                             }
                     else{
                          F[i][j] = Tmp % 10;
                          du = 1;
                          }
                     }
             if(du == 0) F[i][0] = len;
             else {
                  F[i][len + 1] = 1;
                  F[i][0] = len + 1;
                  }
             }
     }
     
void Print(int N){
     if(!N) printf("0");
     for(int i = F[N][0]; i >= 1; i--) printf("%d",F[N][i]);
     }
    
int main () {
    Init();
    while(cin >> N){
              printf("The Fibonacci number for %d is ",N);
              Print(N);
              printf("\n");
              }
    return 0;
    }
