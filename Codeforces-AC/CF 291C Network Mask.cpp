/*
  Name: CF 291C Network Mask
  Author: 3T - mailto: gm.tranthanhtu@gmail.com
  Date: 13/4/2013
  Algorithm: brute force
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
typedef struct IP {
    int a, b, c, d;
};

vector <IP> v;
int tmp[8], sz, n, k;
IP arr[MAXN + 5];
typedef pair <pair <int, int>, pair<int, int> > i4;
map <i4, int> M;

void gen() {
    rep(i, 8) if(!i) tmp[i] = two(7);
    else tmp[i] = tmp[i - 1] + two(7 - i);
    IP ip;
    ip.b = ip.c = ip.d = 0;
    rep(i, 8) ip.a = tmp[i], v.pb(ip);
    ip.a = tmp[7]; ip.c = ip.d = 0;
    rep(i, 8) ip.b = tmp[i], v.pb(ip);
    ip.b = ip.a = tmp[7]; ip.d = 0;
    rep(i, 8) ip.c = tmp[i], v.pb(ip);
    ip.b = ip.c = ip.a = tmp[7];
    rep(i, 8) ip.d = tmp[i], v.pb(ip);
    sz = v.size() - 1;
    //rep(i, v.size()) printf("%d.%d.%d.%d\n", v[i].a, v[i].b, v[i].c, v[i].d);
}

int ok(int p) {
    M.clear();
    int res = 0;
    rep(i, n) {
        IP tmp;
        tmp.a = arr[i].a & v[p].a;
        tmp.b = arr[i].b & v[p].b;
        tmp.c = arr[i].c & v[p].c;
        tmp.d = arr[i].d & v[p].d;
        i4 tmp2 = mp(mp(tmp.a, tmp.b), mp(tmp.c, tmp.d));
        if(!M.count(tmp2)) M[tmp2] = 1, res++;
    }
    return res == k;
}

void solve() {
    rep(i, sz) if(ok(i)) {
        printf("%d.%d.%d.%d\n", v[i].a, v[i].b, v[i].c, v[i].d);
        return;
    }
    printf("-1\n");
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif

    gen();
    scanf("%d %d", &n, &k);
    rep(i, n) scanf("%d.%d.%d.%d", &arr[i].a, &arr[i].b, &arr[i].c, &arr[i].d);
    solve();

    return 0;
}
