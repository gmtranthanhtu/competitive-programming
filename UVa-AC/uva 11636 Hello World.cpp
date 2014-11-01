/*
  Name: UVa 11636 Hello World
  Copyright: 
  Author: 3T
  Date: 05/07/10 01:34
  Description: math, log2
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N,Case(1),Result;

int main () {
    while(scanf("%d",&N) && N > 0){
          if(log2(N) == (int) log2(N)){
                  Result = (int) log2(N);
                  }
          else  Result = (int) log2(N) + 1;  
          printf("Case %d: %d\n",Case,Result);
          Case++;        
          }
    return 0;
    }
