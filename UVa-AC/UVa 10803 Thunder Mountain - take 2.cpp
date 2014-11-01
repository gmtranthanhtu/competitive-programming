/*
  Name: UVa 10803 Thunder Mountain
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 24/5/2012
  Description: floyd
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
#define INF 100011122234.23
#define EPS 1e-7
#define MAXN 200
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

int n, t, a, b, c;

double V[MAXN][MAXN], ans;
vii point;

void solve(){
    REP(i, n){
        FOR(j, i + 1, n) {V[i][j] = V[j][i] = hypot(point[i].ff - point[j].ff, point[i].ss - point[j].ss);if (V[i][j] > 10) V[i][j] = V[j][i] = INF;}
        V[i][i] = 0.0;    
    }    
    REP(i, n)
        REP(j, n)
            REP(k, n)
                V[j][k] = min(V[j][k], V[j][i] + V[i][k]);
    ans = -1;
    REP(i, n) REP(j, n) ans = max(ans, V[i][j]);
    if(ans == INF) {printf("Send Kurdy\n\n"); return;}
    printf("%.4lf\n\n", ans);
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    scanf("%d", &t);
    FOR(i, 1, t){
        scanf("%d", &n);
        point.resize(0);
        FOR(j, 1, n) scanf("%d %d", &a, &b),point.pb(ii(a, b));  
        printf("Case #%d:\n", i);
        solve();
    }

    return 0;
}
