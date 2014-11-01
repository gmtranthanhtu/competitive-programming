/*
  Name:  UVa 160 Factors and Factorials 
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 8/5/2012
  Description: math, prime, count factorial factor
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
#define MAXN 100

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, t, a, b, c, np, na;
int Prime[MAXN + 10], ans[MAXN + 10];

bool isPrime[MAXN + 10];

void Gen(){
    memset(isPrime, true, sizeof isPrime);
    for(int i = 2; i * i <= MAXN; i++){
        if(!isPrime[i]) continue;
        for(int j = i; j * i <= MAXN; j++){
            isPrime[i * j] = false;    
        }    
    } 
    np = 0;
    FOR(i, 2, MAXN){
        if(isPrime[i]) Prime[++np] = i; 
    }   
}

int countFactor(int p, int n){
    int res = 0;
    while(n){
        res += n/p;
        n /= p;    
    }    
    return res;
}

void solve(){
    memset(ans, 0, sizeof ans);
    FOR(i, 1, np){
        na = i;
        if(Prime[i] > n){
            na--;
            break;    
        }    
        ans[i] = countFactor(Prime[i], n);
    }        
}

void Print(){
    printf("%3d! =", n);
    FOR(i, 1, na){
        printf("%3d", ans[i]);
        if(i % 15 == 0 && i != na) printf("\n      ");     
    }    
    printf("\n");
}

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    Gen();
    while(scanf("%d", &n) && n){
        solve();    
        Print();
    }
    return 0;
}
