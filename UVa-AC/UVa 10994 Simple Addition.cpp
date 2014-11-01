/*
  Name: UVa 10994 Simple Addition
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 8/5/2012
  Description: ad hoc, math
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

int n, t;

int64 p, q, ans;


int64 g(int64 a){
    int64 s1 = 0LL, s2 = 0LL, m;
    while(a){
        m = a % 10;
        a /= 10;
        s1 += (m * (m + 1) / 2);
        s2 += a * 45;    
    }        
    return s1 + s2;
}

int64 getSum(){
    if(p) return g(q) - g(p - 1);
    else return g(q);
}

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    while(cin >> p >> q){
        if(p < 0 && q < 0) break;
        cout << getSum() << endl;    
    }
    return 0;
}
