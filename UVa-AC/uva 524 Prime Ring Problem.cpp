/*
  Name: UVa 524 Prime Ring Problem
  Copyright: 
  Author: 3T
  Date: 28/10/10 20:57
  Description: backtracking
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

int N, Case(1), Limit;
int Seq[20];
bool prime[35], Check[20];
string S[20];

void Init(){
     for(int i = 1; i <= 35; i++) prime[i] = false;
     prime[2] = prime[3] = prime[5] = prime[7] = prime[11] = prime[13] = true;
     prime[17] = prime[19] = prime[23] = prime[29] = prime[31] = true;
     }
     
void Print(int cur){
     S[cur].push_back('1');
     for(int i = 2; i <= Limit; i++){
             S[cur].push_back(' ');
             if(Seq[i] < 10) S[cur].push_back(Seq[i] + '0');
             else {S[cur].push_back(Seq[i] / 10 + '0'); S[cur].push_back(Seq[i] % 10 + '0');}
             }
     S[cur].push_back('\n');
     }
     
void backtrack(int cur, int Last, int n){
     if(n == Limit){
          if(prime[1 + Last])
          Print(cur);
          }
     else{
          for(int i = 2; i <= Limit; i++){
                  if(!Check[i] && prime[i + Last]){
                               Check[i] = true;
                               Seq[n + 1] = i;
                               backtrack(cur, i, n + 1);
                               Check[i] = false;
                               }
                  }
          }
     }
     
void Init2(){
     for(int i = 2; i <= 16; i++){
                 Limit = i;
                 S[i] = "";
                 if(i % 2) continue;
                 memset(Check, false, sizeof Check); Check[1] = true;
                 Seq[1] = 1;
                 backtrack(i, 1, 1);
         }
     }

int main () {
    //freopen("524.INP", "r", stdin);
    //freopen("524.OUT", "w", stdout);
    Init();
    Init2();
    while(scanf("%d",&N) != EOF){
            if(Case > 1) printf("\n");
            printf("Case %d:\n", Case++);
            if(N == 1){
                 printf("1\n");
                 }             
            else{
                 if(N % 2) continue;                 
                 cout << S[N];
                 }
            }
    
    return 0;
    }
