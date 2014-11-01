/*
  Name: UVa 101 The Blocks Problem
  Copyright: 
  Author: 3T
  Date: 08/11/10 14:07
  Description: adhoc, stack
*/
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <stack>

using namespace std;

int a, b, n, IsAt[26];
char line[50], Opa[10], Opb[10];
stack <int> S[26];
stack <int> STemp;

// moveOnto
void moveOnto(int s, int d){
     if(s == d) return;
     int Sat = IsAt[s];
     int Dat = IsAt[d];
     if(Sat == Dat) return;
     //remove top d
     while(S[Dat].top() != d){
                        int Tmp = S[Dat].top();
                        S[Dat].pop();
                        S[Tmp].push(Tmp);
                        IsAt[Tmp] = Tmp;
                        }
     while(S[Sat].top() != s){
                        int Tmp = S[Sat].top();
                        S[Sat].pop();
                        S[Tmp].push(Tmp);
                        IsAt[Tmp] = Tmp;                        
                        }
     S[Sat].pop();
     S[Dat].push(s);
     IsAt[s] = Dat;
     }
     
//moveOver
void moveOver(int s, int d){
     if(s == d) return;
     int Sat = IsAt[s];
     int Dat = IsAt[d];
     if(Sat == Dat) return;

     while(S[Sat].top() != s){
                        int Tmp = S[Sat].top();
                        S[Sat].pop();
                        S[Tmp].push(Tmp);
                        IsAt[Tmp] = Tmp;                        
                        }
     S[Sat].pop();
     S[Dat].push(s);
     IsAt[s] = Dat;     
     }
     
//pileOnto
void pileOnto(int s, int d){
     if(s == d) return;
     int Sat = IsAt[s];
     int Dat = IsAt[d];
     if(Sat == Dat) return;
     //remove top d
     while(S[Dat].top() != d){
                        int Tmp = S[Dat].top();
                        S[Dat].pop();
                        S[Tmp].push(Tmp);
                        IsAt[Tmp] = Tmp;
                        }
     //top s?
     while(S[Sat].top() != s){
                        int Tmp = S[Sat].top();
                        S[Sat].pop();
                        STemp.push(Tmp);
                        IsAt[Tmp] = Dat;                        
                        }
     S[Sat].pop();
     S[Dat].push(s);
     IsAt[s] = Dat;
     //move from Temp to Dat
     while(!STemp.empty()) {
                           int Tmp = STemp.top();
                           STemp.pop();
                           S[Dat].push(Tmp);
                           }    
     }
     
//pile over
void pileOver(int s, int d){
     if(s == d) return;
     int Sat = IsAt[s];
     int Dat = IsAt[d];
     if(Sat == Dat) return;
     //top s?
     while(S[Sat].top() != s){
                        int Tmp = S[Sat].top();
                        S[Sat].pop();
                        STemp.push(Tmp);
                        IsAt[Tmp] = Dat;                        
                        }
     S[Sat].pop();
     S[Dat].push(s);
     IsAt[s] = Dat;
     //move from Temp to Dat
     while(!STemp.empty()) {
                           int Tmp = STemp.top();
                           STemp.pop();
                           S[Dat].push(Tmp);
                           }      
     }

int main () {
    //freopen("101.INP", "r", stdin);
    //freopen("101.OUT", "w", stdout);
    scanf("%d",&n);
    scanf(" ");
    for(int i = 0; i < n; i++){
            S[i].push(i);
            IsAt[i] = i;
            }
    while(1){
             gets(line);
             if(strcmp(line, "quit") == 0) break;
             sscanf(line, "%s %d %s %d", &Opa, &a, &Opb, &b);
             if(strcmp(Opa, "move") == 0){
                            if(strcmp(Opb, "onto") == 0) moveOnto(a, b);
                            else moveOver(a, b);
                            }
             else{
                  if(strcmp(Opb, "onto") == 0) pileOnto(a, b);
                  else pileOver(a, b);
                  }
             }
    //output
    for(int i = 0; i < n; i++){
            printf("%d:", i);
            while(!S[i].empty()){
                                 int Tmp = S[i].top();
                                 S[i].pop();
                                 STemp.push(Tmp);
                                 }
            while(!STemp.empty()){
                                 int Tmp = STemp.top();
                                 STemp.pop();
                                 printf(" %d",Tmp);
                                 }
            printf("\n");
            }
    return 0;
    }
