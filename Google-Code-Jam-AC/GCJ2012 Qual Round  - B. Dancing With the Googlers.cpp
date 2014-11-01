/*
  Name: Qualification Round 2012 Problem B. Dancing With the Googlers
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 12/5/2012
  Description: ad hoc, greedy
  Time Limit: 
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
#define MAXN 111

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, t, a, b, c, s, p, arr[MAXN], ans;

int unsurprising(int val){
    if(val % 3) return val / 3 + 1;
    else return val / 3;    
}

int surprising(int val){
    if(val < 2 || val > 28) return -1;
    if((val - 1) % 3) return (val - 1) / 3 + 2;
    else return (val - 1) / 3 + 1;    
}

void solve(){
    ans = 0;
    FOR(i, 1, n){
        if(unsurprising(arr[i]) >= p) {ans++; continue;}
        else if(surprising(arr[i]) >= p && s > 0) ans++, s--;         
    }        
}

int main () {
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    scanf("%d", &t);
    FOR(i, 1, t){
        scanf("%d %d %d", &n, &s, &p);
        FOR(j, 1, n) scanf("%d", &arr[j]);
        solve();   
        printf("Case #%d: %d\n", i, ans); 
    }

    return 0;
}
