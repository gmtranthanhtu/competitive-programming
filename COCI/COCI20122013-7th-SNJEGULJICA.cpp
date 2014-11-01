/*
  Name: COCI 2012/2013 7th contest SNJEGULJICA
  Author: 3T - mailto: gm.tranthanhtu@gmail.com
  Date: 6/4/2013
  Algorithm: RMQ
  Time Limit: 1.000s
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
#define MAXN 220000
#define MAXM 1000008
#define MOD 1000000007

//END OF COMPETITVE PROGRAMMING TEMPLATE
int n, m, a[MAXN], op, b, c, idx[2][MAXN], len;
vi M1, M2;

void ini(int node, int l, int r, vi &M, int id) {
    if(l == r) {
        M[node] = l;
        return;
    }
    ini(node * 2, l, (l + r) / 2, M, id);
    ini(node * 2 + 1, (l + r) / 2 + 1, r, M, id);

    if(idx[id][M[node * 2]] >= idx[id][M[node * 2 + 1]]) M[node] = M[node * 2 + 1];
    else M[node] = M[node * 2];
}

int query(int node, int l, int r, vi &M, int id, int i, int j) {
    if(i > r || j < l) return -INF;
    if(l >= i && r <= j) return M[node];

    int tmp1 = query(node * 2, l, (l + r) / 2, M, id, i, j);
    int tmp2 = query(node * 2 + 1, (l + r) / 2 + 1, r, M, id, i, j);
    if(tmp1 == -INF) return tmp2;
    if(tmp2 == -INF) return tmp1;
    return (idx[id][tmp1] <= idx[id][tmp2]) ? tmp1 : tmp2;
}

int check() {
    if(b > c) swap(b, c);
    int lo = idx[0][query(1, 1, n, M1, 0, b, c)], hi = -1 * idx[1][query(1, 1, n, M2, 1, b, c)];
    return (hi - lo == c - b);
}

int findNode(int node, int l, int r, int v) {
    if(l == r && l == v) return node;
    if(v >= l && v <= (l + r) / 2) return findNode(node * 2, l, (l + r) / 2, v);
    else return findNode(node * 2 + 1, (l + r) / 2 + 1, r, v);
}

void update(int node, vi &M, int id) {
    if(!node) return;
    if(idx[id][M[node * 2]] < idx[id][M[node]]) M[node] = M[node * 2];
    if(idx[id][M[node * 2 + 1]] < idx[id][M[node]]) M[node] = M[node * 2 + 1];
    update(node / 2, M, id);
}

int main () {
    #ifndef ONLINE_JUDGE
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif

    scanf("%d %d", &n, &m);
    fr(i, 1, n) scanf("%d", &a[i]), idx[0][a[i]] = i, idx[1][a[i]] = -1 * i;
    len = 2 * (1 << (1 + (int)floor(log2(n))));
    M1.assign(len + 1, -INF); M2.assign(len + 1, -INF);
    ini(1, 1, n, M1, 0);
    ini(1, 1, n, M2, 1);
    rep(i, m) {
        scanf("%d %d %d", &op, &b, &c);
        if(op == 2) printf("%s\n", check() ? "YES" : "NO");
        else if(op == 1) {
            int uu = findNode(1, 1, n, a[c]), vv = findNode(1, 1, n, a[b]);
            idx[0][a[c]] = b; idx[0][a[b]] = c;
            update(uu / 2, M1, 0); update(vv / 2, M1, 0);
            idx[1][a[c]] = -1 * b; idx[1][a[b]] = -1 * c;
            update(uu / 2, M2, 1); update(vv / 2, M2, 1);
            swap(a[b], a[c]);
        }
    }

    return 0;
}
