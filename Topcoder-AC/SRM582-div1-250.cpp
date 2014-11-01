/*
    Problem: TC SRM 582 div 1 easy
    Author: 3T
    Algorithm: greedy
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
#define ll long long

typedef pair< int, ll > il;
vector< il > enemy;
vector<int> girl;
vector< ll > f;

ll solve() {
    int len = girl.size();
    frr(i, len - 2, 0) {
        if(f[i] <= f[i + 1]) continue;
        ll tmp = 0;
        fr(j, i, len - 1) tmp += f[j];
        ll tmp2 = tmp / (len - i), tmp3 = tmp % (len - i);
        if(tmp2 < f[len - 1]) {
            frr(j, len - 1, i) {
                if(tmp <= 0) f[j] = 0;
                else {
                    f[j] = min(tmp, f[len - 1]);
                    tmp -= f[len - 1];
                }
            }
            continue;
        }
        frr(j, len - 1, i) {
            f[j] = (tmp3-- > 0) ? tmp2 + 1 : tmp2;
        }
    }
    ll res = 0;
    rep(i, len) if(f[i] > res) res = f[i];
    return res;
}

typedef struct SpaceWarDiv1 {
    long long minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector<long long> enemyCount){
        girl = magicalGirlStrength;
        rep(i, enemyStrength.size()) {
            enemy.pb(mp(enemyStrength[i], enemyCount[i]));
        }
        sort(all(enemy));
        sort(all(girl));
        f.assign(girl.size(), 0);
        int i = 0;
        rep(j, girl.size()) {
            ll tmp = 0;
            while(i < enemy.size() && enemy[i].ff <= girl[j]) {
                tmp += enemy[i].ss;
                i++;
            }
            f[j] = tmp;
        }
        if(i != enemy.size())  return -1;
        return solve();
    }
};


