/*
  Name: UVa 11369 Sophaholic
  Copyright: 
  Author: 3T
  Date: 27/10/10 21:04
  Description: sort, ad hoc
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int T, N, R;
int M[20005];

bool myfun(const int a, const int b) {return (b < a);}

int main () {
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            scanf("%d",&N);
            for(int j = 1; j <= N; j++){
                    scanf("%d",&M[j]);
                    }
            R = 0;
            sort(M + 1, M + N + 1, myfun);
            for(int j = 3; j <= N; j +=3) R = R + M[j];
            printf("%d\n",R);
            }
    
    return 0;
    }
