/*
  Name: LightOJ 1008 - Fibsieve`s Fantabulous Birthday 
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 29/10/2012
  Description: adhoc, math, binary search
  Time Limit: 0.500s
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
#define INF 100111222
#define EPS 1e-7
#define MAXN 20000
#define MOD 1000000007
#define L 32000000

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;

template<typename T>inline T gcd(T a, T b){if (b == 0)return a;else return gcd(b, a % b);}
template<typename T>inline T lcm(T a, T b){return (a * b) / gcd(a, b);}

int n, t, m, a, b, c;
int64 S;

ii solve(){
    int x, y, p = INF, lo = 1, hi = INF, mi;
    while(lo <= hi){
        mi = (lo + hi) >> 1;
        if((int64) mi * (int64)mi >= S){
            p = min(p, mi);
            hi = mi - 1;        
        }
        else{
            lo = mi + 1;    
        }     
    }
    int64 s = (p-1) * (p-1) + 1;
    if(S <= ((int64)p *(p-1) + 1)){
        x = p;
        y = S - s + 1;   
    } 
    else{
        y = p;
        x = p * p - S + 1;    
    }
    if(p%2 == 0) swap(x,y);
    return ii(x, y);     
}

int main () {
    //#ifndef ONLINE_JUDGE
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    //#endif
    
    scanf("%d", &t);
    FOR(i,1,t){
        cin >> S;    
        ii ans = solve();
        printf("Case %d: %d %d\n", i, ans.ff, ans.ss);
    }

    return 0;
}
