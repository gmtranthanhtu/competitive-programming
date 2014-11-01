/*
  Name: CF 234 Fence
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 18/10/2012
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

#define INP "input.txt"
#define OUT "output.txt"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;

template<typename T>inline T gcd(T a, T b){if (b == 0)return a;else return gcd(b, a % b);}
template<typename T>inline T lcm(T a, T b){return (a * b) / gcd(a, b);}

int n, t, m, a, b, c, dp[220][40005][2], h[222], sum[222], ans;

void solve(){
    memset(dp, INF, sizeof dp);
    if(h[1] <= a) dp[1][h[1]][0] = 0;
    if(h[1] <= b) dp[1][h[1]][1] = 0;
    FOR(i,2,n)
        FOR(k,0,1){
            m = (k == 0 ? a : b);
            FOR(j,0,m){
                if(j - h[i] >= 0) dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-h[i]][k]);
                if(sum[i] - j >= 0) dp[i][j][k] = min(dp[i][j][k], dp[i-1][sum[i] - j][k^1] + min(h[i], h[i-1]));    
            } 
        }
     ans = INF;
     FOR(j,0,max(a,b)) FOR(k,0,1) ans=min(ans, dp[n][j][k]);       
           
}

int main () {
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    
    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    FOR(i,1,n) scanf("%d", &h[i]);
    memset(sum,0,sizeof sum);
    FOR(i,1,n) sum[i] = sum[i-1] + h[i];
    solve();
    
    if(ans == INF) printf("-1\n");
    else printf("%d\n", ans);
    

    return 0;
}
