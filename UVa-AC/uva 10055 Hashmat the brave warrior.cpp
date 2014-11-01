/*
  Name: UVa 10055 Hashmat the brave warrior
  Copyright: 
  Author: 3T
  Date: 30/05/10 01:02
  Description: 
*/
#include <stdio.h>
#include <stdlib.h>

int main (){
    long a,b,c;
    while(scanf("%ld%ld",&a,&b) == 2){
         c = (a > b) ? a - b : b - a;
         printf("%ld\n",c);                     
         }
    return 0;
    }
