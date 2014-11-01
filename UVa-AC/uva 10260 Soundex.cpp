/*
  Name: UVa 10260 Soundex
  Copyright: 
  Author: 3T
  Date: 18/09/10 19:13
  Description: map, string, brute force
*/
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>

using namespace std;
string S, R, L, Tmp;
map <char, string> M;

void Init(){
     M['P'] = M['F'] = M['B'] = M['V'] = "1";
     //2 represents C, G, J, K, Q, S, X,  or Z
     M['C'] = M['G'] = M['J'] = M['K'] = M['Q'] = M['S'] = M['X'] = M['Z'] = "2";
     M['D'] = M['T'] = "3";
     M['L'] = "4";
     M['M'] = M['N'] = "5";
     M['R'] = "6";
     }

int main () {
    Init();
    while(getline(cin, S)){
         R = "";
         L = "aaa";
         for(int i = 0; i < S.length(); i++){
                 Tmp = M[S[i]];
                 if(Tmp.compare(L)) R += Tmp;
                 L = Tmp;
                 }            
         cout << R << endl;  
         }
    return 0;
    }
