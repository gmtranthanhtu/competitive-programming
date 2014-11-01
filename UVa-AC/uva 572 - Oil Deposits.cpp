/*
  Name: UVa 572 - Oil Deposits
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 8/5/2012
  Description: bfs, dfs
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
#define MAXN 100000

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, t, a, b, c, m, res;

char arr[105][105];
int X[]={8, -1, 0, 1, -1, 1, -1, 0, 1};
int Y[]={8, -1, -1, -1, 0, 0, 1, 1, 1};

bool ok(int x, int y){
    return (x >= 0 && x <= m && y >= 0 && y <= n);    
}

void delCell(int x, int y){
    arr[x][y] = '*';
    FOR(i, 1, 8){
        int xx = x + X[i], yy = y + Y[i];
        if(!ok(xx, yy)) continue;   
        if(arr[xx][yy] == '@') delCell(xx, yy); 
    }    
}

void solve(){
    res = 0;
    REP(i, m) REP(j, n){
        if(arr[i][j] == '@'){
            res++;
            delCell(i, j);    
        }    
    }        
    printf("%d\n", res);
}

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    while(scanf(" %d %d ", &m, &n) && m){
        REP(i, m) gets(arr[i]);
        solve();    
    }
    return 0;
}
