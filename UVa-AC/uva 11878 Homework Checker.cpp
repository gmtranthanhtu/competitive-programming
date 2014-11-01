/*
  Name: UVa 11878 Homework Checker
  Copyright: 
  Author: 3T
  Date: 01/11/10 01:41
  Description: ad hoc
*/
#include <stdio.h>
#include <string.h>

int R,a,b, Ans;
char Op,S[1000], An[1000];

int getAns(){
    if(Op == '+') return a + b;
    return a - b;
    }

int main () {
    R = 0;
    while(scanf("%s",&S) != EOF){
        sscanf(S,"%d%c%d=%s",&a,&Op,&b,&An);     
        if(An[0] == '?') continue;
        sscanf(An, "%d", &Ans);
        if(Ans == getAns()) R++;   
        }
                printf("%d\n",R); 
    return 0;
    }
