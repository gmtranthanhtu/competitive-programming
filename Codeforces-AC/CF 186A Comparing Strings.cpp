/*
  Name: Codeforces 186A Comparing Strings
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 4/5/2012
  Description: string, implementation
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
#define MAXN 100000

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, t, a, b, c, len1, len2, diff[10], appear[1000];

string s1, s2;

bool isSame(){
    len1 = s1.length();
    len2 = s2.length();
    if(len1 != len2) return false;
    n = 0;
    REP(i, len1){
        if(s1[i] != s2[i]){
            n++;
            if(n > 2) return false;
            diff[n] = i;    
        }    
    }    
    if(n == 1) return false;
    if(n == 0){
        memset(appear, 0, sizeof appear);
        REP(i, len1){
            appear[(int)s1[i]]++;    
        }    
        for(char c = 'a'; c <= 'z'; c++){
            if(appear[(int) c] >= 2) return true;    
        }
        return false;
    }
    if(s1[diff[1]] == s2[diff[2]] && s1[diff[2]] == s2[diff[1]]) return true;
    return false;
}


int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    cin >> s1 >> s2;
    if(isSame()) cout << "YES" << endl;
    else cout << "NO" << endl;
    //system("pause");
    return 0;
}
