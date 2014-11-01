/*
  Name: UVa 11532 Simple Adjacency Maximization
  Copyright: 
  Author: 3T
  Date: 12/07/10 03:41
  Description: DP, math
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;

unsigned long long M[51][51];

void Init(){
     for(int i = 0; i <= 50; i++) M[0][i] = 0;
     for(int i = 1; i <= 50; i++){
             unsigned long long Temp = (unsigned long long)pow(2, i - 1);
             M[i][0] = M[i - 1][0] + Temp;
             }
     int loop = 1, loope = 2, loopo = 0;
     for(int i = 1; i <= 50; i++){
             for(int j = 1; j <= 50; j++){
                     if(j < loop){
                          M[i][j] = M[i - 1][j] * 2 + 1;
                          }
                     else if(j == loop){
                          if(i % 2 != 0){
                               unsigned long long Temp = (unsigned long long)pow(2, loopo);
                               M[i][j] = M[i - 1][j] + Temp;
                               loopo += 3;
                               }
                          else{
                               unsigned long long Temp = (unsigned long long)pow(2, loope);
                               M[i][j] = M[i - 1][j] + Temp;
                               loope += 3;                               
                               }
                          }
                     else{
                          M[i][j] = M[i][loop];
                          }
                     }
             if(i % 2 == 0) loop++;
             }
     }

int main (){
    Init();
    int T,P,Q;
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            scanf("%d%d",&P,&Q);
            cout << M[P][Q] << endl;
//            printf("%I64u\n",M[P][Q]);
            }
    }
