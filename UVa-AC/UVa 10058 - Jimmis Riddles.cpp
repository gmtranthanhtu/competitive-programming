/*
  Name: UVa 10058 - Jimmi's Riddles
  Author: 3T - mailto: gm.tranthanhtu@gmail.com
  Date: 28/3/2013
  Algorithm: finite automata
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

/*STATEMENT = ACTION | STATEMENT , ACTION
ACTION = ACTIVE_LIST VERB ACTIVE_LIST
ACTIVE_LIST = ACTOR | ACTIVE_LIST and ACTOR
ACTOR = NOUN | ARTICLE NOUN
ARTICLE = a | the
NOUN = tom | jerry | goofy | mickey | jimmy | dog | cat | mouse
VERB = hate | love | know | like | VERBs*/

//END OF COMPETITVE PROGRAMMING TEMPLATE

string noun[] = { "tom" , "jerry" , "goofy" , "mickey" , "jimmy" , "dog" , "cat", "mouse"};
string verb[] = {"hate", "love", "know", "like"};
map <string, int> N;
map <string, int> V;
map <string, int> A;

vi automat[6];

string s;
int len, cur;

void gen() {
    rep(i, 8) N[noun[i]] = 1;
    rep(i, 4) V[verb[i]] = 1;
    A["the"] = 1; A["a"] = 1;

    rep(i, 6) automat[i].assign(5, -1);
    automat[0][2] = 1; automat[0][3] = 2;
    automat[1][3] = 2;
    automat[2][1] = 0; automat[2][4] = 3;
    automat[3][2] = 4; automat[3][3] = 5;
    automat[4][3] = 5;
    automat[5][1] = 3; automat[5][0] = 0;
}

int getType(string S) {
    if(S == ",") return 0;
    if(S == "and") return 1;
    if(S == "a" || S == "the") return 2;
    if(N.count(S) != 0) return 3;
    int len = S.length();
    int k = len - 1;
    while(k >= 0 && S[k] == 's') k--;
    if(k < 0) return -1;
    string tmp = S.substr(0, k + 1);
    if(V.count(tmp)) return 4;
    return -1;
}


int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif

    gen();
    while(getline(cin, s)) {
        len = s.length();
        cur = 0;
        int i = 0;
        while(1) {
            while(i < len && s[i] == ' ') i++;
            if(i >= len) break;

            string tmp = "";
            while(i < len && s[i] != ' ') tmp += s[i], i++;

            int tp = getType(tmp);
            if(tp == -1) {
                cur = 0; break;
            }
            cur = automat[cur][tp];
        }
        if(cur == 5) puts("YES I WILL");
        else puts("NO I WON'T");
    }

    return 0;
}
