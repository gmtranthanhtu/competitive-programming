/*
  Name: UVa 10954 Add All
  Copyright: 
  Author: 3T
  Date: 03/09/10 22:33
  Description: greedy
*/
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int main () {
    FILE *f = stdin;
    int N,a,b,R;
    while(fscanf(f, "%d", &N) && N){
         priority_queue <int> Q;
         R = 0;
         for(int i = 1; i <= N; i++){
                 fscanf(f,"%d",&a);
                 Q.push(-a);
                 }         
         while(Q.size() > 1){
              a = Q.top(); Q.pop();
              b = Q.top(); Q.pop();
              Q.push(a + b);  
              R = R + a + b;        
              }  
         printf("%d\n",-R);
         }

    return 0;
    }
