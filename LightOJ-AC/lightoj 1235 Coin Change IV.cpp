/*
  Name: LightOJ 1235 Coin Change IV
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 14/5/2012
  Description: binary search, bisection
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
#define MAXN 20000
#define MOD 1000000007

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, t, a[20], b[MAXN], c[MAXN], lb, lc, K;

int Pow3(int v){
    if(v == 0) return 0;
    int res = 1;
    FOR(i, 1, v) res *= 3;
    return res;    
}

int getSum(int bitmask, int st, int en, int len){
    int res = 0;
    int i = st;
    while(bitmask){
        res += (bitmask % 3) * a[i];
        bitmask /= 3;   
        i++;     
    }        
    return res;
}

int ok(){
    if(n == 1){
        if(a[1] == K || a[1] * 2 == K) return 1;
        return 0;    
    }
    int m = n/2;
    lb = Pow3(m) - 1; lc = Pow3(n - m) - 1;
    //fill b
    FOR(bitmask, 0, lb){
        b[bitmask] = getSum(bitmask, 1, m, m);    
    }
    //fill c
    FOR(bitmask, 0, lc) c[bitmask] = getSum(bitmask, m + 1, n, n - m);
    
    sort(b, b + lb + 1);
    
    FOR(i, 0, lc){
        int lo = 0, hi = lb, mi, tmp;
        while(lo <= hi){
            mi = (lo + hi) / 2;
            tmp = c[i] + b[mi];
            if(tmp == K) return 1;
            else if(tmp > K) hi = mi - 1;
            else lo = mi + 1;    
        }        
    }    
    return 0;    
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    scanf("%d", &t);
    FOR(i, 1, t){
        scanf("%d %d", &n, &K);
        FOR(j, 1, n) scanf("%d", &a[j]);
        printf("Case %d: %s\n", i, ok() ? "Yes" : "No");        
    } 
    return 0;
}
