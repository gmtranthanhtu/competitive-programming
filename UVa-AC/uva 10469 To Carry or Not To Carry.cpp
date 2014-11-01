/*
  Name: UVa 10469 To carry or not to carry
  Copyright: 
  Author: 3T
  Date: 03/11/10 06:11
  Description: bitwise operation
*/
#include <stdio.h>

long a, b;

int main (){
    while(scanf("%d%d",&a,&b) != EOF){
            printf("%ld\n",a ^ b);                  
            }
    return 0;
    }
