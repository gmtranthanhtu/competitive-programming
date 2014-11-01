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
int cx, cy, cnt, n, m, vis[60][60], l;
vector <string> lv;

void dfs(int x, int y) {
    fr(i, y, m - 1) {
        if(lv[x][i] != 'X') break;
        if(!vis[x][i]) vis[x][i] = 1, dfs(x, i);
    }
    frr(i, y, 0) {
        if(lv[x][i] != 'X') break;
        if(!vis[x][i]) vis[x][i] = 1, dfs(x, i);
    }
    fr(i, max(0, x - l), min(n - 1, x + l)) {
        if(!vis[i][y] && lv[i][y] == 'X') vis[i][y] = 1, dfs(i, y);
    }
}

typedef struct ArcadeManao{
    int shortestLadder(vector <string> level, int coinRow, int coinColumn) {
        cx = coinRow; cy = coinColumn;
        n = level.size();
        m = level[0].length();
        lv = level;
        rep(len, n) {
            l = len;
            memset(vis, 0, sizeof vis);
            vis[n - 1][0] = 1;
            dfs(n - 1, 0);
            if(vis[cx - 1][cy - 1]) return len;
        }
    }
};
