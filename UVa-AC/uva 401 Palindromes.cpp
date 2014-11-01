#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <map>

using namespace std;

#define INP ""
#define OUT ""	

map <char, char> R;
bool Palin, Mirror;
string S;

void Gen(){
     R['A'] = 'A'; R['E'] = '3'; R['H'] = 'H'; R['I'] = 'I'; R['J'] = 'L'; R['L'] = 'J';
     R['M'] = 'M'; R['O'] = 'O'; R['S'] = '2'; R['T'] = 'T'; R['U'] = 'U'; R['V'] = 'V';
     R['W'] = 'W'; R['X'] = 'X'; R['Y'] = 'Y'; R['Z'] = '5'; R['1'] = '1'; R['2'] = 'S';
     R['3'] = 'E'; R['5'] = 'Z'; R['8'] = '8';          
     }

void Process(){
     int L = 0, Ri = S.length() - 1; 
     Palin = true;
     Mirror = true;
     while(L <= Ri && (Palin || Mirror)){
             if(S[L] != S[Ri]) Palin = false;
             if(S[L] != R[S[Ri]]) Mirror = false;
             L++;
             Ri--;
             }
             
     cout << S << " -- ";
     if(!Palin && !Mirror) cout << "is not a palindrome." << endl;
     else if(!Palin && Mirror) cout << "is a mirrored string." << endl;
     else if(Palin && !Mirror) cout << "is a regular palindrome." << endl;
     else cout << "is a mirrored palindrome." << endl;
     cout << endl;
     }

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    
    Gen();
    while(cin >> S){
              Process();
              }
    return 0;
    }
