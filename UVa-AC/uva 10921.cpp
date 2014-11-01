#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

int lena;
string a;

char Transform(char b){
     if(b == 'A' || b == 'B' || b == 'C') return '2';
     if(b == 'D' || b == 'E' || b == 'F') return '3';
     if(b == 'G' || b == 'H' || b == 'I') return '4';
     if(b == 'J' || b == 'K' || b == 'L') return '5';   
     if(b == 'M' || b == 'N' || b == 'O') return '6';
     if(b == 'T' || b == 'U' || b == 'V') return '8';  
     if(b == 'Q' || b == 'P' || b == 'R' || b == 'S') return '7';
     if(b == 'W' || b == 'X' || b == 'Y' || b == 'Z') return '9';
     else return b;
     }

int main () {
    while(getline(cin, a)){
         lena = a.length();
         for(int i = 0; i < lena; i++){
                 a[i] = Transform(a[i]);
                 }              
         cout << a << endl;
         }
    return 0;
    }
