#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define BIG 2147483647


long long DP[250];
long long Mu10[]={1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int T, N, len;
char a[250];

long long Convert(int b, int c){
    long long R = 0;
    int t = c - b;
    for(int i = b; i <= c; i++){
        int Tmp = a[i] - 48;
        long long Tmp2 = Tmp * Mu10[t];
        R = R + Tmp2;
        t--;
        }
    return R;    
    }

long long runDP(int S){
     if(DP[S] != -1) return DP[S];
     if(S == len) return (a[S] - 48);
     if(a[S] == '0'){
             DP[S] = runDP(S + 1);
             return DP[S];
             }
    if(S + 8 >= len){
        DP[S] = Convert(S, len);
        return DP[S];
        }
    if(S + 9 == len){
        long long Tmp;
        Tmp = Convert(S, len);
        if(Tmp <= BIG){
            DP[S] = Tmp;
            return DP[S];
            }
        } 
     
     long long Max = -100000;
     for(int k = 0; k <= 9; k++){
             long long Tmp = Convert(S, S + k);
             if(Tmp <= BIG){
                    long long Tmp2 = Tmp + runDP(S + k + 1);
                    if(Tmp2 > Max) Max = Tmp2;
                    }
             } 
     DP[S] = Max;
     return DP[S];
     }

int main () {
    //freopen("258.INP", "r", stdin);
    //freopen("258.OUT", "w", stdout);
    scanf("%d",&T);
    scanf(" ");
  //  cout << T;
    for(int i = 1; i <= T; i++){
        gets(a);
        N = strlen(a);
        len = N - 1;
            for(int j = 0; j < N; j++) DP[j] = -1;

        cout << runDP(0) << endl;
        }
    return 0;
    }
