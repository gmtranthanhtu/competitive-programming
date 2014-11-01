/*
  Name: UVa 10141 - Request for Proposal
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 8/5/2012
  Description: ad hoc
  Time Limit: 3.000s
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

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef struct brand{
    int idx, meet;
    double price;
    string name;
    };
    
brand arr[1005];
int n, t, a, b, c(0), p;

string S;

bool cmp(const brand& b1, const brand& b2){
    return ((b1.meet > b2.meet) ||(b1.meet == b2.meet && b1.price < b2.price) || (b1.meet == b2.meet && b1.price == b2.price && b1.idx < b2.idx)) ;   
}

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    while(scanf(" %d %d ", &n, &p) && n){
        FOR(i, 1, n) getline(cin, S);
        FOR(i, 1, p){
            arr[i].idx = i;
            getline(cin, arr[i].name) ;
            scanf(" %lf %d ", &arr[i].price, &arr[i].meet);  
            FOR(j, 1, arr[i].meet) getline(cin, S);  
        } 
        sort(arr + 1, arr + p + 1, cmp);
        c++;
        if(c > 1) cout << endl;
        printf("RFP #%d\n", c);
        cout << arr[1].name << endl;      
    }
    return 0;
}
