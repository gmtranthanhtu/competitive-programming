/*
  Name: UVa 353 Pesky Palindromes
  Copyright: 
  Author: 3T
  Date: 25/08/11 21:42
  Description: ad hoc, string
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define INP "353.INP"
#define OUT "353.OUT"

string S;
string P[50000];
int N, len;

bool Palin(int i, int j){
     while(i < j){
             if(S[i] != S[j]) return false;
             i++;
             j--;
             }
     return true;
     }
     
bool Exist(string a){
     for(int i = 1; i <= N; i++){
             if(a == P[i]) return true;
             }
     return false;
     }

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    while(cin >> S){
              N = 0;
              len = S.length();
              for(int i = 0; i < len; i++){
                      for(int j = i; j < len; j++){
                              if(!Palin(i, j)) continue;
                              string a = S.substr(i, j - i + 1);
                              if(Exist(a)) continue;
                              N++;
                              P[N] = a;
                              }
                      }
              //for(int i = 1; i <= N; i++) cout << P[i] << endl;
              cout << "The string '" << S << "' contains " << N << " palindromes." << endl;
              }
    
    return 0;
    }
