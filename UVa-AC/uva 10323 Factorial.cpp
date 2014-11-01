/*
  Name: UVa 10323 Factorial
  Copyright: 
  Author: 3T
  Date: 14/09/10 02:47
  Description: 
*/
#include <stdio.h>
#include <stdlib.h>

int main (){
    char Ans[6][12] = {"40320", "362880", "3628800", "39916800", "479001600", "6227020800"};
    int n;
    while(scanf("%d", &n) != EOF){
           if(n < 0){
                if(n % 2) printf("Overflow!\n");
                else printf("Underflow!\n");
                }
           else if(n < 8) printf("Underflow!\n");    
           else if(n > 13) printf("Overflow!\n");   
           else printf("%s\n",Ans[n - 8]);    
           }
    return 0;
    }
