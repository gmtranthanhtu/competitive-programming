/*
  Name: UVa 10706 Number Sequence
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 7/5/2012
  Description: math, binay search
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

int64 getNum(int64 ff, int64 ll, int rr){
    return (ll - ff) / rr + 1;        
}

int64 getSum(int64 f, int64 l, int r){
    return (f + l) * getNum(f, l, r) / 2;        
}

int findn(int p1, int64 p2){ 
    int64 a1 = lens[p1].st;
    int64 dd = p1;
    int64 L;
    int64 RR;
    L = 0; RR = d[p1];
    int64 res = -1;
    while(L <= RR){
        int64 M = (L + RR) / 2;
        int64 tmp = M * (2 * a1 + (M - 1) * dd) / 2;
        if(tmp == p2){
            res = M;
            break;    
        }    
        if(tmp > p2) RR = M - 1;
        else L = M + 1;
    }    
    if(res == -1) res = L;
    return res;
}

int findDigit2(int pos){
    int dn = 0;
    FOR(i, 1, DIGIT){
        if(Seg[i].st <= pos && Seg[i].en >= pos){
            dn = i;
            break;    
        }    
    }    

    int p = findn(dn, pos - Seg[dn].st + 1);
    int64 tmp = (p - 1) * (2 * lens[dn].st + (p - 1 - 1) * dn) / 2;
    int tmp2 = pos - tmp + 1 - Seg[dn].st;
    return findDigit(tmp2);
}

void Gen(){
    
    //cal ds
    ds[0] = 0;
    ds[1] = 1;
    FOR(i, 2, 11){
        ds[i] = ds[i - 1] + d[i - 1] * (i - 1);
    }
    
    //cal lens
    lens[0].st = 0; lens[0].en = 0;
    lens[1].st = 1; lens[1].en = 9;
    FOR(i, 2, DIGIT){
        lens[i].st = lens[i - 1].en + i;
        lens[i].en = lens[i].st + (d[i] - 1) * i;    
    }
    
    //cal segment
    Seg[0].st = 0; Seg[0].en = 0;
    Seg[1].st = 1; Seg[1].en = 45;
    FOR(i, 2, DIGIT){
        Seg[i].st = Seg[i - 1].en + 1;    
        Seg[i].en = Seg[i].st - 1 + getSum(lens[i].st, lens[i].en, i);
    }    
}

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    Gen();
    scanf("%d", &t);
    while(t--){
        cin >> n;
        cout << findDigit2(n) << endl;    
    }
    return 0;
}
