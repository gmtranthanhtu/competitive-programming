/*
  Name: TC SRM div 2 250
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 20/5/2012
  Description: sum xor
  Time Limit: 2.000s
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
#define MAXN 33
#define MOD 1000000007

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, t, a, b, c;

int64 Pow2[50] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648LL,4294967296LL,8589934592LL};

int64 countOne(int64 N){
    if(N % 2) return N / 2 + 1;
    else return N / 2;    
}

int isOne(int64 L, int64 R, int i){
    if(i == 0){
        int64 One = 0LL;
        One = countOne(R) - countOne(L - 1);
        return One % 2;        
    }
    int64 One = 0LL;
    int64 r = L % (Pow2[i] * 2);
    if(r >= Pow2[i]){
        One += Pow2[i] * 2 - r;        
        if(L + One - 1 >= R){
            One = R - L + 1;
            if(One % 2) return 1;
            else return 0;    
        } 
    }  
    
    int64 r2 = R % (Pow2[i] * 2);
    if(r2 >= Pow2[i]){
        One+= (Pow2[i] - (Pow2[i] * 2 - r2) + 1);        
    }
    if(One % 2) return 1;
    return 0;
}


typedef struct EllysXors{
    long long getXor(long long L, long long R){
        if(L == R) return L;
        int64 res = 0LL;
        FOR(i, 0, MAXN){
            if(isOne(L, R, i)) res += Pow2[i];     
        }
        return res;        
    }    
};

