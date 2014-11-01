/*
  Name: UVa 846 Steps
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 9/5/2012
  Description: ad hoc, binary search
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
#define INF 2000111222
#define EPS 1e-7
#define MAXN 100000

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, t, a, b, c;

int64 x, y, d;

int64 getStep(int64 a){
    if(a % 2 == 0) return (a/2) * (a/2 + 1);
    else return (a/2 + 1) * (a/2 + 1);      
}

int64 cal(int64 step){
    if(step == 0 || step == 1 || step == 2) return step;
    int64 lo = 0, hi = INF, mi, tmp;
    while(lo <= hi){
        mi = (lo + hi) / 2;
        tmp = getStep(mi);    
        if(tmp == step) return mi;
        if(tmp > step) hi = mi - 1;
        else lo = mi + 1;
    }  
    return lo;
} 

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    scanf("%d", &t);
    while(t--){
        cin >> x >> y;   
        d = y - x;
        cout << cal(d) << endl; 
    }
    return 0;
}
