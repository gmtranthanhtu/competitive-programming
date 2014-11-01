/*
  Name: CF 187B AlgoRace 
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 11/5/2012
  Description: dp, floyd warshall
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
#define MAXN 100000

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, a, b, c, m, r, s, t, u;

int arr[65][65][65], dp[65][65][65];

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    scanf("%d%d%d",&n,&m,&r);
    FOR(i, 0, n) FOR(j, 1, n) FOR(k, 1, n) dp[i][j][k] = INF;
    FOR(i, 1, m){
        FOR(j, 1, n) FOR(k, 1, n) scanf("%d", &arr[i][j][k]);
        FOR(j, 1, n) FOR(k, 1, n) FOR(l, 1, n) arr[i][k][l] = min(arr[i][k][l], arr[i][k][j] + arr[i][j][l] );
        FOR(j, 1, n) FOR(k, 1, n) dp[0][j][k] = min(dp[0][j][k], arr[i][j][k]);    
    }
    
    FOR(i, 1, n) FOR(j, 1, n) FOR(k, 1, n) FOR(l, 1, n) dp[i][k][l] = min(dp[i][k][l], dp[i - 1][k][j] + dp[0][j][l]);
    
    while(r--){
        scanf("%d%d%d", &s,&t,&u);
        u = min(u, n);
        printf("%d\n", dp[u][s][t]);    
    }

    return 0;
}
