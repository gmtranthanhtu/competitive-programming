/*
  Name: UVa 673 Parentheses Balance
  Copyright: 
  Author: 3T
  Date: 23/10/10 07:54
  Description: stack, string
*/
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;

int T;
char c, line[10];
string S;


char oppo(char c){
     if(c == ')') return '(';
     if(c == ']') return '[';
     }

bool Check(){
     int len = S.length(), lenv(0), lent(0);
     if(len % 2) return false;
     if(!len) return true;
     stack <char> ST;
     for(int i = 0; i < len; i++){
             if(S[i] == '(' || S[i] == '[') ST.push(S[i]);
             if(S[i] == ')' || S[i] == ']'){
                     if(ST.empty()) return false;
                     if(ST.top() != oppo(S[i])) return false;
                     ST.pop();
                     }
             }
     if(!ST.empty()) return false;
     return true;
     }

int main () {
    scanf("%d",&T);
    gets(line);
    for(int i = 1; i <= T; i++){
            getline(cin, S);
            printf(Check() ? "Yes\n" : "No\n");
            }
    
    return 0;
    }
