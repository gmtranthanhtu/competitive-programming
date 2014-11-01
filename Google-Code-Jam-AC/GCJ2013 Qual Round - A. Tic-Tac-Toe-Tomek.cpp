/*
  Name: GCJ Qualifications A Tic-Tac-Toe-Tomek
  Author: 3T - mailto: gm.tranthanhtu@gmail.com
  Date: 13/4/2013
  Algorithm: ad hoc
  Time Limit: .000s
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
#define INF 1000111
#define EPS 1e-7
#define MAXN 100000
#define MOD 1000000007

//END OF COMPETITVE PROGRAMMING TEMPLATE
char line[10], a[10][10], s[][30] = {"X won", "O won", "Game has not completed", "Draw"};
int t, c[10][10];

int check() {
    int cnt = 0;
    rep(i, 4) rep(j, 4) {
        if(a[i][j] == 'X') c[i][j] = 1;
        if(a[i][j] == 'O') c[i][j] = 0;
        if(a[i][j] == '.') c[i][j] = -INF, cnt++;
        if(a[i][j] == 'T') c[i][j] = MAXN;
    }
    int sum3 = 0, sum4 = 0;
    rep(i, 4) {
        int sum1 = 0, sum2 = 0;
        rep(j, 4) sum1 += c[i][j], sum2 += c[j][i];
        if(sum1 == MAXN + 3 || sum2 == MAXN + 3 || sum1 == 4 || sum2 == 4) return 0;
        if(sum1 == MAXN || sum2 == MAXN || !sum1 || !sum2) return 1;
        sum3 += c[i][i];
        sum4 += c[i][3 - i];
    }
    if(sum3 == MAXN + 3 || sum4 == MAXN + 3 || sum3 == 4 || sum4 == 4) return 0;
    if(sum3 == MAXN || sum4 == MAXN || !sum3 || !sum4) return 1;

    if(!cnt) return 3;
    return 2;
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif

    scanf(" %d ", &t);
    fr(tt, 1, t) {
        rep(i, 4) gets(a[i]);
        if(tt < t) gets(line);

        printf("Case #%d: %s\n", tt, s[check()]);
    }

    return 0;
}
