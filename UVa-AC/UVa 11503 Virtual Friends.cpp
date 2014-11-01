/*
  Name: UVa 11503 Virtual Friends
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 25/5/2012
  Description: disjoint set
  Time Limit: 10.000s
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
#define MAXN 200100
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

int n, t, a, b, c, p, lab[MAXN];

string s1, s2;
char line[100];
map <string, int> m;

void iniSet(int n){
    FOR(i, 1, n) lab[i] = -1;        
}

int getRoot(int u){
    if(lab[u] < 0) return u;
    return getRoot(lab[u]);    
}

int unionSet(int u, int v){
    int x = lab[u] + lab[v];
    if(lab[u] > lab[v]) lab[u] = v, lab[v] = x;
    else{
        lab[v] = u; lab[u] = x;
    }        
    return -x;    
}

int res(int u, int v){
    int uu = getRoot(u), vv = getRoot(v);
    if(uu == vv) return -lab[uu];
    return unionSet(uu, vv);     
}


int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif

    scanf("%d", &t);
    while(t--){
        scanf(" %d ", &n);    
        iniSet(n * 2);
        m.clear();
        p = 0;
        FOR(i, 1, n){
            s1 = s2 = "";
            scanf("%s", &line);
            s1 += line;
            scanf("%s", &line);
            s2 += line;
            int u = ((m[s1] != 0) ? m[s1] : (m[s1] = ++p));
            int v = ((m[s2] != 0) ? m[s2] : (m[s2] = ++p));
            printf("%d\n", res(u, v));
        }
    }        

    return 0;
}
