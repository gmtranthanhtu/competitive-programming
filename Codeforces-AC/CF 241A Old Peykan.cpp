/*
  Name: CF 241A Old Peykan 
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 1/11/2012
  Description: greedy
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

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define debug(x) cout<<#x<<": "<<x<<endl

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
typedef vector<string> vs;

template<typename T>inline T gcd(T a, T b){if (b == 0)return a;else return gcd(b, a % b);}
template<typename T>inline T lcm(T a, T b){return (a * b) / gcd(a, b);}

int n, t, m, a, b, c, k;
int s[1111], d[1111], ms[1111];
typedef struct F{
    int ti, fu;    
};

F f[1111];

void solve(){
    f[1].ti = 0;
    f[1].fu = s[1];
    FOR(i,2,n){
        if(d[i] <= f[i-1].fu){
            f[i].ti = f[i-1].ti + d[i] - d[i-1];
            f[i].fu = f[i-1].fu + s[i];    
        }    
        else{
            f[i].ti = f[i-1].ti + d[i] - d[i-1];
            int tmp = d[i] - f[i-1].fu;
            int shit;
            if(tmp % ms[i-1]){
                shit = tmp / ms[i-1] + 1;        
            }    
            else shit = tmp / ms[i-1];
            f[i].ti += shit * k;
            f[i].fu = f[i-1].fu + s[i] + shit * ms[i-1]; 
        }
    }    
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    scanf("%d%d", &m, &k);
    n = m + 1;
    d[1] = 0;
    FOR(i,2,n) scanf("%d", &a), d[i] = d[i-1] + a;
    FOR(i,1,n-1){
        scanf("%d", &s[i]);
        if(i==1) ms[i] = s[i];
        else ms[i] = max(s[i], ms[i-1]);    
    }
    solve();
    printf("%d\n", f[n].ti);
    

    return 0;
}
