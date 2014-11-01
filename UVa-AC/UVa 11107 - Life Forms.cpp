/*
  Name: UVa 11107 - Life Forms
  Author: 3T - mailto: gm.tranthanhtu@gmail.com
  Date: 1/4/2013
  Algorithm: suffix array, binary search, longest common substring of n strings
  Time Limit: 6.666s
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
#define MAXN 111222
#define MOD 1000000007

//END OF COMPETITVE PROGRAMMING TEMPLATE
int t, n, tmpSA[MAXN], tmpRA[MAXN], RA[MAXN], SA[MAXN], Phi[MAXN], PLCP[MAXN], LCP[MAXN], c[MAXN], stupid(0), Sfrom[MAXN];
int mlen, half, Wlen[MAXN], vis[111];
char T[MAXN], line[MAXN], ans[MAXN];

void countingSort(int k) {
    fill0(c);
    int Max = max(300, n);
    rep(i, n) c[i + k < n ? RA[i + k] : 0]++;
    for(int i = 0, sum = 0; i < Max; i++) {
        int tmp = c[i]; c[i] = sum; sum += tmp;
    }
    rep(i, n) tmpSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    rep(i, n) SA[i] = tmpSA[i];
}

void constructSA() {
    rep(i, n) SA[i] = i, RA[i] = T[i];
    for(int k = 1; k < n; k <<= 1) {
        countingSort(k); countingSort(0);
        int r = tmpRA[SA[0]] = 0;
        fr(j, 1, n - 1) tmpRA[SA[j]] = (RA[SA[j]] == RA[SA[j - 1]] && RA[SA[j] + k] == RA[SA[j - 1] + k]) ? r : ++r;
        rep(j, n) RA[j] = tmpRA[j];
    }
}

void computeLCP() {
    Phi[SA[0]] = -1;
    fr(i, 1, n - 1) Phi[SA[i]] = SA[i - 1];
    for(int i = 0, L = 0; i < n; i++) {
        if(Phi[i] == -1) {PLCP[i] = 0; continue;}
        while(T[i + L] == T[Phi[i] + L]) L++;
        PLCP[i] = L;
        L = max(L - 1, 0);
    }
    rep(i, n) LCP[i] = PLCP[SA[i]];
}

bool check(int len, int fl) {
    int i, j, cnt;
    for(i = t + 1; i < n; i++) {
        if(LCP[i] < len) continue;
        fill0(vis);
        cnt = 1;
        j = i;
        vis[Sfrom[SA[j - 1]]] = 1;
        while(j < n && LCP[j] >= len) {
            if(Sfrom[SA[j]] != Sfrom[SA[j] + len - 1]) {
                j++; break;
            }
            if(!vis[Sfrom[SA[j]]]) vis[Sfrom[SA[j]]] = 1, cnt++;
            j++;
        }
        if(cnt > half) {
            if(!fl) return 1;
            for(int u = SA[j - 1]; u <= SA[j - 1] + len - 1; u++) putchar(T[u]);
            puts("");
        }
        i = j - 1;
    }
    return 0;
}

void solve() {
    int lo = 1, hi = mlen, mi, res = 0;
    while(lo <= hi) {
        mi = (lo + hi) / 2;
        if(check(mi, 0)) {
            lo = mi + 1;
            res = max(res, mi);
        }
        else hi = mi - 1;
    }
    if(!res) puts("?");
    else check(res, 1);
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif

    while(scanf("%d", &t) && t) {
        if(stupid++) printf("\n");
        n = mlen = 0;
        half = t / 2;
        rep(i, t) {
            scanf("%s", T + n);
            int cnt = 0;
            while(T[n] != '\0') Sfrom[n] = i, n++, cnt++;
            mlen = max(mlen, cnt);
            Wlen[i] = cnt;
            T[n++] = '$';
            T[n] = '\0';
        }
        T[n-1] = '#';
        constructSA();
        computeLCP();
        solve();
    }

    return 0;
}
