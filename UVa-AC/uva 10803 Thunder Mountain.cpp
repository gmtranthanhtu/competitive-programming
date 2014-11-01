/*
  Name: UVa 10803 Thunder Mountain
  Copyright: 
  Author: 3T
  Date: 21/12/10 09:57
  Description: Floyd
*/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;

#define BIG 199999999

double C[110][110];
double X[110], Y[110];
int T, N;

int main () {
    //freopen("10803.INP", "r", stdin); freopen("10803.OUT", "w", stdout);
    scanf("%d",&T);
    for(int c = 1; c <= T; c++){
        scanf("%d",&N);
        for(int i = 1; i <= N; i++){
            cin >> X[i] >> Y[i];
            }
        //Init
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(i == j) C[i][j] = 0.0;
                else{
                    double Tmp;
                    Tmp = hypot(X[i] - X[j], Y[i] - Y[j]);
                    if(Tmp <= 10.0) C[i][j] = Tmp;
                    else C[i][j] = BIG;
                    }
                }
            }
        //Floyd
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                for(int k = 1; k <= N; k++){
                    C[j][k] = min(C[j][k], C[j][i] + C[i][k]);
                    }
                }
            }
        double Max = -1000.0;
        bool Can = true;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(C[i][j] == BIG) Can = false;
                else Max = max(Max, C[i][j]);
                }
            }
        printf("Case #%d:\n",c);
        if(Can) printf("%.4lf\n\n",Max);
        else printf("Send Kurdy\n\n");
        }
    return 0;
    }
