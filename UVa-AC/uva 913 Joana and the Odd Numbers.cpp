#include <stdio.h>
#include <iostream>
using namespace std;

long long a1, a, Row, N, R, Ans, d; 

int main () {
    d = 12;
    a = 15;
    a1 = 30;
    while(cin >> N){
              Row = (N + 1) / 2;
              if(Row == 2) cout << a << endl;
              else{
                   R = Row - 2;
                   Ans = (R * (2 * a1 + (R - 1) * d)) / 2;
                   Ans = Ans + a;
                   cout << Ans << endl;
                   }
              }
    return 0;
    }
