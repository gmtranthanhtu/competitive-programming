/*
  Name: UVa 834	Continued Fractions
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

int n, t, a, b, c, ans[1000];

int nume, deno;

int gcd(int a, int b){
    return (!a) ? b : gcd(b % a, a);    
}

void solve(){
    n = 1;
    ans[1] = nume / deno;
    if(nume > deno) nume -= (deno * ans[1]); 
    while(1){
        int tmp = gcd(nume, deno);
        nume /= tmp; deno /= tmp;  
        if(nume == 1){
            n++;
            ans[n] = deno;
            break;    
        }  
        swap(nume, deno);
        n++;
        ans[n] = nume / deno;
        if(nume > deno) nume -= (deno * ans[n]);
    }     
    printf("[%d;", ans[1]);
    FOR(i, 2, n){
        printf("%d", ans[i]);
        if(i < n) printf(",");
        else printf("]\n");    
    }
}

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    while(scanf("%d %d", &nume, &deno) == 2){
        solve();    
    }

    return 0;
}
