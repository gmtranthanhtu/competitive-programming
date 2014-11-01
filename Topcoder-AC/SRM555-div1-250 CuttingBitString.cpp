/*
  Name: TC SRM 555 div1 250 CuttingBitString
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 19/10/2012
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

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define REP(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define debug(x) cout<<#x<<": "<<x<<endl

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
#define MAXN 20000
#define MOD 1000000007

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;

#define _int string
#define Class CuttingBitString
#define Method getmin

template<typename T>inline T gcd(T a, T b){if (b == 0)return a;else return gcd(b, a % b);}
template<typename T>inline T lcm(T a, T b){return (a * b) / gcd(a, b);}

int n, t, m, a, b, c, len;
vs Power;

string toBinary(int64 N){
    string res ="";
    while(N!=0){
        res += N%2 + '0';
        N/=2;    
    }
    reverse(all(res));
    return res;    
}

void Init(){
    int64 tmp = 1ll;
    Power.pb("1");
    FOR(i,1,24){
        tmp *= 5;
        Power.pb(toBinary(tmp));    
    }       
    len = Power.size(); 
}

bool isP(string ss){
    if(ss[0] == '0') return false;
    REP(i,len) if(ss == Power[i]) return true;
    return false;        
}

bool ok(string s, int k){
    if(s[0] =='0') return false;
    if(k==1){
        if(isP(s)) return true;
        return false;    
    } 
    int l = s.length();
    if(l < k) return false;
    FOR(i,1,l-1){
        string s1 = s.substr(0,i);
        string s2 = s.substr(i,l-i);
        if(isP(s1) && ok(s2,k-1)) return true;    
    }   
    return false;
}

typedef struct Class{
    int Method(_int S){
        int res = -1;
        Init();
        FOR(i, 1, 50){
            if(ok(S,i)) return i;    
        }
        
        return res;    
    }        
};
