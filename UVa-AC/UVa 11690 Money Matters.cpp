/*
  Name: UVa 11690 Money Matters
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
#define MAXN 10000
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

int n, t, m, a[MAXN+5], b, c, sum[MAXN+5];
vi pset;

void iniSet(int u){
    pset.assign(n+1,0);
    REP(i,n) pset[i] = i;        
}

int findSet(int u){
    return (pset[u] == u ? u : pset[u] = findSet(pset[u]));    
}

bool isSameSet(int u, int v){
    return findSet(u) == findSet(v);    
}

void unionSet(int u, int v){
    pset[findSet(u)] = findSet(v);    
}

bool ok(){
    //REP(i,n) debug(sum[i]), debug(pset[i]);
    REP(i,n) if(sum[i]) return false;
    return true;    
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        REP(i,n) scanf("%d", &a[i]);
        memset(sum,0,sizeof sum);
        iniSet(n);  
        FOR(i,1,m){
            scanf("%d%d", &b, &c);
            if(!isSameSet(b,c)) unionSet(b,c);    
        }  
        REP(i,n) sum[findSet(i)] += a[i];
        if(ok()) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }

    return 0;
}
