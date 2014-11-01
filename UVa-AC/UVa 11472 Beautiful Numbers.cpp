/*
  Name: UVa 11472 - Beautiful Numbers
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 1/11/2012
  Description: dp + bitmask
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

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define debug(x) cout<<#x<<": "<<x<<endl

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
typedef vector<string> vs;

template<typename T>inline T gcd(T a, T b){if (b == 0)return a;else return gcd(b, a % b);}
template<typename T>inline T lcm(T a, T b){return (a * b) / gcd(a, b);}

int n, t, m, a, b, c, f[111][1<<10][11];

int solve(){
    if(!m) return 0;
    REP(i,m+1) REP(j, (1<<n)) REP(k,n) f[i][j][k] = 0;
    FOR(i,1,n-1) f[1][1<<i][i] = 1;
    FOR(i,2,m){
        REP(j,n){
            int h1 = j - 1, h2 = j + 1;
            if(h1 >= 0)
            REP(k, (1<<n)) f[i][k | (1<<j)][j] += f[i-1][k][h1], f[i][k | (1<<j)][j] %= MOD; 
            if(h2 < n)
            REP(k, (1<<n)) f[i][k | (1<<j)][j] += f[i-1][k][h2], f[i][k | (1<<j)][j] %= MOD;    
        }    
    }
    int ans = 0;
    FOR(i,1,m) REP(j,n) ans += f[i][(1 << n) - 1][j], ans %= MOD;
    return ans;
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        printf("%d\n", solve());    
    }

    return 0;
}
