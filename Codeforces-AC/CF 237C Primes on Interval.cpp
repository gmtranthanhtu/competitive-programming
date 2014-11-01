/*
  Name: Codeforces 237C Primes on Interval
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 25/10/2012
  Description: prime, binary search
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
#define MAXN 1001000
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

int n, t, m, a, b, c[MAXN], k, ans;
bool prime[MAXN];

void preCal(){
     memset(prime, true, sizeof prime);
     prime[0]=prime[1]= false;
     for(int i = 2; i * i <= MAXN; i++){
        if(!prime[i]) continue;
        for(int j = 2; j * i <= MAXN; j++) prime[i*j] = false;    
        } 
        
    c[0] = 0;
    FOR(i,1,MAXN) if(prime[i]) c[i] = c[i-1] + 1;
    else c[i] = c[i-1];       
}

bool ok(int x){
    FOR(i,a,b-x+1){
        int r = x + i - 1;
        if(c[r] - c[i-1] < k) return false;    
    }    
    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    preCal();
    scanf("%d%d%d", &a, &b, &k);
    ans = INF;
    int l = 1, h = b - a + 1, mi, tmp;
    while(l <= h){
        mi = (l+h)/2;
        if(ok(mi)){
            ans = min(ans, mi);
            h = mi - 1;    
        }    
        else l = mi + 1;
    }
    if(ans == INF) printf("-1");
    else printf("%d\n",ans);

    return 0;
}
