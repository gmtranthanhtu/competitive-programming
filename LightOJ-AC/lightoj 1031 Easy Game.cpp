/*
  Name: Light OJ 1031 - Easy Game 
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 30/10/2012
  Description: dp, game
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
#define MAXN 105
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

int n, t, m, a[MAXN], b, c, f[MAXN][MAXN][2];

int getSum(int x, int y){
    return a[y] - a[x-1];    
}

int cal(int x, int y, int w){
    if(x > y) return 0;
    if(f[x][y][w] != -INF) return f[x][y][w];
    if(!w){
        int tmp = -INF;
        FOR(i,0,y-x) tmp = max(tmp, getSum(x, x + i) + cal(x + i + 1, y, w^1));
        FOR(i,0,y-x) tmp = max(tmp, getSum(y - i, y) + cal(x, y - i - 1, w^1));
        return f[x][y][w] = tmp;        
    }   
    else{
        int tmp = INF;
        FOR(i,0,y-x) tmp = min(tmp, cal(x + i + 1, y, w^1));
        FOR(i,0,y-x) tmp = min(tmp, cal(x, y - i - 1, w^1));
        return f[x][y][w] = tmp;                     
    }
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    scanf("%d", &t);
    FOR(tt,1,t){
        scanf("%d", &n);
        FOR(i,0,n) a[i] = 0;
        FOR(i,0,n) FOR(j,0,n) REP(k,2) f[i][j][k] = -INF; 
        FOR(i,1,n) scanf("%d", &b), a[i] = a[i-1] + b;
        int tmp = cal(1, n, 0);
        printf("Case %d: %d\n", tt, 2 * tmp - a[n]);   
    }

    return 0;
}
