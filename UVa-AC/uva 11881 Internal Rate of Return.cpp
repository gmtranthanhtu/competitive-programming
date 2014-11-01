/*
  Name: UVa 11881	Internal Rate of Return
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 8/5/2012
  Description: binary search
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

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, t, a, b, c;

double cf[20], res;

double Pow(double a, int b){
    double res = 1;
    FOR(i, 1, b) res *= a;
    return res;   
}

void solve(){
    double lo = -0.9999999999, hi = INF, mi, tmp;
    FOR(i, 1, 200){
        mi = (lo + hi) / 2;
        tmp = cf[0];
        FOR(j, 1, t){
            tmp += (cf[j] / Pow(1 + mi, j));      
        }  
        if(tmp < 0.0) hi = mi;
        else lo = mi;  
    } 
    mi = (lo + hi)/2;
    tmp = cf[0];
    FOR(j, 1, t){
        tmp += (cf[j] / Pow(1 + mi, j)); 
    } 
    if(fabs(tmp) <= EPS){
        if(mi > -1) res = mi;
        else res = -100;    
    }
    else res = -100;
    if(res == -100) printf("No\n");
    else printf("%.2lf\n", res);
}

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    while(scanf("%d", &t) && t){
        FOR(i, 0, t) cin >> cf[i];
        solve();    
    }

    return 0;
}
