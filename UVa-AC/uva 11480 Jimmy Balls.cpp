/*
  Name: UVa 11480 Jimmy Balls
  Copyright: 
  Author: 3T
  Date: 28/10/10 10:03
  Description: combinations, prove later
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 166670

int Case(1), N;
long long R;
long long M[MAX + 5];
void Init(){
     M[1] = 1;
     for(int i = 2; i <= MAX; i++) M[i] = M[i - 1] + i;
     }

void Cal(){
     R = 0;
     int p = N / 6;
     int m = N % 6;
     if(!m){
            R = M[p - 1] * 6 + 1;
            }
     else{
          R = M[p - 1] * 6  + m * p;
          }
     }

int main () {
    Init();
    while(scanf("%d",&N) && N){
                         Cal();
                         printf("Case %d: ",Case++);
                         cout << R << endl;
                         }
    return 0;
    }
