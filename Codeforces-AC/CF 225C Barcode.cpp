/*
  Name: Codeforces 225B Barcode
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 20/9/2012
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

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;

template<typename T>inline T gcd(T a, T b){if (b == 0)return a;else return gcd(b, a % b);}
template<typename T>inline T lcm(T a, T b){return (a * b) / gcd(a, b);}

int n, t, m, a, b[1111][3][1111], c[3][1111], x, y, ans;

char bar[1111][1111];

void solve(){
    REP(i,m){
        int sum = 0;
        REP(j,n){
            if(bar[j][i] == '#') sum++;        
        }    
        c[1][i+1] = sum;
        c[2][i+1] = n - sum;
    }   
    
    memset(b,INF,sizeof b);
    b[1][1][1] = c[1][1];
    b[1][2][1] = c[2][1];
    FOR(i,2,m){
        FOR(j,1,2){
            FOR(k,2,y){
                if(b[i-1][j][k-1] == INF) b[i][j][k] = INF;
                else b[i][j][k] = b[i-1][j][k-1] + c[j][i];    
            } 
            int p = (j == 1 ? 2 : 1);
            int tmp = INF;
            FOR(k,x,y){
                tmp = min(tmp, b[i-1][p][k]);    
            }               
            b[i][j][1] = tmp + c[j][i];
        }                    
    }     
    ans = INF;
    FOR(j,1,2) FOR(k,x,y){
        ans = min(ans, b[m][j][k]);    
    }
    cout << ans << endl;
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    scanf(" %d %d %d %d ", &n, &m, &x, &y);
    REP(i,n) {gets(bar[i]); }
    solve();
    return 0;
}
