/*
  Name: TCO2013 Round 1C Medium TheOlympiadInInformatics
  Author: 3T - mailto: gm.tranthanhtu@gmail.com
  Date: 4/3/2013
  Algorithm: binary search
  Time Limit: 2.000s
*/

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <vector>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

inline bool EQ(double a, double b) {return fabs(a - b) < 1e-9;}

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

template<typename T>inline T gcd(T a, T b){if (b == 0)return a;else return gcd(b, a % b);}
template<typename T>inline T lcm(T a, T b){return (a * b) / gcd(a, b);}

#define INF 1000111222
vi s;
int K;

long long f(int x) {
    long long r = 0;
    rep(i, s.size()) {
        r += s[i] / x;
    }
    return r;
}

typedef struct TheOlympiadInInformatics{
    int find(vector <int> sums, int k) {
        s = sums;
        K = k;
        int res = INF;
        int lo = 0, hi = INF, mi;
        while(lo <= hi) {
            mi = (lo + hi) / 2;
            if(f(mi + 1) <= k) {
                res = min(res, mi);
                hi = mi - 1;
            }
            else lo = mi + 1;
        }
        return res;
    }
};

