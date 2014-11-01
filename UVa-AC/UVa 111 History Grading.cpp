/*
  Name: UVa 111 History Grading
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 8/10/2012
  Description: LIS
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

int n, t, m, a, b, c, len;
map <int, int> order;
vi ans, arr, a1, a2, arr1;

void updateLis(int u){
    if(!len || order[u] > order[ans[len-1]]){
        ans.pb(u); len++; return;    
    }    
    int l = 0, h = len-1, mi, tmp;
    while(l <= h){
        mi = (l+h) >> 1;
        if(order[ans[mi]] < order[u]) l = mi + 1;
        else if(order[ans[mi]] == order[u]) return;
        else{
            h = mi - 1;        
        }    
    }
    ans[l] = u;
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    scanf("%d", &n);
    order.clear();
    arr1.assign(n+1,0);
    a1.clear();
    FOR(i,1,n) scanf("%d", &a), a1.pb(a);
    REP(i,n) arr1[a1[i]-1] = i+1;
    REP(i,n) order[arr1[i]] = i;
    while(scanf("%d", &a) != EOF){
        arr.assign(n+1,0);
        a2.clear();
        a2.pb(a);
        ans.resize(0);
        len = 0;
        FOR(i,1,n-1) scanf("%d", &a), a2.pb(a);
        REP(i,n) arr[a2[i]-1] = i+1;
        REP(i,n) updateLis(arr[i]);   
        cout << len << endl; 
    }

    return 0;
}
