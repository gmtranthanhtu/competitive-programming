/*
  Name: CF 187C - Weak Memory 
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 12/5/2012
  Description: bfs, binary search
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
#define MAXN 100005

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, t, a, b, c, m, k, u, v, s, res, d[MAXN];

vi adj[MAXN];
bool volu[MAXN], Free[MAXN];

bool ok(int qq){ //bfs, revisit node i if d[i] changed. 
    queue <int> q;
    FOR(i, 1, n) d[i] = -1, Free[i] = true;
    d[s] = qq;
    q.push(s);
    while(!q.empty()){
        int x = q.front(); q.pop();
        if(x == t) return true;
        if(!Free[x] || d[x] <= 0) continue;
        Free[x] = false;
        REP(i, adj[x].size()){
            int y = adj[x][i]; int tmp = (volu[y]) ? qq : d[x] - 1;
            if(d[y] < tmp) d[y] = tmp, q.push(y), Free[y] = true;    
        }    
    }  
    return false;    
}

void solve(){
    int lo = 1, hi = n, res = -1, mi;
    while(lo <= hi){
        mi = (lo + hi)/2;
        if(ok(mi)){
            res = mi;
            hi = mi - 1;    
        }       
        else lo = mi + 1;
    }   
    
    printf("%d\n", res); 
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    scanf("%d %d %d", &n, &m, &k);
    FOR(i, 1, n) adj[i].clear(), volu[i] = false;  

    while(k--){
        scanf("%d", &a); volu[a] = true;      
    }
    while(m--){
        scanf("%d %d", &a, &b); adj[a].pb(b); adj[b].pb(a);    
    }
    scanf("%d %d", &s, &t);
    solve();
    
    return 0;
}
