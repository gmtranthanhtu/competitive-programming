/*
  Name: UVa 11966 Galactic Bonding
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 5/10/2012
  Description: union-find disjoint set
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
#define MAXN 1000
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

int n, t, m, a, b, c, ans;
vi pset;
double x[MAXN+5], y[MAXN+5], d;

void iniSet(int u){
    pset.assign(u+1,0);
    FOR(i,1,u) pset[i]=i;    
}
int findSet(int u){return pset[u] == u ? u : (pset[u] = findSet(pset[u]));}
bool isSameSet(int u, int v){return findSet(u) == findSet(v);}
void unionSet(int u, int v){pset[findSet(u)] = findSet(v);}

bool ok(int i, int j){
    return hypot(x[i]-x[j], y[i]-y[j]) <= d;    
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    scanf("%d", &t);
    FOR(i,1,t){
        scanf("%d %lf", &n, &d);
        FOR(j,1,n) scanf("%lf %lf", &x[j], &y[j]);
        if(!n){
            printf("Case %d: 0\n", i);
            continue;     
        }
        iniSet(n);
        ans = n;
        FOR(j,1,n)
            FOR(k,j+1,n){
                if(ok(j,k)&& !isSameSet(j,k)) unionSet(j,k), ans--;    
            } 
        printf("Case %d: %d\n", i, ans);   
    }

    return 0;
}
