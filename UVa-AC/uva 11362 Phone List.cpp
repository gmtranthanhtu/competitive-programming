/*
  Name: UVa 11362 Phone List
  Copyright: 
  Author: 3T
  Date: 07/12/10 11:12
  Description: string, ad hoc, sorting
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 10005

int T, N;
string S[MAX];

int Solve(){
    if(N == 1) return 1;
    for(int i = 1; i < N; i++){
        size_t F;
        F = S[i + 1].find(S[i]);
        if(F != string::npos) return 0;
        }
    return 1;
    }

int main () {
    //freopen("11362.INP", "r", stdin); freopen("11362.OUT", "w", stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        scanf(" ");
        for(int i = 1; i <= N; i++){
            cin >> S[i];
            }
        sort(S + 1, S + N + 1);
        int Ans = Solve();
        if(Ans) printf("YES\n");
        else printf("NO\n");
        }
    return 0;
    }
