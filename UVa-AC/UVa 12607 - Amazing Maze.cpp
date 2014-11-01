/*
  Name: UVa 12607 - Amazing Maze
  Author: 3T - mailto: gm.tranthanhtu@gmail.com
  Date: 18/3/2013
  Algorithm: dijsktra set
  Time Limit: 15.000s
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
typedef pair< ii, ii > i4;
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
#define MAXN 105
#define MAXS 257
#define MOD 1000000007

//END OF COMPETITVE PROGRAMMING TEMPLATE
char maze[MAXN][MAXN];
int m, n, K, gate[MAXN][MAXN], chest[MAXN][MAXN], d[MAXN][MAXN][MAXS], lim, x, y;
iii st, en;
set<  i4 > S;

int getMod(int N, int M) {
    while(N < 0) N += M;
    return N % M;
}

void gen() {
    rep(i, n) rep(j, m) {
        if(maze[i][j] == 'N') gate[i][j] = 0;
        else if(maze[i][j] == 'E') gate[i][j] = 1;
        else if(maze[i][j] == 'S') gate[i][j] = 2;
        else if(maze[i][j] == 'W') gate[i][j] = 3;
    }
    lim = (1 << K) - 1;
    st = mp(0, mp(0, 0));
    en = mp(lim, mp(n - 1, m - 1));
    rep(i, n) rep(j, m) rep(k, lim + 1) d[i][j][k] = INF;
    d[0][0][0] = 0;
    S.clear();
    S.insert(mp(ii(0, 0), ii(0, 0)));
}

bool ok(int x, int y) {
    return (x < n && x >= 0 && y < m && y >= 0);
}

void dijsktra() {
    while(!S.empty()) {
        i4 tmp = *S.begin();
        S.erase(S.begin());

        int ux = tmp.ss.ff, uy = tmp.ss.ss, mask = tmp.ff.ss;
        if(ux == n - 1 && uy == m - 1 && mask == lim) return;
        if(chest[ux][uy] != -1) {
            if(!isOnBit(mask, chest[ux][uy])) {
                int nmask = mask | two(chest[ux][uy]);
                if(d[ux][uy][nmask] > d[ux][uy][mask]) {
                    if(d[ux][uy][nmask] != INF) {
                        S.erase(S.find(mp(mp(d[ux][uy][nmask], nmask), mp(ux, uy))));
                    }
                    d[ux][uy][nmask] = d[ux][uy][mask];
                    S.insert(mp(mp(d[ux][uy][nmask], nmask), mp(ux, uy)));
                    continue;
                }
            }
        }

        rep(i, 4) {
            int vx = ux + dx4[i], vy = uy + dy4[i], cost;
            cost = getMod(i - (gate[ux][uy] + (d[ux][uy][mask] % 4)) % 4, 4) + 1;
            if(!ok(vx, vy)) continue;
            if(d[vx][vy][mask] > d[ux][uy][mask] + cost) {
                if(d[vx][vy][mask] != INF) {
                    S.erase(S.find(mp(mp(d[vx][vy][mask], mask), mp(vx, vy))));
                }
                d[vx][vy][mask] = d[ux][uy][mask] + cost;
                S.insert(mp(mp(d[vx][vy][mask], mask), mp(vx, vy)));
            }
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif

    while(scanf(" %d %d ", &n, &m) && (n + m)) {
        rep(i, n) gets(maze[i]);
        fill(chest, -1);
        scanf("%d", &K);
        rep(i, K) scanf("%d %d", &x, &y), chest[x - 1][y - 1] = i;
        gen();
        dijsktra();
        printf("%d\n", d[n - 1][m - 1][lim]);
    }

    return 0;
}
