/*
  Name: UVa 10427 Naughty Sleepy Boys
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 7/5/2012
  Description: math, adhoc
  Time Limit: 1.000s
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
#define INF 2147483647
#define INF2 9000000
#define EPS 1e-7
#define MAXN 100000
#define DIGIT 10


#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

typedef struct Segment{
    int64 st, en;
    };

Segment Seg[50];

int  n, t, a, b, c;


Segment lens[50];
int64 ds[50];
int64 arr[MAXN + 1];
int64 d[] = {0, 9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 900000000, 9000000000LL};
int64 nums[] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 10000000, 1000000000, 10000000000LL}; 
string S;
char line[MAXN];

int findDigit(int pos){
    int dn = 0;
    FOR(i, 1, DIGIT){
        if(pos >= ds[i] && pos < ds[i + 1]){
            dn = i;
            break;    
        }    
    } 
    int v = (pos - ds[dn]) % dn + 1;
    int64 num = (pos - ds[dn]) / dn + nums[dn];
    v = dn + 1 - v;
    int tmp;
    
    FOR(i, 1, v){
        tmp = num % 10;
        num /= 10;    
    }       
    return tmp;     
}



void Gen(){
    
    //cal ds
    ds[0] = 0;
    ds[1] = 1;
    FOR(i, 2, 11){
        ds[i] = ds[i - 1] + d[i - 1] * (i - 1);
    }       
}

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    Gen();
    //scanf("%d", &t);
    while(cin >> n){
        cout << findDigit(n) << endl;    
    }
    return 0;
}
