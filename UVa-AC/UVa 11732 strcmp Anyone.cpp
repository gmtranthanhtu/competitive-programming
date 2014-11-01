/*
  Name: UVa 11732 strcmp() Anyone?
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 24/5/2012
  Description: string, sort
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
#define MAXN 20000
#define MOD 1000000007

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;

int n, t, a, b, c(0);

vi p;
vector <string> s;
int64 ans;
string st;

void solve(){
    sort(all(s));
    
    FOR(i, 1, n-1){
        int l = min(s[i - 1].length(), s[i].length());
        REP(j, l){
            p[i]++;
            if(s[i - 1][j] != s[i][j]) break;
            p[i]++;
            if(s[i - 1][j] == '\0') break;       
        }    
    }  
    
    ans = 0LL;
    REP(i, n){
        int tmp = INF;
        FOR(j, i + 1, n - 1){
            tmp = min(tmp, p[j]);
            ans += tmp;    
        }    
    }  
    
    printf("Case %d: %lld\n", ++c, ans);
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    while(scanf(" %d ", &n), n){
        s.resize(0);
        p.assign(n, 0);
        REP(i, n) cin >> st, s.pb(st + '\0');
        solve();      
    }

    return 0;
}
