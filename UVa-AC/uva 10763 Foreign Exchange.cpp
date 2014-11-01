/*
  Name: UVa 10763 Foreign Exchange
  Copyright: 
  Author: 3T
  Date: 05/11/10 01:45
  Description: sorting
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 500010
typedef struct Array{
        int Start, End;
        bool Dao;
        };
int N, a, b;
bool Check[MAX];
Array M[MAX];

bool myfun(const Array a, const Array b){
     if(a.Start < b.Start) return true;
     else if(a.Start == b.Start && a.End < b.End) return true;
     else if(a.Start == b.Start && b.End == a.End && !a.Dao && b.Dao) return true;
     return false;
     }
     
bool Yes(){
     for(int i = 1; i <= N; i++){
             //printf("Test: %d\n",i);
             if(Check[i]) continue;
             if(M[i].Dao) return false;
             bool Test = true;
             int j = i + 1;
             if(j > N) return false;
             while(M[j].Start == M[i].Start && M[j].End == M[i].End){
                              if(M[j].Dao && !Check[j]){
                                           Check[j] = true;
                                           Test = false;
                                           break;
                                           }
                              j++;
                              if(j > N) return false;
                              }
             if(Test) return false;
             }
     return true;
     }

int main () {
    while(scanf("%d",&N) && N){
           for(int i = 1; i <= N; i++){
                   Check[i] = false;
                   scanf("%d%d",&a,&b);
                   if(a < b){
                        M[i].Dao = false;
                        M[i].Start = a;
                        M[i].End = b;
                        } 
                   else{
                        M[i].Dao = true;
                        M[i].Start = b;
                        M[i].End = a;
                        }
                   }
           if(N % 2) {printf("NO\n"); continue;}
           sort(M + 1, M + N + 1, myfun);
           //for(int i = 1; i <= N; i++){
            //       printf("%d %d ",M[i].Start,M[i].End);
              //     printf(M[i].Dao ? "Dao\n" : "Ko\n");
              //     }
           printf(Yes() ? "YES\n" : "NO\n");              
           }
    return 0;
    }
