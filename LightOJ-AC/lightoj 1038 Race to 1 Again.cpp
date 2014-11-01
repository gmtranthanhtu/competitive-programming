/*
  Name: 1038 - Race to 1 Again 
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 1/11/2012
  Description: probability, divisor, expected value
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
#define MAXN 100000
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

int n, t, m, a, b, c(0);

double f[MAXN + 5];

double cal(int m){
    if(f[m] > -1) return f[m];
    int cnt = 0;
    double tmp = 1;
    for(int i = 2; i * i <= m; i++){
        if(m%i == 0){
            cnt++;
            tmp += cal(i) + 1;
            int d = m/i;
            if(d!=i){
                cnt++;
                tmp += cal(d) + 1;    
            }    
        }    
    }
    cnt++;
    tmp += 1;
    return f[m] = tmp/cnt;    
}

void pre(){
    FOR(i,1,MAXN) f[i] = -1.0;
    f[1] = 0;
    FOR(i,2,MAXN) f[i] = cal(i);     
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    pre();
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("Case %d: %.10lf\n", ++c, f[n]);        
    }

    return 0;
}
