/*
  Name: UVa 10107 What's the median
  Copyright: 
  Author: 3T
  Date: 18/09/10 18:52
  Description: queue
*/
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

priority_queue <int, vector<int>, less<int> > MinQ;
priority_queue <int, vector<int>, greater<int> > MaxQ;
int N;

void Swap(){
     int a = MinQ.top(); MinQ.pop();
     int b = MaxQ.top(); MaxQ.pop();
     MinQ.push(b);
     MaxQ.push(a);
     }

int main () {
    while(scanf("%d", &N) != EOF){
           if(MinQ.size() == 0){
                          MinQ.push(N);
                          printf("%d\n",N);
                          }
           else if(MaxQ.size() == 0){
                MaxQ.push(N);
                printf("%d\n",(MaxQ.top() + MinQ.top()) / 2);
                if(MaxQ.top() < MinQ.top()) Swap();
                }
           else if(MinQ.size() == MaxQ.size()){
                if(N <= MinQ.top()){
                     MinQ.push(N);
                     printf("%d\n",MinQ.top());
                     }
                else{
                     MaxQ.push(N);
                     int a = MaxQ.top();
                     MaxQ.pop();
                     MinQ.push(a);
                     printf("%d\n",MinQ.top());
                     }
                }
           else if(MinQ.size() - MaxQ.size() == 1){
                if(N <= MinQ.top()){
                     MinQ.push(N);
                     int a = MinQ.top();
                     MinQ.pop();
                     MaxQ.push(a);
                     printf("%d\n",(MaxQ.top() + MinQ.top()) / 2);
                     }
                else{
                     MaxQ.push(N);
                     printf("%d\n",(MaxQ.top() + MinQ.top()) / 2);
                     }
                }
           }
    return 0;
    }
