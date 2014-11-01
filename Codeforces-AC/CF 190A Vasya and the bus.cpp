/*
  Name: CF 190A Vasya and the Bus 
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 16/5/2012
  Description: greedy, math
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

int n, t, a, b, c, m;

void solve(){
    if(n == 0 && m == 0){
        printf("0 0\n");
        return;    
    } 
    else if(n == 0){
        cout << "Impossible" << endl;
        return;    
    } 
    if(m == 0){
        printf("%d %d\n", n, n);
        return;    
    }
    a = max(n, m);
    b = m + n - 1;
    printf("%d %d\n", a, b);    
}

int main () {
    //#ifndef ONLINE_JUDGE
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    //#endif
    
    cin >> n >> m;
    solve();


    return 0;
}
