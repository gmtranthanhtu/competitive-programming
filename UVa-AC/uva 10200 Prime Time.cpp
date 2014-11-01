#include <stdio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX 10000

int prime[MAX + 5];
int a, b;
//int DP[MAX + 5][MAX + 5];

bool isPrime(long t){
     if(t == 1) return false;
     if(t == 2) return true;
     if(t % 2 == 0) return false;
     for(int i = 3; i * i <= t; i += 2){
             if(t % i == 0) return false;
             }
     return true;
     }

void Init(){
     for(int i = 0; i < 40; i++) prime[i] = 1;
     for(int i = 40; i <= MAX; i++){
             long Tmp = i * i + i + 41;
             if(isPrime(Tmp))
             prime[i] = 1;
             else prime[i] = 0;
             }
     //DP
//     for(int i = 0; i <= MAX; i++){
//             for(int j = i; j <= MAX; j++){
//                     if(i == j){
//                          if(prime[i]) DP[i][j] = 1;
//                          else DP[i][j] = 0;
//                          }
//                     else{
//                          if(prime[j]) DP[i][j] = DP[i][j - 1] + 1;
//                          else DP[i][j] = DP[i][j - 1];
//                          }
//                     }
//             }

     }

int main () {
    Init();
    while(cin >> a >> b){
//                    double N = (double)b - (double)a + 1.0;
//                    double Ans = ((double)DP[a][b] / N) * 100.0;
//                    printf("%.2lf\n",Ans + 0.000000001);

                     // double Ans = 100.00 * ((double) DP[a][b] / ((double) b - a + 1.0));
                      //printf("%.2lf\n", Ans);
                      int Count = 0, N = 0;
                      for(int i = a; i <= b; i++){
                              if(prime[i]) Count++;
                              N++;
                              }
                      double Ans = double(Count) / (double) N;
                      printf("%.2lf\n",Ans * 100.00 + 0.000000001);

                      }
    return 0;
    }
