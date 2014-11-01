/*
  Name: LightOJ 1198 Karate Competition
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 26/10/2012
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

int n, t, m, a[100], b[100], c, use1[100], use2[100], ans;

bool cmp(const int& a, const int& b){return a > b;}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    scanf("%d", &t);
    FOR(i,1,t){
        scanf("%d", &n);
        FOR(j,1,n) scanf("%d", &a[j]);
        FOR(j,1,n) scanf("%d", &b[j]);
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1, cmp);
        FOR(j,1,n) use1[j] = use2[j] = 0;
        ans = 0; 
        FOR(j,1,n) if(!use1[j]){
            int u = 0, Max = -1;
            FOR(k,1,n) if(b[k] < a[j] && b[k] > Max && !use2[k]){
                u = k;
                Max = b[k];
                }
            if(u){
                ans += 2; use2[u] = 1; use1[j] = 1;    
            }    
        }
        FOR(j,1,n) if(!use1[j]){
            FOR(k,1,n) if(!use2[k] && a[j] == b[k]){
                ans += 1; use2[k] = 1; use1[j] = 1;  
                break;  
            }    
        }
        printf("Case %d: %d\n", i, ans);   
    }

    return 0;
}
