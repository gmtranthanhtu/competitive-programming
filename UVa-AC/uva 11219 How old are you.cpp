/*
  Name: UVa 11219 How old are you
  Copyright: 
  Author: 3T
  Date: 06/10/10 04:19
  Description: ad hoc
*/
#include <stdio.h>
#include <stdlib.h>

int Cd, Cm, Cy, Bd, Bm, By, Age, T;

int calAge(){
    int A = Cy - By;
    if(Cm < Bm || (Cm == Bm && Cd < Bd)) A--;
    return A;
    }

int main () {
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            scanf("%d/%d/%d",&Cd,&Cm,&Cy);
            scanf("%d/%d/%d",&Bd,&Bm,&By);
          
            printf("Case #%d: ",i);
            int Age = calAge();
            if(Age < 0) printf("Invalid birth date\n");
            else if(Age > 130) printf("Check birth date\n");
            else printf("%d\n",Age);
            }
    return 0;
    }
