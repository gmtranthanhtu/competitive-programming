/*
  Name: Light OJ 1035 - Intelligent Factorial Factorization
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 4/11/2012
  Description: factorial factorization, math
  Time Limit: 0.500s
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
#define MAXN 100
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

int n, t, m, a, b, c, len;
bool prime[MAXN+5];
vi p;
int ans[MAXN+5][MAXN+5];

void gen(){
    FOR(i,2,MAXN) prime[i] = true;   
    for(int i = 2; i * i <=  MAXN; i++){
        if(!prime[i]) continue;
        for(int j = 2; j * i <= MAXN; j++) prime[i*j] = false;    
    }     
    FOR(i,2,MAXN) if(prime[i]) p.pb(i);
    len = p.size();
    
    FOR(i,2,MAXN){
        int cnt = 0;
        REP(j,len){
            int tmp = 0, nn = i, d = p[j];
            while(nn){
                tmp += nn/d;
                nn /= d;    
            }    
            if(tmp) cnt++;
            ans[i][j] = tmp;
        }    
        ans[i][len] = cnt;
    }
}

void printAns(int n){
    int cnt = 0;
    REP(i,len){
        if(!ans[n][i]) break;
        if(!cnt) printf("%d (%d)", p[i], ans[n][i]);
        else printf(" * %d (%d)", p[i], ans[n][i]);
        cnt++;    
    }        
    puts("");    
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    gen();
    scanf("%d", &t);
    FOR(tt,1,t){
        scanf("%d", &n);
        printf("Case %d: %d = ",tt,n);
        printAns(n);    
    }

    return 0;
}
