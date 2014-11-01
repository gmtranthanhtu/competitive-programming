/*
  Name: LightOJ 1279 - Graph Coloring
  Author: 3T - mailto: gm.tranthanhtu@gmail.com
  Date: 27/3/2013
  Algorithm: gaussian elimination, big mod
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
#define MAXN 100000
#define MOD 1000000007

//END OF COMPETITVE PROGRAMMING TEMPLATE
int t, n, m, k, numAr, nosol, ans;
vi adj[105];

ll g[105][105];

ll x, y, d;

void ini() {
    fr(i, 1, n) fr(j, 1, n + 1) g[i][j] = 0ll;
    fr(i, 1, n) {
        g[i][i] = 1;
        rep(j, adj[i].size()) g[i][adj[i][j]] = -1;
    }
}

ll getMod(ll N, int M) {
    if(N < 0) { // --> fasten the method
        ll tmp = N + INF;
        N = tmp % M - INF % M;
    }
    while(N < 0) N += M;
    return N % M;
}

void extendedEuclid(ll A, ll B) {
    if(B == 0) {x = 1; y = 0; d = A; return;}
    extendedEuclid(B, A % B);
    ll x1 = y;
    ll y1 = x - (A / B) * y;
    x = x1;
    y = y1;
}

ll getExtendedEuclid(ll N) {
    extendedEuclid(N, k);
    return getMod(x, k);
}

void gaussian() {
    int i = 1, j = 1;
    while(i <= n && j <= n) {
        if(g[i][j] == 0) {
            int p = -1;
            fr(l, i + 1, n) if(g[l][j] != 0) {
                p = l; break;
            }
            if(p == -1) {
                j++;
                continue;
            }
            fr(l, j, n + 1) swap(g[i][l], g[p][l]);
        }
        if(g[i][j] < 0) {
            fr(l, j, n + 1) g[i][l] = getMod(g[i][l], k);
        }
        if(g[i][j] != 1) {
            ll tmp = getExtendedEuclid(g[i][j]);
            fr(l, j, n + 1) g[i][l] = getMod(g[i][l] * tmp, k);
        }
        fr(q, i + 1, n) {
            if(g[q][j] == 0) continue;
            ll tmp = -g[q][j];
            fr(l, j, n + 1) {
                g[q][l] = g[i][l] * tmp + g[q][l]; g[q][l] = getMod(g[q][l], k);
            }
        }
        i++; j++;
    }
    nosol = numAr = 0;
    fr(p, 1, n) {
        int cnt = 0;
        fr(q, 1, n) if(g[p][q] != 0) cnt++;
        if(cnt == 0 && g[p][n + 1] != 0){
            nosol = 1; return;
        }
        if(!cnt) numAr++;
    }
}

int bigMod(int P, int Q, int M) {
    if(!Q) return 1;
    if(Q % 2) {
        ll tmp = 1ll * P * bigMod(P, Q - 1, M);
        return tmp % M;
    }
    ll tmp = 1ll * bigMod(P, Q/2, M);
    tmp *= tmp;
    return tmp % M;
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif

    scanf("%d", &t);
    fr(tt, 1, t) {
        scanf("%d %d %d", &n, &m, &k);
        fr(i, 1, n) adj[i].clear();
        int u, v;
        fr(i, 1, m) scanf("%d %d", &u, &v), adj[u].pb(v), adj[v].pb(u);
        ini();
        gaussian();
        if(nosol) ans = 0;
        else ans = bigMod(k, numAr, MOD);
        printf("Case %d: %d\n", tt, ans);
    }

    return 0;
}
