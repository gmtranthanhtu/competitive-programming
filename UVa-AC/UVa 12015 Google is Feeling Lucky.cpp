/*
  Name: UVa 12015 Google is Feeling Lucky
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 9/5/2012
  Description: ad hoc
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

char s[12][112], line[112];
int v[12];

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    gets(line);
    sscanf(line, "%d", &t);
    FOR(i, 1, t){
        a = -1;
        FOR(j, 1, 10) {gets(line);
            sscanf(line, "%s %d", &s[j], &v[j]);
            a = max(a, v[j]);
        }    
        printf("Case #%d:\n", i);
        FOR(j, 1, 10){
            if(v[j] == a) cout << s[j] << endl;
        }
    }

    return 0;
}
