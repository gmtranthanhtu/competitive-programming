/*
  Name: UVa 944 Happy Numbers
  Copyright: 
  Author: 3T
  Date: 24/07/11 00:15
  Description: DP, math
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 99999

int Happy[MAXN + 5], It[MAXN + 5], Path[MAXN], t, L, H, Case(0); 

int getSumDigit(int i){
    int R = 0;
    while(i != 0){
            int m = i % 10;
            R += (m * m);
            i /= 10;
            }
    return R;
    }
    
bool checkCycle(int a){
     for(int i = 1; i <= t; i++) if(Path[i] == a) return true;
     return false;
     }

int calIt(int i){
     int Tmp = getSumDigit(i);
     if(checkCycle(Tmp)){
                  Happy[i] = Happy[Tmp] = 2;
                  return 0;
                  }
     t++;
     Path[t] = Tmp;
     
     if(Tmp > MAXN){
            int b = calIt(Tmp);
            if(b != 0) return b + 1;
            else return b;
            }
     else{
          if(Happy[Tmp] == 1){
                        Happy[i] = 1;
                        It[i] = 1 + It[Tmp];
                        return It[i];
                        }
          else if(Happy[Tmp] == 2){
               Happy[i] = 2;
               return 0;
               }
          else{
               int a = calIt(Tmp);
               if(a == 0){
                    Happy[i] = 2;
                    return 0;
                    }
               else{
                    Happy[i] = 1;
                    It[i] = a + 1;
                    return It[i];
                    }
               }
          }
     }

void Gen(){
     memset(Happy, 0, sizeof Happy);
     memset(It, 0, sizeof It);
     
     Happy[1] = 1; It[1] = 1; Happy[7] = 1; It[7] = 6;
     for(int i = 2; i <= MAXN; i++){
             if(!Happy[i]){
                        t = 1;
                        Path[t] = i;
                        int a = calIt(i);   
                        if(a == 0){
                             Happy[i] = 2;
                             }            
                        else{
                             Happy[i] = 1;
                             It[i] = a;
                             }   
                        t = 0;      
                        }
             }
     }
     

int main () {
    //freopen("944.INP", "r", stdin); freopen("944.OUT", "w", stdout);
    Gen();
    while(scanf("%d%d",&L,&H) != EOF){
            Case++;
            if(Case > 1) printf("\n");
            for(int i = L; i <= H; i++){
                    if(Happy[i] == 1){
                                printf("%d %d\n",i,It[i]);
                                }
                    }                  
            }
    
    return 0;
    }
