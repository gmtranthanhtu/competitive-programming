/*
  Name: UVa 371	Ackermann Functions
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 8/5/2012
  Description: math, ad hoc, 
  Time Limit: 3.000s
*/

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

#define PI 3.1415926535897932385
#define INF 1000111222
#define EPS 1e-7
#define MAXN 100000

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, t, a, b, c;

int64 L, H, V, S;

int64 getS(int64 N){
    int64 res = 0LL;
    if(N % 2) N = N * 3 + 1;
    else N /= 2; 
    
    while(N != 1){
        if(N % 2) N = N * 3 + 1;
        else N /= 2;  
        res++;           
    }   
    res++;
    return res;
}

void solve(){
    S = -1;
    for(int64 i = min(L, H); i <= max(L, H); i++){
        int64 tmp = getS(i);
        if(tmp > S) {S = tmp; V = i;}    
    } 
    printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", min(L, H), max(L,H), V, S);   
}

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    while(cin >> L >> H){
        if(L == 0 && H == 0) break;
        solve();    
    }
    return 0;
}
