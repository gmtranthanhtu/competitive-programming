/*
  Name: TC SRM 576 div1 256 ArcadeManao
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 12/4/2013
  Description: dfs, brute force
  Time Limit: 2.000s
*/

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <vector>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

inline bool EQ(double a, double b) {return fabs(a - b) < 1e-9;}

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

template<typename T>inline T gcd(T a, T b){if (b == 0)return a;else return gcd(b, a % b);}
template<typename T>inline T lcm(T a, T b){return (a * b) / gcd(a, b);}

#define INF 1000111222
int cx, cy, cnt, n, m, N, t, d[3000];
iii a[3000];
vii adj[3000];

set <ii> S;

int dis(int u, int v) {
    if(a[u].ss.ff > a[v].ss.ss || a[u].ss.ss < a[v].ss.ff) return INF;
    return abs(a[u].ff - a[v].ff);
}

int dijs() {
    fr(i, 1, N) d[i] = INF;
    d[N] = 0;
    S.insert(mp(0, N));
    while(!S.empty()) {
        ii tmp = *S.begin();
        S.erase(tmp);
        int u = tmp.ss;
        if(u == t) return tmp.ff;
        rep(i, adj[u].size()) {
            int v = adj[u][i].ff, w = adj[u][i].ss;
            if(max(w, d[u]) < d[v]) {
                if(d[v] != INF) S.erase(mp(d[v], v));
                d[v] = max(w, d[u]);
                S.insert(mp(d[v], v));
            }
        }
    }
}

typedef struct ArcadeManao{
    int shortestLadder(vector <string> level, int coinRow, int coinColumn) {
        cx = coinRow; cy = coinColumn;
        n = level.size();
        m = level[0].length();
        N = 0;
        rep(i, n) {
            int st = -1, len = 0;
            char tmpch = '.';
            rep(j, m) {
                if(level[i][j] == '.' && tmpch == 'X'){
                    int x = i + 1, y1 = st + 1, y2 = st + len;
                    a[++N] = mp(x, mp(y1, y2));
                    if(cx == x && cy >= y1 && cy <= y2) t = N;
                    tmpch = '.'; st = -1;
                }
                else if(level[i][j] == 'X') {
                    if(tmpch == '.') st = j, tmpch = 'X', len = 1;
                    else len++;
                }
            }
            if(tmpch == 'X') {
                    int x = i + 1, y1 = st + 1, y2 = st + len;
                    a[++N] = mp(x, mp(y1, y2));
                    if(cx == x && cy >= y1 && cy <= y2) t = N;
                    tmpch = '.'; st = -1;
            }
        }

        fr(i, 1, N) fr(j, 1, N) {
            int tmp = dis(i, j);
            if(tmp != INF) adj[i].pb(mp(j, tmp));
        }

        int ans = dijs();
        return ans;
    }
};
