/*
  Name: UVa 11127 Triple - Free Binary Strings
  Copyright: 
  Author: 3T
  Date: 24/06/10 03:37
  Description: Backtracking
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

#define INP "11127.INP"
#define MAXLEN 30

int n,Case(1),Count;
char line[MAXLEN + 5],P[MAXLEN + 1],c;

bool checkPossible(int m){
     int a = (m + 1) / 3;
     if(a == 0) return true;
     bool result;
     for(int i = 1; i <= a; i++){
             result = false;
             int result2 = 0;
             for(int j = 0; j < i; j++){
                     if(result) break;
                     if(P[m - j] != P[m - j - i] || P[m - j - i] != P[m - j - i - i]) result = true;
                     else result2++;
                     }
             if(result2 == i) return false;
             }
     return result;
     }

void processBacktracking(int m){
     if(m == n) Count++;     
     else if(P[m] == '*'){
          P[m] = '1';
          if(checkPossible(m)){
                               processBacktracking(m + 1);
                               P[m] = '0';
                               }
          else{
               P[m] = '0';
               }
          if(checkPossible(m)){
                               processBacktracking(m + 1);
                               P[m] = '*';
                               }
          else{
               P[m] = '*';
               }
          }
     else{
          if(checkPossible(m)) processBacktracking(m + 1);
          }
     }

int main () {
 //   FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    while(fgets(line,MAXLEN + 5,f) && strlen(line) != 2){
          sscanf(line,"%d %s",&n,&P);
          Count = 0;
          processBacktracking(0);
          //output
          cout << "Case " << Case++ << ": " << Count << endl;               
          }
 //   getchar();
    return 0;
    }
