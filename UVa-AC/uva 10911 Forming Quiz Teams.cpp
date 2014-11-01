/*
  Name: UVa 10911
  Copyright: 
  Author: 3T
  Date: 17-03-12 16:19
  Description: DP + bitmask
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>

using namespace std;

#define INP "10911.INP"
#define OUT "10911.OUT"
#define MAXN 65536
#define INF 9999999

char line[1000], name[1000];
int X[20], Y[20], a, b, N, Case(1);
double Dis[20][20], memo[MAXN + 5];

double matching(int bitmask){
    //calculated already
    if(memo[bitmask] > -0.1) return memo[bitmask];
    
    if(bitmask == (int) (pow(2.0, 2.0 * N) - 1)){
        return memo[bitmask] = 0;
        }
        
    double Min = INF;
    for(int i = 0; i < 2 * N; i++){
        if(!(bitmask & (1 << i))){
            for(int j = i + 1; j < 2 * N; j++){
                if(!(bitmask & (1 << j))){
                    Min = min (Min, Dis[i][j] + matching(bitmask | (1 << i) | (1 << j)));
                    }
                }
           // break;
            }
        }
    return memo[bitmask] = Min;
    }

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    while(sscanf(gets(line), "%d", &N) && N){
        for(int i = 0; i < 2 * N; i++){
            sscanf(gets(line), "%s %d %d", &name, &X[i], &Y[i]);
            }
        
        //calculate all distances
        for(int i = 0; i < 2 * N; i++){
            for(int j = i + 1; j < 2 * N; j++){
                Dis[i][j] = Dis[j][i] = hypot(X[i] - X[j], Y[i] - Y[j]);
                }
            }
        
        memset(memo, -1, sizeof memo);
        printf("Case %d: %.2lf\n", Case++, matching(0));
        }

    return 0;
    }
