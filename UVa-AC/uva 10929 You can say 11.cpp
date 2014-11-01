/*
  Name: UVa 10929 YOu can say 11
  Copyright: 
  Author: 3T
  Date: 16/11/10 15:58
  Description: an integer is said to be divisible by 11 when difference between sum of its odd-position-digit
               and sum of its even-position-digit is divisible by 11   
*/
#include <stdio.h>
#include <string.h>

char S[1005];

bool Check(){
     int Sum[5];
     Sum[0] = 0;
     Sum[1] = 0;
     int t = 0;
     int len = strlen(S);
     for(int i = 0; i < len; i++){
             int Tmp = S[i] - 48;
             Sum[t] += Tmp;
             t = (t ? 0 : 1);
             }
     int d = Sum[0] - Sum[1];
     if(d < 0) d *= -1;
     if(d % 11) return false;
     return true;
     }

int main  () {
    while(gets(S)){
         if(!strcmp(S,"0")) break;
         printf("%s ",S);
         printf(Check() ? "is a multiple of 11.\n" : "is not a multiple of 11.\n");          
         }
    return 0;
    }
