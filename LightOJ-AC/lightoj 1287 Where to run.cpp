/*
  Name: Light OJ 1287 - Where to Run
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 31/10/2012
  Description: dp bitmask, expected value, probability
  Time Limit: 2.000s
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

int n, t, m, a, b, c[15][15], vis[15][1<<15], u, v, w;
double f[15][1<<15];

int dfs(int node, int mask){
    if(mask == (1 << n) - 1){
        f[node][mask] = 0;
        return 1;    
    }    
    if(vis[node][mask]) return f[node][mask] > 1e-7;
    vis[node][mask] = 1;
    f[node][mask] = 5;
    int cnt = 0, tmp;
    REP(i,n){
        if(!(mask & (1 << i)) && c[node][i] != INF && dfs(i, mask | (1 << i))){
            tmp = mask | (1 << i);
            f[node][mask] += c[node][i] + f[i][tmp]; 
            cnt++;       
        }    
    }
    if(!cnt){
        f[node][mask] = 0;    
        return 0;        
    }
    else{
        f[node][mask] /= cnt;
        return 1;    
    }
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    scanf("%d", &t);
    FOR(tt, 1, t){
        scanf("%d%d", &n, &m);
        REP(i,n) REP(j,n) c[i][j] = INF;
        REP(i,m) scanf("%d%d%d", &u, &v, &w), c[u][v] = c[v][u] = w;
        memset(vis, 0, sizeof vis);
        //REP(i,n) REP(j,1<<15) f[i][j] = 0.0;  
        dfs(0,1);
        printf("Case %d: %.10lf\n", tt, f[0][1]);  
    }

    return 0;
}
