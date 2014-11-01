/*
  Name: LightOJ 1004 - Monkey Banana Problem 
  Author: 3T
  Date: 06-04-12 21:47
  Description: dp
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
#define MAXN 1000

#define INP ""
#define OUT ""

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int a, b, c, d, e, f, g, h, n;
int T, M[MAXN + 5][MAXN + 5], DP[MAXN + 5][MAXN + 5];

void readInput(){
    FOR(i, 1, h){
        if(i <= n){
            FOR(j, 1, i) scanf("%d", &M[i][j]);
        }
        else FOR(j, 1, h - i + 1) scanf("%d", &M[i][j]);
    }      
}

void dp(){
    memset(DP, 0, sizeof DP);
    DP[1][1] = M[1][1];
    FOR(i, 2, h){
        if(i <= n) e = -1;
        else e = 1;
        FOR(j, 1, n) DP[i][j] = max(DP[i - 1][j + e], DP[i - 1][j]) + M[i][j];
        }
    }

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    scanf("%d", &T);
    FOR(i, 1, T){
        scanf("%d", &n);
        h = 2 * n - 1;
        readInput();
        dp();
        printf("Case %d: %d\n", i, DP[h][1]);
    }
    return 0;
}
