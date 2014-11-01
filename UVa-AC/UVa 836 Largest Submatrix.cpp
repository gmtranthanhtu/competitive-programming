/*
  Name: UVa 60703 Largest Subsmatrix
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 26/5/2012
  Description: dp, largest sum
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
#define MAXN 50
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

int n, t, m, a, b, c, sum[MAXN][MAXN], dp[MAXN][MAXN][MAXN][MAXN];

char line[100];
string s, arr[MAXN];

int solve(){
    fill(sum, 0);
    fill(dp, 0);
    FOR(i, 1, n) 
        FOR(j, 1, n){
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i - 1][j - 1] - '0';           
        } 
    int res = 0; 
    FOR(i, 1, n)
        FOR(j, 1, n)
            FOR(k, i, n)
                FOR(l, j, n){
                    int tmp = sum[k][l] - sum[k][j - 1] - sum[i - 1][l] + sum[i - 1][j - 1];
                    if(tmp == (k - i + 1) * (l - j + 1)){
                        res = max(res, tmp); 
                    }    
                }   
    return res;                   
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif

    getline(cin, s);
    t = atoi(s.c_str());
    //debug(t);
    getline(cin, s);
    FOR(i, 1, t){
        n = 0;
        while(getline(cin, s) && s.length() != 0){
            arr[n++] = s;  
        }    
        if(i > 1) cout << endl;
        printf("%d\n", solve());
    }

    return 0;
}
