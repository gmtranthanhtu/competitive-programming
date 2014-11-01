/*
  Name: UVa 11015 Rendezvous
  Copyright: 
  Author: 3T
  Date: 21/12/10 01:26
  Description: Floyd
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

#define BIG 199999999

map <int, string> mymap;
int Ans, Min, u, v, w, N, M, Case(1), C[50][50];
string S;

int main () {
    //freopen("11015.INP", "r", stdin); freopen("11015.OUT", "w", stdout);
    while(scanf("%d%d",&N,&M) && N){
        scanf(" ");
        for(int i = 1; i <= N; i++){
            cin >> S;
            mymap[i] = S;
            }
        //init
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                C[i][j] = BIG;
                }
            C[i][i] = 0;
            }
        for(int i = 1; i <= M; i++){
            scanf("%d%d%d",&u,&v,&w);
            C[u][v] = C[v][u] = w;
            }
        //Floyd
        for(int i = 1; i <= N; i++)
           for(int j = 1; j <= N; j++) 
               for(int k = 1; k <= N; k++){
                    C[j][k] = min(C[j][k], C[j][i] + C[i][k]);
                    }   
        Min = BIG;
        for(int i = N; i >= 1; i--){
            //tim tong
            int Sum = 0;
            for(int j = 1; j <= N; j++){
                Sum += C[i][j];
                }
            if(Sum <= Min){
                Ans = i;
                Min = Sum;
                }
            }
        printf("Case #%d : ", Case++);
        cout << mymap[Ans] << endl;
        }
    
    return 0;
    }
