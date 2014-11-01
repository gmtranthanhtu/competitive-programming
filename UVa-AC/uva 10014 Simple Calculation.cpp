/*
  Name: UVa 10014
  Copyright: 
  Author: 3T
  Date: 23/10/10 10:43
  Description: math
      //(n+1)A1 = nA0 + An+1 - 2Cn - 4Cn-1 - 6Cn-2 - ... - (2n)C1 
*/
#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int Case(1), T, N;
double R, a;

int main () {

    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            R = 0;
            scanf("%d",&N);
            scanf("%lf",&a); R += a * N;
            scanf("%lf",&a); R += a;

            int NN = 2 * N;
            for(int i = 1; i <= N; i++){
                    scanf("%lf",&a);
                    R -= NN * a;
                    NN -= 2;
                    }
            R /= (N + 1);
            if(Case > 1) printf("\n");
            Case++;
            printf("%.2lf\n",R);
            }
    
    return 0;
    }
