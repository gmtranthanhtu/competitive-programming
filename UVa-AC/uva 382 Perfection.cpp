/*
  Name: UVa 382 Perfection
  Copyright: 
  Author: 3T
  Date: 08/11/10 14:42
  Description: perfect number 
*/
#include <stdio.h>

int n, a, M[105];

int Check(int N){
    if(N <= 5) return 1;
    int Sum = 1;
    for(int i = 2; i * i <= N; i++){
            if(N % i == 0){
                 if(i * i == N) Sum += i;
                 else{
                      Sum += i;
                      Sum += (N / i);
                      }
                 if(Sum > N) return 3;
                 }
            }
    if(Sum > N) return 3;
    if(Sum == N) return 2;
    else return 1;
    }

int main () {
    //freopen("382.INP", "r", stdin);
    //freopen("382.OUT", "w", stdout);
    n = 0;
    while(scanf("%d",&a) && a){
          M[++n] = a;               
          }
    printf("PERFECTION OUTPUT\n");
    for(int i = 1; i <= n; i++){
            printf("%5d  ", M[i]);
            int Ans = Check(M[i]);
            if(Ans == 2) printf("PERFECT\n");
            else if(Ans == 1) printf("DEFICIENT\n");
            else if(Ans == 3) printf("ABUNDANT\n");
            }
    printf("END OF OUTPUT\n");
    
    return 0;
    }
