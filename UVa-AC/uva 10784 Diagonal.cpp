#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int Case(1), Ans;
unsigned long long N;

int main () {
    while(cin >> N && N){
              double Tmp = (sqrt(8 * N + 9) + 3) / 2;
              Ans = (int) ceil(Tmp);
              printf("Case %d: %d\n",Case++,Ans);
              }
    return 0;
    }
