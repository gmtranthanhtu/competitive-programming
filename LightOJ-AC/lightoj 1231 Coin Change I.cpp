/*
  Name: LightOJ 1231 Coin Change (I)
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 14/5/2012
  Description: dp, coin change
  Time Limit: 1.000s
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
#define MODU 100000007

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, t, a[105], b, c[105], K;
int dp[1005][55], way[1005], tmp[1005];

void Copy(){
    FOR(i, 0, K)  tmp[i] = way[i];   
}

int solve(){
    memset(way, 0, sizeof way);
    way[0] = 1;
    Copy();
    
    FOR(i, 1, n){
        Copy();       
        FOR(j, 1, c[i]){
            FORD(k, K, j * a[i]) {way[k] += tmp[k - j * a[i]]; way[k] %= MODU;}    
        }    
    }                
    return way[K] % MODU;
}

int main () {
   // #ifndef ONLINE_JUDGE
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    //#endif
    
    scanf("%d", &t);
    FOR(i, 1, t){
        scanf("%d %d", &n, &K);  
        FOR(j, 1, n) scanf("%d", &a[j]);
        FOR(j, 1, n) scanf("%d", &c[j]);
        printf("Case %d: %d\n", i, solve());
    }

    return 0;
}
