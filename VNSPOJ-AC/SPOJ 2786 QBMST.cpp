/*
  Name: SPOJ 2786 Cay khung nho nhat
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 19/5/2012
  Description: kruscal
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
#define MAXN 20000
#define MAXM 15005
#define MOD 1000000007

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, t, a, b, c, m, u, v, ans;
typedef struct Edge {
    int u, v, cost;    
};
Edge e[MAXM];

vi pset;

void iniSet(int n){
    pset.assign(n + 1, 0);
    FOR(i, 1, n) pset[i] = i;    
}

int findSet(int i){
    return (pset[i] == i ? i : (pset[i] = findSet(pset[i])));    
}

bool isSameSet(int i, int j) {return (findSet(i) == findSet(j));}
void unionSet(int i, int j) {pset[findSet(i)] = findSet(j);}

bool cmp(const Edge& e1, const Edge& e2){return e1.cost <  e2.cost;}

void solve(){
    iniSet(n);
    b = 0;
    ans = 0;
    sort(e + 1, e + m + 1, cmp);  
    FOR(i, 1, m) if(!isSameSet(e[i].u, e[i].v)){
        ans += e[i].cost;
        b++;
        if(b == n - 1) break;
        unionSet(e[i].u, e[i].v);    
    }
    printf("%d\n", ans);  
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    scanf("%d %d", &n, &m);
    FOR(i, 1, m) scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].cost);
    solve();

    return 0;
}
