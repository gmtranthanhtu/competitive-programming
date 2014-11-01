/*
  Name: UVa 1231 ACORN
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 13/9/2012
  Description: dp
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
#define MAXN 2000
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

int n, t, m, a, b, c, h, f;

int acorn[MAXN + 5][MAXN + 5];
int dp[MAXN + 5];

void solve(){
    FOR(i,1,t){
        dp[h] = max(dp[h], acorn[i][h]);                
    }        
    FORD(i,h-1,0){
        FOR(j,1,t){
            int tmp = acorn[j][i+1];
            if(i + f <= h) tmp = max(tmp, dp[i+f]);
            tmp += acorn[j][i];
            acorn[j][i] = tmp;
            dp[i] = max(dp[i], tmp);         
        }   
    }
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    scanf("%d", &n);
    while(n--){
        scanf("%d%d%d", &t,&h,&f);
        FOR(i,1,t) FOR(j,0,h) acorn[i][j] = 0;
        FOR(i,1,t){
            scanf("%d", &a);    
            while(a--){
                scanf("%d", &b);
                acorn[i][b]++;    
            }
        } 
        
        memset(dp, 0, sizeof dp);
        solve();  
        printf("%d\n", dp[0]);     
    }
    scanf("0\n");

    return 0;
}
