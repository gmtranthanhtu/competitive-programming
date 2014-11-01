/*
  Name: UVa 11415 - Count the Factorials
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 8/5/2012
  Description: prime, factorial, binary search
  Time Limit: 5.000s
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
#define MAXN 3000050
#define TRY 3000000

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

bool isPrime[MAXN + 10];
int n, t, a, b, c, np, na;
int Prime[MAXN + 10], ans[MAXN + 10], cf[MAXN + 10], cf2[MAXN + 10];

void Gen2(){
    isPrime[0] = isPrime[1] = false;        
}

int countNumberFactor(int v){
    int res = 0;
    for(int i = 1; Prime[i] * Prime[i] <= v; i++){
        if(v % Prime[i] == 0){
            while(v % Prime[i] == 0){
                v /= Prime[i];
                res++;    
            }    
        }    
    } 
    if(v != 1) res++;
    return res;   
}

void Gen(){
    memset(cf, -1, sizeof cf);
    memset(cf2, 0, sizeof cf2);
    isPrime[0] = isPrime[1] = false;
    memset(isPrime, true, sizeof isPrime);
    for(int i = 2; i * i <= MAXN; i++){
        if(!isPrime[i]) continue;
        for(int j = i; j * i <= MAXN; j++){
            isPrime[i * j] = false;    
        }    
    } 
    np = 0;
    FOR(i, 2, MAXN){
        if(isPrime[i]) Prime[++np] = i; 
    }   
    
    //fill cf2
    FOR(i, 2, TRY){
        cf2[i] = cf2[i - 1] + countNumberFactor(i);        
    }
}

//int countFactor(int p, int N){
//    int res = 0;
//    while(N){
//        res += N/p;
//        N /= p;    
//    }    
//    return res;
//}

//int countFact(int a){
//    if(cf[a] != -1) return cf[a];
//    int res = 0;
//    memset(ans, 0, sizeof ans);
//    FOR(i, 1, np){
//        na = i;
//        if(Prime[i] > a){
//            na--;
//            break;    
//        }    
//        ans[i] = countFactor(Prime[i], a);
//    }   
//    FOR(i, 1, na) res += ans[i];
//    return cf[a] = res;           
//}

int findn(){
    int lo = 0, hi = TRY, mi, tmp;
    while(lo <= hi){
        mi = (lo + hi) / 2;
        tmp = cf2[mi];
        if(tmp == n) return mi;
        if(tmp > n) hi = mi - 1;
        else lo = mi + 1;  
    } 
    return hi;   
}

void solve(){  
    printf("%d\n", findn() + 1);
}


int main () {
   // freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    Gen2();
    Gen();
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        solve();    
    }
    return 0;
}
