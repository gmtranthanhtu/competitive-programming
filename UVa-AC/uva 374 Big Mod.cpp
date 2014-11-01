#include <stdio.h>
#include <iostream>
using namespace std;

long B, P, M, Ans;

long BigMod(long a, long b, long c){
     if(a == 0) return 0;
     if(b == 0){
          if(c > 1) return 1; 
          else return 0; //check later
          }
     if(b % 2 == 0){
          long Tmp = BigMod(a, b / 2, c);
          return (Tmp * Tmp) % c;
          }
     else{
          return ((a % c) * BigMod(a, b - 1, c)) % c;
          }
     }

int main () {
    while(cin >> B >> P >> M){
              cout << BigMod(B, P, M) << endl;
              }
    return 0;
    }
