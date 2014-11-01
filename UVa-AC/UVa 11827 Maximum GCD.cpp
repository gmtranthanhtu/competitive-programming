/*
  Name: UVa 11827 Maximum GCD
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 8/5/2012
  Description: gcd
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

int n, t, a, b, c, arr[1000], ans;

char line[1000];
char f[1000];

int countNum(){
    int res = 0;
    char prev = 'a';
    int len = strlen(line);
    REP(i, len){
        if(line[i] == ' '){prev = ' '; continue;}
        if(i == 0 && line[i] != ' ') {res++; prev = line[i];}
        else if(line[i] != ' ' && prev == ' ') {res++; prev = line[i];}  
                   
    }
    return res;    
}

int gcd(int a, int b){
    //if(a < b) swap(a, b);
    if(a % b == 0) return b;
    return gcd(b, a%b);    
}

void solve(){
    n = countNum();  
    //cout << n << endl;
    FOR(i, 1, n) {sscanf(line, "%d %[' ', 0-9]", &arr[i], &line);}
    ans = -1;
    FOR(i, 1, n - 1){
        FOR(j, i + 1, n){
            ans = max(ans, gcd(arr[i], arr[j]));    
        }    
    }    
    printf("%d\n", ans);
}

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    gets(line);
    sscanf(line, "%d", &t);
    while(t--){
        gets(line);
        solve();    
    }
    return 0;
}
