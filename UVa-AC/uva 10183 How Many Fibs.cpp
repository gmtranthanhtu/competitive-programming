/*
  Name: UVa 10183 How many Fibs?
  Copyright: 
  Author: 3T
  Date: 29/06/11 20:16
  Description: fibonacci, big num
*/
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

typedef struct BigInt{
        int Num[200];
        int len;
        };
        
const BigInt Zero = {{0}, 1};
const BigInt One = {{1}, 1};
BigInt Fibo[700];
int FNum;



void addNum(BigInt &a, BigInt &b, BigInt &r){
     memset(r.Num, 0, sizeof r.Num);
     r.len = (a.len > b.len)? a.len : b.len;
     for(int i = 0; i < r.len; i++){
             r.Num[i] += a.Num[i] + b.Num[i];
             
             if(r.Num[i] >= 10){
                         r.Num[i + 1]++;
                         r.Num[i] -= 10;
                         }
             }
     if(r.Num[r.len]) r.len++;
     }

int cmpNum(BigInt &a, BigInt &b){ //return 1 if a > b
     if(a.len > b.len) return 1;
     if(a.len < b.len) return -1;
     for(int i = a.len - 1; i >= 0; i--){
             if(a.Num[i] > b.Num[i]) return 1;
             if(a.Num[i] < b.Num[i]) return -1;
             }
     return 0;
     }

void Gen(){
     FNum = 1;
     Fibo[0] = Fibo[1] = One;
     for(int i = 2; Fibo[i - 1].len <= 101; i++){
             addNum(Fibo[i - 2], Fibo[i - 1], Fibo[i]);
             FNum++;
             }
     }

int main (){
    //freopen("11388.INP", "r", stdin); freopen("11388.OUT", "w", stdout);
    Gen();
    string s1, s2;
    while(cin >> s1 >> s2){
              if(s1 == "0" && s2 == "0") break;
              
              int Ans = 0;
              BigInt aa, bb;
              memset(aa.Num, 0, sizeof aa.Num);
              memset(bb.Num, 0, sizeof bb.Num);       
              aa.len = s1.length(); 
              bb.len = s2.length();
              
              for(int i = aa.len - 1; i >= 0; i--){
                      aa.Num[i] = s1[aa.len - i - 1] - '0';
                      }  
              for(int i = bb.len - 1; i >= 0; i--){
                      bb.Num[i] = s2[bb.len - i - 1] - '0';
                      }                 
              
              for(int  i = 1; i <= FNum; i++){
                      if(cmpNum(bb, Fibo[i]) < 0) break;
                      if(cmpNum(aa, Fibo[i]) <= 0) Ans++; 
                      }  
              cout << Ans << endl;                      
              }
    return 0;
    }
