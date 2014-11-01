/*
  Name: UVa 10790 How many points of intersections
  Copyright: 
  Author: 3T
  Date: 24/05/11 01:02
  Description: combinatory
*/
#include <stdio.h>
#include <iostream>

using namespace std;

#define ll long long

int Case;
ll a, b;
ll Ans;


int main () {
    Case = 0;
    while((cin >> a >> b) && a){
        Case++;
        Ans = ((a * (a - 1)) / 2) * ((b * (b - 1)) / 2);
        cout << "Case " << Case << ": " << Ans << endl;
        }
    return 0;
    }
