/*
  Name: UVa 12598 - Starting School
  Author: 3T - mailto: gm.tranthanhtu@gmail.com
  Date: 2/3/2013
  Algorithm: ad hoc
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
#define MAXN 50000
#define MOD 1000000007

//END OF COMPETITVE PROGRAMMING TEMPLATE

int t, n, k, q , a[MAXN + 5], ans[MAXN + 5], x, q2;
ii qu[MAXN + 5];

void solve() {
    a[0] = 0;
    a[k + 1] = INF;
    qu[0].ff = k;
    int cur = 0;
    fr(i, 1, q2) {
        int tmp = qu[i].ff - qu[i - 1].ff;
        if(!tmp) {ans[qu[i].ss] = ans[qu[i - 1].ss]; continue;}
        while(1) {
            while(a[cur + 1] - a[cur] <= 1) cur++;
            int dif = a[cur + 1] - a[cur] - 1;
            if(tmp <= dif) {
                a[cur] += tmp;
                ans[qu[i].ss] = a[cur];
                break;
            }
            else {
                cur++;
                tmp -= dif;
            }
        }
    }
}

bool cmp (const ii &p1, const ii &p2) {
    return p1.ff < p2.ff;
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif

    scanf("%d", &t);
    fr(tt, 1, t) {
        scanf("%d %d %d", &n, &k, &q);
        fr(i, 1, k) scanf("%d", &a[i]);
        q2 = 0;
        fr(i, 1, q) {
            scanf("%d", &x);
            if(x <= k) {ans[i] = a[x];}
            else {
                q2++;
                qu[q2] = mp(x, i);
            }
        }
        sort(a + 1, a + k + 1);
        sort(qu + 1, qu + q2 + 1, cmp);
        solve();
        printf("Case %d:\n", tt);
        fr(i, 1, q) printf("%d\n", ans[i]);
    }

    return 0;
}
