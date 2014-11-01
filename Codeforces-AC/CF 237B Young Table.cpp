/*
  Name: Codeforces 237B Young Table
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 25/10/2012
  Description: ad hoc
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

int n, t, m, a[60][60], b, c[60], s;

typedef struct S{
    int x1, y1, x2, y2;    
};

S Step[3000];

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    scanf("%d", &n);
    s = m = b = 0;
    FOR(i,1,n) scanf("%d", &c[i]), s += c[i];
    FOR(i,1,n) FOR(j,1,c[i]) scanf("%d", &a[i][j]);
    FOR(i,1,n) FOR(j,1,c[i]){
        b++;
        if(a[i][j] == b) continue;
        int x, y;
        FOR(u,1,n) FOR(v,1,c[u]) if(a[u][v] == b){
            x = u; y = v; 
            break;   
        }    
        m++; Step[m].x1 = i; Step[m].y1 = j; Step[m].x2 = x;  Step[m].y2 = y;
        swap(a[i][j], a[x][y]);
    }
    
    printf("%d\n", m);
    FOR(i,1,m) printf("%d %d %d %d\n",Step[i].x1, Step[i].y1,Step[i].x2, Step[i].y2);

    return 0;
}