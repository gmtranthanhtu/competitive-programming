/*
  Name: UVa 10664 Luggage
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 26/5/2012
  Description: dp
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
#define MAXN 111
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

int n, t, m, a, b, c, arr[50], sum, dp[25][MAXN][MAXN], lim;

char line[1000];

int tryBoot(int i, int b1, int b2){
    if(b1 > lim || b2 > lim) return 0;
    if(i == n + 1 && b1 == lim && b2 == lim) return 1;
    if(dp[i][b1][b2] != -1) return dp[i][b1][b2];
    
    return dp[i][b1][b2] = tryBoot(i + 1, b1 + arr[i], b2) || tryBoot(i + 1, b1, b2 + arr[i]);        
}

int solve(){
    if(sum % 2) return 0; 
    lim = sum/2;   
    memset(dp, -1, sizeof dp);
    return tryBoot(1, 0, 0);
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif

    gets(line);
    t = atoi(line);
    while(t--){
        n = 0; 
        gets(line);
        c = 0;
        sum = 0;
        REP(i, strlen(line)) if(line[i] == ' ') c++;
        FOR(i, 1, c + 1){
            n++;
            sscanf(line, "%d %[' ', 0-9]", &a, &line);
            arr[n] = a;   
            sum += a;
        }   
        printf("%s\n", solve() ? "YES" : "NO");    
    }

    return 0;
}
