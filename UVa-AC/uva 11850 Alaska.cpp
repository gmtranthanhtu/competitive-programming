/*
  Name: UVa 11850 Alaska 
  Copyright: 
  Author: 3T
  Date: 04/10/10 03:09
  Description: DP
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int S[1500];
int n;

bool Check(){
     if(S[1] != 0) return false;
     if( 2 * (1422 - S[n]) > 200) return false;
     int t = 1;
     while(t <= n - 1){
             if(S[t + 1] - S[t] > 200) return false;
             t++;
             }
     
     return true;
     }

int main () {
    while(scanf("%d",&n) && n){
          for(int i = 1; i <= n; i++) scanf("%d",&S[i]);
          sort(S + 1, S + n + 1);
          printf(Check() ? "POSSIBLE\n" : "IMPOSSIBLE\n");               
          }
    return 0;
    }
