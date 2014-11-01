/*
  Name: UVa 11614 - Etruscan Warriors Never Play Chess
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 8/5/2012
  Description: binary search, math
  Time Limit: 1.000s
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
#define MAXN 10000000000LL

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int t, a, b, c;

uint64 n, ans;

void solve(){
    ans = 0;
    if(n == 0) {ans = 0; return;}
    uint64 lo = 0, hi = MAXN;
    while(lo <= hi){
        uint64 mi = (lo + hi) / 2;
        uint64 tmp = mi * (mi + 1) / 2;
        if(tmp == n) {ans = mi; return;}
        if(tmp > n) hi = mi - 1;
        else lo = mi + 1;    
    } 
    ans = hi;
    return;   
}

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    scanf("%d", &t);
    while(t--){
        cin >> n;
        solve();
        cout << ans << endl;    
    }
    return 0;
}
