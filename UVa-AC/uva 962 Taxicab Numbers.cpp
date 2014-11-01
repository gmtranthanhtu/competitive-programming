/*
  Name: UVa 962 Taxicab Numbers
  Copyright: 
  Author: 3T
  Date: 31/05/11 02:28
  Description: Taxicab Numbers, too slow, need to optimize
*/
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;


#define MAX 1000100000

int N, R, Num, So, u, v, t, Num2, k(0);
int Cube[1005], Ans[1000000];
bool B[MAX] = {0};
int Found[100000];
bool Use[2000];

void Gen() {
    Num = 0;
    for(int i = 1; i * i * i <= MAX; i++){Num++; Cube[Num] = i * i * i;}
    }
    
void Sort(){
     for(int i = 1; i < k; i++){
             for(int j = i + 1; j <= k; j++){
                     if(Found[i] > Found[j]) swap(Found[i], Found[j]);
                     }
             }
     }
     
void Gen2(){
     for(int i = 1; i < Num; i++){
             for(int j = i + 1; j <= Num; j++){
                     if(Cube[i] + Cube[j] > MAX) continue;
                     int Tmp = Cube[i] + Cube[j];
                     if(!B[Tmp]){
                                B[Tmp] = true;
                                }
                     else{
                          k++;
                          Found[k] = Tmp;
                          }
                     }
             }
     Sort();
     Use[1] = true;
     for(int i = 2; i <= k; i++){
             if(Found[i] == Found[i - 1]) Use[i] = false;
             else Use[i] = true;
             }
     }  
  

int main () {
    Gen();
    Gen2();
    while(scanf("%d",&N) != EOF){
         scanf("%d",&R);
         u = 0;
         for(int i = 1; i <= k; i++){
                 if(Found[i] <= N + R && Found[i] >= N && Use[i]) {printf("%d\n",Found[i]); u++;}
                 if(Found[i] > N + R) break;
                 }                
         if(u == 0) printf("None\n");
         }
    return 0;
    }
