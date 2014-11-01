/*
  Name: TCO2013 Round 1B Medium EllysFigurines
  Author: 3T - mailto: gm.tranthanhtu@gmail.com
  Date: 4/3/2013
  Algorithm: bitwise, brute force
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

#define ull unsigned long long
#define ll long long
#define ld double
#define ui unsigned int
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;


inline int two(int n) {return 1 << n;}
inline int isOnBit(int n, int b) {return (n >> b) & 1;}
inline void onBit(int & n, int b) {n |= two(b);}
inline void offBit(int & n, int b) {n &= ~two(b);}
inline int lastBit(int n) {return n & (-n);}
inline int cntBit(int n) {int res = 0; while(n && ++res) n -= n &(-n); return res;}

#define PI 3.1415926535897932385
#define INF 1000111222

//END OF COMPETITVE PROGRAMMING TEMPLATE
int n, m, lim, c, r;
vector <string> b, bt;

int solve(){
        lim = n - r + 1;
        int res = INF;
        rep(i, (1 << lim)) {
            int sum = 0;
            bt = b;
            int tmp = i, id = 0;
            while(tmp) {
                if(tmp % 2 == 0) {
                    id++;
                    tmp /= 2;
                    continue;
                }
                sum ++;
                fr(u, id, id + r - 1) rep(v, m) bt[u][v] = '.';
                id++;
                tmp /= 2;
            }
            vi a;
            rep(u, m) {
                rep(v, n) {
                    if(bt[v][u] == 'X') {
                        a.pb(u);
                        break;
                    }
                }
            }
            if(!a.size()) res = min(res, sum);
            int u = 0;
            while(u < a.size()) {
                int len = a[u] + c - 1;
                while(u < a.size() && len >= a[u]) u++;
                sum++;
            }
            res = min(res, sum);
        }
        return res;
}

void conver() {
    vs tmpb;
    rep(i, m) {
        string s = "";
        rep(j, n) {
            s += b[j][i];
        }
        tmpb.pb(s);
    }
    swap(m, n); swap(r, c); b = tmpb;
}

typedef struct EllysFigurines {
    int getMoves(vector <string> board, int R, int C) {
        b = board;
        r = R; c = C;
        n = board.size();
        m = board[0].length();
        int cnt = 0;
        rep(i, n) rep(j, m) cnt += (b[i][j] == 'X');
        if(cnt == 0) return 0;
        if(r >= n || c >= m) return 1;
        int res = solve();
        conver();
        res = min(res, solve());
        return res;
    };
};
