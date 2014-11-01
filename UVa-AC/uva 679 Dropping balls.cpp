/*
  Name: UVa 679 - Dropping Balls
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 7/5/2012
  Description: math, adhoc
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
#define MAXB 524288
#define MAXN 1048575
#define MAXD 20
#define MAXTEST 31

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, t, a, b, c;
int Ans[21][MAXB + 5];

int Pow2(int m){
    if(!m) return 1;
    int res = 1;
    FOR(i, 1, m) res *= 2;
    return res;    
}

string S[MAXN];

void Gen(){    
    Ans[1][1] = 1;
    Ans[2][1] = 2;
    Ans[2][2] = 3;
    FOR(i, 3, MAXD){
        int len = Pow2(i - 1);
        int l = len / 2;
        FOR(j, 1, l){
            Ans[i][j] = Ans[i - 1][j] * 2;    
        }   
        FOR(j, l + 1, len){
            Ans[i][j] = Ans[i][j - l] + 1;    
        }  
    }
}

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    Gen();
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &a, &b);
        cout << Ans[a][b] << endl;    
    }
    scanf("-1");
    return 0;
}
