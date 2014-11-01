/*
  Name: UVa 350 Pseudo-Random Numbers
  Copyright: 
  Author: 3T
  Date: 25/08/11 21:23
  Description: ad hoc
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

#define INP ""
#define OUT ""

int Case(0), Z, I, M, L, a[10005];

int findAns(){
    memset(a, 0, sizeof a);
    int n = 0;
    while(1){
             n++;
             int Tmp = (Z * L + I) % M;
             if(a[Tmp] != 0) return n - a[Tmp];
             a[Tmp] = n;
             L = Tmp;
             }
    }

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    while(scanf("%d %d %d %d",&Z, &I, &M, &L)){
                    if(Z == 0 && I == 0 && M == 0 && L == 0) break;
                    Case++;
                    printf("Case %d: %d\n",Case, findAns());
                    }
    
    return 0;
    }
