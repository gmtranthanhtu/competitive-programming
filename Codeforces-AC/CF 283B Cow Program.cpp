/*
  Name: CF 283B Cow Program
  Author: 3T - mailto: gm.tranthanhtu@gmail.com
  Date: 18/3/2013
  Algorithm: dfs, dp
  Time Limit: 2.000s
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
typedef pair<ll, int> plli;

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
#define MAXN 200111
#define MOD 1000000007

//END OF COMPETITVE PROGRAMMING TEMPLATE
pair< ll, int> f[MAXN][2];
int n, a[MAXN], vis[MAXN][2];

pair< ll, int> go(int nn, int st) {
    pair< ll, int> &res = f[nn][st];
    if(res.ff != -10 && res.ss != -10) return res;

    if(vis[nn][st]) {
        res.ff = -1; res.ss = -1; return res;
    }
    vis[nn][st] = 1;
    int tmp;
    if(st) {
        tmp = nn - a[nn];
    }
    else tmp = nn + a[nn];

    //ket thuc
    if(tmp <= 0 || tmp > n) {
        res.ff = a[nn];
        res.ss = 2;
        return res;
    }

    //gap 1
    if(tmp == 1) {
        res.ff = a[nn];
        res.ss = st ^ 1;
        return res;
    }

    plli tp = go(tmp, st ^ 1);
    if(tp.ff == -1 && tp.ss == -1) {
        res = tp;
        return res;
    }
    res.ff = tp.ff + a[nn];
    res.ss = tp.ss;

    return res;
}

void gen() {
    fr(i, 2, n) rep(j, 2) f[i][j] = mp(-10, -10);
    fill0(vis);

    fr(i, 2, n) rep(j, 2) go(i, j);
}

ll solve(int u) {
    ll x = 1 + u, y = u;
    int curs = 1;
    if(f[x][curs].ss == -1) return -1;
    if(f[x][curs].ss == 2) return f[x][curs].ff + y;
    if(f[x][curs].ss == 0) return -1;
    if(f[x][curs].ss == 1) return f[x][curs].ff + y + u;
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif

    scanf("%d", &n);
    fr(i, 2, n) scanf("%d", &a[i]);
    gen();

    fr(i, 1, n - 1) {
        ll anss = solve(i);
        cout << anss << endl;
    }

    return 0;
}
