/*
  Name: CF 186B Growing Mushrooms
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 4/5/2012
  Description: greedy, sort
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
#define MAXN 1005

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, t1, t2, k, a[MAXN], b[MAXN], c;
typedef struct Rank{
    int ind;
    double height;
    };
    
Rank R[MAXN];

bool cmp(const Rank& R1, const Rank& R2){
    if (R1.height > R2.height) return true;
    else if(R1.height == R2.height && R1.ind < R2.ind) return true;
    return false;    
}

void solve(){
    FOR(i, 1, n){
        R[i].ind = i;
        R[i].height = max(a[i] * t1 * (1 - (double) k / 100.0) + b[i] * t2, b[i] * t1 * (1 - (double) k / 100.0) + a[i] * t2);    
    }
    sort(R + 1, R + n + 1, cmp);  
    FOR(i, 1, n){
        printf("%d %.2lf\n", R[i].ind, R[i].height);    
    }  
}

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    scanf("%d %d %d %d", &n, &t1, &t2, &k);
    FOR(i, 1, n) scanf("%d %d", &a[i], &b[i]);
    solve();    
    return 0;
}
