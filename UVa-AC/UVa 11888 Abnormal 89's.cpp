/*
  Name: UVa 11888 - Abnormal 89's
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 31/5/2012
  Description: kmp, palindrome, alindrome
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
#define MAXN 400400
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

int n, t, m, a, b[MAXN], c;

string T, P, ans;

void kmpPreprocess(){
    n = T.length();
    m = P.length();   
    int i = 0, j = -1; 
    b[0] = -1;
    while(i < m){
        while(j >= 0 && P[i] != P[j]) j = b[j];
        i++; j++;
        b[i] = j;    
    } 
}

int kmpSearch(){
    int res = 0;
    int i = 0, j = 0;
    while(i < n){
        while(j >= 0 && P[j] != T[i]) j = b[j];
        i++; j++;
        if(j == m){
            res++;
            j = b[j];    
        }     
    }   
    return res; 
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif

    scanf(" %d ", &t);
    FOR(i, 1, t){
        cin >> P;
        T = P + P;
        reverse(all(P));
        //debug(P);   
        kmpPreprocess();
        int tmp = kmpSearch();
        switch(tmp){
            case 0:
                ans = "simple";
                break;
            case 2:
                ans = "palindrome";
                break;
            default:
                ans = "alindrome";
                break;        
        } 
        cout << ans << endl;
    }

    return 0;
}
