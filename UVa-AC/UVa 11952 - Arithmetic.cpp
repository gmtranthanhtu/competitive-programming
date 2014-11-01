/*
  Name: UVa 11952 - Arithmetic
  Author: 3T - mailto: gm.tranthanhtu@gmail.com
  Date: 21/3/2013
  Algorithm: brute force
  Time Limit: 3.000s
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
int a, b, c, t, a1, b1, c1, MaxD, Sum[20];
vi A, B, C;

void getDigit(int N, vi &V, int &n1, int &M) {
    while(N) {
        int d = N % 10;
        if(d == 1) n1++;
        M = max(M, d);
        V.pb(d);
        N /= 10;
    }
}

int ok(int bs) {
    int asz = A.size(), bsz = B.size();
    int r = 0;
    fill0(Sum);
    rep(i, max(asz, bsz)) {
        int d1 = 0, d2 = 0;
        if(i <= asz - 1) d1 = A[i];
        if(i <= bsz - 1) d2 = B[i];
        Sum[i] = (r + d1 + d2) % bs;
        r = (r + d1 + d2) / bs;
    }
    Sum[max(asz, bsz)] = r;
    int len = -1;
    frr(i, 10, 0) if(Sum[i] != 0) {
        len = i; break;
    }
    string SC = toStr(c);
    string SS = "";
    frr(i, len, 0) SS += toStr(Sum[i]);
    return SS == SC;
}

int solve() {
    if(a == 0 && b == 0 && c == 0) return 2;
    if(a == 0 && b == 0 && c != 0) return 0;
    A.clear();
    B.clear();
    C.clear();
    a1 = b1 = c1 = MaxD = 0;
    getDigit(a, A, a1, MaxD);
    getDigit(b, B, b1, MaxD);
    getDigit(c, C, c1, MaxD);
    if(a1 >= 1 && b1 >= 1 && c1 >= 1 && a1 == A.size() && b1 == B.size() && c1 == C.size()) {
        if(a1 + b1 == c1) return 1;
    }
    fr(i, max(2, MaxD + 1), 100) {
        if(ok(i)) return i;
    }
    return 0;
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif

    scanf("%d", &t);
    while(t--) {
        scanf("%d + %d = %d", &a, &b, &c);
        printf("%d\n", solve());
    }

    return 0;
}
