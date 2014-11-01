/*
  Name: UVa 967 Circular
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 15/9/2012
  Description: adhoc, prime
  Time Limit: .000s
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
#define MAXN 1000000
#define MOD 1000000007

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;

template<typename T>inline T gcd(T a, T b){if (b == 0)return a;else return gcd(b, a % b);}
template<typename T>inline T lcm(T a, T b){return (a * b) / gcd(a, b);}

int n, t, m, a, b, c, sum[MAXN + 5];

bool prime[MAXN + 5], ok[MAXN + 5];

vi num;

bool isCircular(int u){
    num.clear();
    num.pb(u);
    if(ok[u]) return true;
    if(!prime[u]) return false;
    
    int digit = 1, tmp = u, d;
    while(tmp){
        digit*=10;
        tmp/=10;
    }        
    digit/=10;
    
    bool can = true;
    tmp = u;
    d = tmp%10;
    tmp /= 10; tmp += d*digit;
    while(tmp!=u){
        if(prime[tmp]) num.pb(tmp);
        else{
            can = false;
            break;    
        }    
        tmp = (tmp%10) * digit + tmp/10;
    }
    if(can){
        REP(i,num.size()) ok[num[i]] = true;    
    }
    return can;
}

void preCal(){
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= MAXN; i++){
        if(!prime[i]) continue;
        for(int j = 2; j * i <= MAXN; j++) prime[i*j] = false;    
    }    
    
    memset(ok, false, sizeof ok);
    memset(sum, 0, sizeof sum);
    
    FOR(i,100,MAXN){
        sum[i] = sum[i-1];
        if(isCircular(i)) sum[i]++;    
    }
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
     
    preCal();
    while(scanf("%d", &a) && a!=-1){
        scanf("%d", &b); 
        c = sum[b] - sum[a-1];
        if(!c) printf("No Circular Primes.\n");
        else if(c == 1) printf("%d Circular Prime.\n", c);
        else printf("%d Circular Primes.\n", c);   
    }
    return 0;
}
