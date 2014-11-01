/*
  Name: UVa 11877 The Coca Store
  Copyright: 
  Author: 3T
  Date: 01/11/10 01:39
  Description: ad hoc, ANSI C
*/
#include <stdio.h>

int Emp, R;

int main () {
    while(scanf("%d",&Emp) && Emp){
          R = 0;
          while(Emp >= 3){
                    R += Emp / 3;
                    Emp = Emp / 3 + Emp % 3;
                    }                  
          if(Emp == 2) R++;
          printf("%d\n",R);
          }
    
    
    return 0;
    }
