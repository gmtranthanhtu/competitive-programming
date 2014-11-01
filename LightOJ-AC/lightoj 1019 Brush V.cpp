/*
  Name: LightOJ 1019 Brush(V)
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 26/10/2012
  Description: dijsktra
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

int n, t, m, a, b, c[111][111], u, v, w, d[111];
bool Free[111];

void dij(){
    memset(d, INF, sizeof d);
    FOR(i,1,n) d[i] = INF;
    d[1] = 0;
    memset(Free, true, sizeof Free);
    
    while(1){
        int u = -1, Min = INF;
        FOR(i,1,n){
            if(Free[i] && d[i] < Min){
                u = i;
                Min = d[i];    
            }    
        }    
        if(u == -1 || u == n) break;
        Free[u] = false;
        FOR(i,1,n){
            if(c[u][i] != INF && u != i && Free[i] && d[i] > d[u] + c[u][i]){
                d[i] = d[u] + c[u][i];    
            }    
        }
    }    
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    scanf("%d", &t);
    FOR(i,1,t){
        scanf("%d%d", &n,&m);
        memset(c,INF,sizeof c);
        while(m--){
            scanf("%d%d%d", &u, &v, &w);
            c[u][v] = c[v][u] = min(c[u][v], w);    
        }   
        FOR(j,1,n) c[j][j] = 0; 
        dij();
        if(d[n] == INF) printf("Case %d: Impossible\n", i);
        else printf("Case %d: %d\n", i, d[n]);
    }

    return 0;
}
