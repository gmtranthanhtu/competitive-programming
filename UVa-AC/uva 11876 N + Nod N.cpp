/*
  Name:  UVa 11876 - N + NOD (N)
  Copyright: 
  Author: 3T
  Date: 27/10/10 07:09
  Description: number theory
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 1000000
#define MAX2 64725

#define INP "I.INP"
#define OUT "I.OUT"

bool IsNOD[MAX + 5];  //---> what the fuck? 1st
int T,A,B,R; // ---> what the fuck? 2nd
int Divi[MAX + 5], Seq[MAX2 + 5], NumNOD[MAX];


int Count(int n)
{
   int p = 1;
   int Factor = 1;
   while (n % 2 == 0) {
      p++;
      n /= 2;
   }
   Factor *= p;
   for (int i = 3; i*i <= n; i+=2) {
      p = 1;
      while (n % i == 0) {
         p++;
         n /= i;
      }
      Factor *= p;
   }
   if (n > 1) Factor *= 2;
   return Factor;
}


void Init(){
         for(int i = 3; i <= MAX; i++) {
            Divi[i] = Count(i);
            IsNOD[i] = false;
            }
    IsNOD[1] = true; IsNOD[2] = true;
    Divi[1] = 1; Divi[2] = 2;
    Seq[1] = 1; 
    for(int k = 2; k <= 64725; k++) {
          Seq[k] = Seq[k - 1] + Divi[Seq[k - 1]];
          IsNOD[Seq[k]] = true;
          }
    //DP
    
    NumNOD[1] = 1;
    for(int i = 2; i <= MAX; i++){
            if(IsNOD[i]) NumNOD[i] = NumNOD[i - 1] + 1;
            else NumNOD[i] = NumNOD[i - 1];
            }
    //IsNOD[1] = true; IsNOD[2] = true; IsNOD[4] = true;
    //printf("%d\n",k);
    //for(int i = 1; i <= MAX; i++) printf("%d ", Divi[i]);
     }


int main () {
    //freopen(INP, "r", stdin);
    //freopen(OUT, "w", stdout);
    Init();
    //main
   // if(IsNOD[2]) printf("Buc minh\n");
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            scanf("%d%d",&A,&B);
            printf("Case %d: ",i);
//            if(A == B){
//                 if(IsNOD[A]) R = 1;
//                 else R = 0;
//                 printf("%d\n",R);
//                 continue;
//                 }
            if(A == 1) {printf("%d\n",NumNOD[B]); continue;}
            R = NumNOD[B] - NumNOD[A];
            if(IsNOD[A]) R++;
            printf("%d\n",R);
            }
    
    
    
    return 0;
    }
