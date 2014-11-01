/*
  Name: Uva 11269 Setting Problems
  Copyright: 
  Author: 3T
  Date: 15/11/10 12:00
  Description: schedule problem, johnson's algorithm
*/
#include <stdio.h>
#include <algorithm>
using namespace std;

int N, a[5][50], t1, t2, Ans[50], S, D, Min, Who, w;
bool Used[50];

int main () {
    while(scanf("%d",&N) != EOF){
         for(int i = 1; i <= 2; i++)
             for(int j = 1; j <= N; j++){
                     scanf("%d",&a[i][j]);
                     Used[j] = false;
                     }               
         //sort the giai thuat johnson
         S = 0;
         D = N + 1;
         while(S + 1 != D){
                 //tim min
                 Min = 10000000;
                 for(int i = 1; i <= 2; i++){
                         for(int j = 1; j <= N; j++){
                                 if(!Used[j]){
                                              if(a[i][j] < Min){
                                                         Who = i;
                                                         Min = a[i][j];
                                                         w = j;
                                                         }
                                              }
                                 }
                         }
                 //gan vao bang ket qua
                 if(Who == 1){
                        S++;
                        Ans[S] = w;
                        Used[w] = true;
                        }
                 else{
                      D--;
                      Ans[D] = w;
                      Used[w] = true;
                      }
                 } 
         //tim tong thoi gian
         t1 = 0;
         t2 = 0;
         for(int i = 1; i <= N; i++){
                 t1 = t1 + a[1][Ans[i]];
                 t2 = max(t1, t2) + a[2][Ans[i]];
                 }
         printf("%d\n",t2);
         }
    
    return 0;
    }
