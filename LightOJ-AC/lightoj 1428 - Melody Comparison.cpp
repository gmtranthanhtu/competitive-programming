/*
  Name: LightOJ 1428 - Melody Comparison
  Author: 3T - mailto: gm.tranthanhtu@gmail.com
  Date: 3/4/2013
  Algorithm: suffix array, KMP, number of distinct substrings
  Time Limit: 4.000s
*/

//COMPETITIVE PROGRAMMING TEMPLATE

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
#include <deque>
#include <list>
#include <sstream>
#include <fstream>
#include <complex>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <utility>
#include <iterator>
#include <numeric>
#include <climits>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it,ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define fillinf(ar, n) fr(i,0,(n)) ar[i] = INF
#define debug(x) cout<<#x<<": "<<x<<endl
#define arr1d(a,n) cout << #a << " : "; fr(_,1,n) cout << a[_] << ' '; cout << endl;
#define arr1d0(a,n) cout << #a << " : "; rep(_,n) cout << a[_] << ' '; cout << endl;
#define arr2d(a,n,m) cout << #a << " :" << endl; fr(_,1,n) {fr(__,1,m) cout << a[_][__] << ' '; cout << endl;}
#define arr2d0(a,n,m) cout << #a << " :" << endl; rep(_,n) {rep(__,m) cout << a[_][__] << ' '; cout << endl;}

#define ull unsigned long long
#define ll long long
#define ld double
#define ui unsigned int
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define y0 yyyyyy0
#define y1 yyyyyy1

#define BIT(n) (1<<(n))
#define SQR(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
#define LSOne(S) (S) & (-S)
inline bool EQ(double a, double b) {return fabs(a - b) < 1e-9;}

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;

template<typename T>inline T gcd(T a, T b){if (b == 0)return a;else return gcd(b, a % b);}
template<typename T>inline T lcm(T a, T b){return (a * b) / gcd(a, b);}
template<typename T> string toStr(T x) {stringstream st; st << x; string s; st >> s; return s;}
template<class T>
void splitStr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

inline int two(int n) {return 1 << n;}
inline int isOnBit(int n, int b) {return (n >> b) & 1;}
inline void onBit(int & n, int b) {n |= two(b);}
inline void offBit(int & n, int b) {n &= ~two(b);}
inline int lastBit(int n) {return n & (-n);}
inline int cntBit(int n) {int res = 0; while(n && ++res) n -= n &(-n); return res;}

const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
const int dx8[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy8[] = {0, 1, 0, -1, -1, 1, -1, 1};

#define INP "test.inp"
#define OUT "test.out"

#define PI 3.1415926535897932385
#define INF 1000111222
#define EPS 1e-7
#define MAXN 55000
#define MOD 1000000007

//END OF COMPETITVE PROGRAMMING TEMPLATE
int t, sz, n, m, b[MAXN], sa[MAXN], tmpsa[MAXN], ra[MAXN], tmpra[MAXN], c[MAXN], phi[MAXN], lcp[MAXN], p[MAXN];
char T[MAXN], P[MAXN];
vi v;

void kmpProcess() {
    int i = 0, j = -1;
    b[0] = -1;
    while(i < m) {
        while(j >= 0 && (P[i] != P[j])) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

void kmpSearch() {
    v.clear();
    int i = 0, j = 0;
    while(i < n) {
        while(j >= 0 && (T[i] != P[j])) j = b[j];
        i++; j++;
        if(j == m) {
            v.pb(i - m);
            j = b[j];
        }
    }
    sz = v.size();
}

void countingSort(int k) {
    fill0(c);
    int Max = max(300, n);
    rep(i, n) c[i + k < n ? ra[i + k] : 0]++;
    for(int i = 0, sum = 0; i < Max; i++) {
        int tmp = c[i]; c[i] = sum; sum += tmp;
    }
    rep(i, n) tmpsa[c[sa[i] + k < n ? ra[sa[i] + k] : 0]++] = sa[i];
    rep(i, n) sa[i] = tmpsa[i];
}

void constructSA() {
    T[n++] = '$';
    T[n] = '\0';
    rep(i, n) sa[i] = i, ra[i] = T[i];
    for(int k = 1; k < n; k <<= 1) {
        countingSort(k); countingSort(0);
        int r = tmpra[sa[0]] = 0;
        fr(i, 1, n - 1) tmpra[sa[i]] = (ra[sa[i]] == ra[sa[i - 1]] && ra[sa[i] +k] == ra[sa[i - 1] + k]) ? r : ++r;
        rep(i, n) ra[i] = tmpra[i];
    }
}

void computeLCP() {
    phi[sa[0]] = -1;
    fr(i, 1, n - 1) phi[sa[i]] = sa[i - 1];
    for(int i = 0, l = 0; i < n; i++) {
        if(phi[i] == -1) {p[i] = 0; continue;}
        while(T[i + l] == T[phi[i] + l]) l++;
        p[i] = l;
        l = max(l - 1, 0);
    }
    rep(i, n) lcp[i] = p[sa[i]];
}

int getRange(int pos) {
    int Min = n, lo = 0, hi = sz - 1, mi;
    while(lo <= hi) {
        mi = (lo + hi) / 2;
        if(v[mi] < pos) lo = mi + 1;
        else {
            Min = min(Min, v[mi]);
            hi = mi - 1;
        }
    }
    if(Min == n) return n - pos - 1;
    Min = Min + m - 1;
    return Min - pos;
}

int solve() {
    int res = 0;
    fr(i, 1, n - 1) {
        int tmp = getRange(sa[i]);
        res += tmp;
        res -= min(tmp, lcp[i]);
    }
    return res;
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif

    scanf("%d", &t);
    fr(tt, 1, t) {
        scanf("%s", T);
        scanf("%s", P);
        n = strlen(T); m = strlen(P);
        kmpProcess();
        kmpSearch();
        constructSA();
        computeLCP();
        printf("Case %d: %d\n", tt, solve());
    }

    return 0;
}
