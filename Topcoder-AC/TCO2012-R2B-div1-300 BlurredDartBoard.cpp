/*
  Name: TCO 2012 Round 2B div1 300 BlurredDartboard
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 13/5/2012
  Description: binary search
  Time Limit: 
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
#define MAXN 10000000000LL

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, t, a, b, c, arr[55], p, maxs, sum[55];
int nh;
bool hid[55];

int64 getPoint(int64 k){
    if(nh == 0){
        return k * maxs;    
    }
    if(k % nh == 0){
        if(sum[nh] > nh * maxs) return sum[nh] * (k / nh);
        else return k * maxs;    
    }      
    
   if(sum[nh] <= nh * maxs) return k * maxs;
   
   int64 res = (k / nh) * sum[nh];
   int64 tmp = k % nh;
   if(sum[tmp] > tmp * maxs) return res + sum[tmp];
   else return res + tmp * maxs;
}

int solve(){
    int64 lo = 1, hi = MAXN, mi, ans = 0;
    int64 tmp;   
    while(lo <= hi){
        mi = (lo + hi)/2;
        tmp = getPoint(mi);
        if(tmp >= p) ans = mi, hi = mi - 1;
        else lo = mi + 1;    
    } 
    return (int)ans;
}

typedef struct BlurredDartboard{
    int minThrows(vector <int> points, int P){
        maxs = 0;
        n = points.size();
        fill(hid, true);
        FOR(i, 1, n) a = points[i - 1], hid[a] = false, maxs = max(a, maxs);
        p = P;
        sum[0] = 0; nh = 0;
        FOR(i, 1, n) if(hid[i]) nh++, sum[nh] = sum[nh - 1] + i;     
        return solve();            
    }    
};
