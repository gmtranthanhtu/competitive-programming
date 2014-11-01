/*
  Name: GCJ2012 Qualification round - A. Speaking in Tongues
  Author: 3T
  Date: 06-04-12 21:47
  Description: ad hoc
  Time Limit:
*/

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a) | (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

#define PI 3.1415926535897932385
#define INF 1000111222
#define EPS 1e-7
#define MAXN 100000

#define INP "A-small-attempt0.in"
#define OUT "A-small-attempt0.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int a, b, c, d, e, f, g, h, n;
char line[1000];

map <char, char> M;

void solve(){
    REP(i, strlen(line)){
        if(line[i] == ' ') cout << line[i];
        else printf("%c", M[line[i]]);    
    }
    cout << endl;    
}

void Gen(){
    M['a'] = 'y'; M['b'] = 'h'; M['c'] = 'e'; M['d'] = 's'; M['e'] = 'o'; 
    M['f'] = 'c'; M['g'] = 'v'; M['h'] = 'x'; M['i'] = 'd'; M['j'] = 'u';
    M['k'] = 'i'; M['l'] = 'g'; M['m'] = 'l'; M['n'] = 'b'; M['o'] = 'k'; 
    M['p'] = 'r'; M['r'] = 't'; M['s'] = 'n'; M['t'] = 'w';   
    M['u'] = 'j'; M['v'] = 'p'; M['x'] = 'm'; M['y'] = 'a'; M['w'] = 'f';    
    M['q'] = 'z';
    M['z'] = 'q';
}

int main () {
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    Gen();
    scanf(" %d ", &n);
    FOR(i, 1, n){
        gets(line);
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
