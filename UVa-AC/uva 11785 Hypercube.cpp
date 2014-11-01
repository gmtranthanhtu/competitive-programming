/*
  Name: UVa 11785 Hypercube
  Copyright: 
  Author: 3T
  Date: 01/05/10 07:20
  Description: 
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MaxNode 1024
int M,K,i,j,n,m,check,count;
int u,v;
int OK2[MaxNode];


bool Test2(){
     for(int i = 0; i < K; i++){
             if(OK2[i] != n) return false;
             }
     return true;
     }

//bool Log(int a){
//    for(int d = 0; d <= 10; d++){
//            if((int)pow(2,d) == a) return true;
//            }
//    return false;
//    }

bool OK(int b, int c){
     bool differ = false;
     while(b != 0 || c != 0){
             if(b%2 != c%2){
                    if(differ == false) differ = true;
                    else{
                         return false;
                         }
                    }
             b = (int) b / 2;
             c = (int) c / 2;
             }
     return true;
     }

int main (){
    while(scanf("%d%d",&K,&M) && K != 0){
    bool yes = true;
    int count = 0;
    n = log(K) / log(2);
    check = (n * K) / 2;
    if(check != M) yes = false;
          for(int i = 0; i < M; i++){
                  scanf("%d%d",&u,&v);
                  if(u >= K || v >= K || u == v){
                       yes = false;
                       }
                  else{
                       if(yes){
                       OK2[u]++;
                       OK2[v]++;
                       if(OK(u,v)) count++;
                       else yes = false;
                               }
                       }
                  }
          if(yes){
                  if(!Test2()) printf("YES\n");
                  }
          else printf("NO\n");
          }
    return 0;
    }
