/*
  Name: Uva 11774 Doom's Day
  Copyright: 
  Author: 3T
  Date: 20/04/10 01:58
  Description: Euclidean, math
*/
#include <stdio.h>
#include <stdlib.h>

int n,m,T;

int GCD(int a, int b){
    if(a < b) return GCD(b,a);
    else if(b == 0) return a;
    else return GCD(b, a % b);
}

int Doom(int a, int b){
    if(a == b) return 2;
    else{
         int gcd = GCD(a,b);
         if(gcd == 1) return a + b;
         a = a / gcd;
         b = b / gcd;
         return Doom(a,b);
         } 
    }

int main () {
    scanf("%d",&T);
    for(int k = 1; k <= T; k++){
    scanf("%d%d",&m,&n);
    printf("Case %d: %d\n",k,Doom(m,n)); 
}
    return 0;
    }
