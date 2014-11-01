/*
  Name: UVa 10295 Hay Points
  Copyright: 
  Author: 3T
  Date: 14/09/10 01:13
  Description: brute force, dictionary
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

#define INP "10295.INP"
#define OUT "10295.OUT"

int m, n, a;
long Total;
string line;
map <string, int> Hay;

int main () {
   // freopen(INP, "r", stdin);
   // freopen(OUT, "w", stdout);
    scanf("%d %d", &m, &n);
    //cin >> line;
  //  cout << line << endl;
    for(int i = 1; i <= m; i++){
            cin >> line;
         //   cout << line << endl;
            cin >> a;
          //  cout << a << endl;
            Hay[line] = a;
            }
    for(int i = 1; i <= n; i++){
            Total = 0;
            while(cin >> line && line.compare(".") != 0){
                      Total += Hay[line];
                      }
            cout << Total << endl;
            }
    return 0;
    }
