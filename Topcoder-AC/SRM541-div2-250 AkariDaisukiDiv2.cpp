/*
  Name: DRM 541 div2 250 AkariDaisukiDiv2
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 24/4/2012
  Description: ad hoc, string
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

#define INP ""
#define OUT ""

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, t, a, b, c;
vector<string> V[1000000];

bool check(string AA, string CC, string EE, string DD){
    if(n == 0) return true;
    FOR(i, 1, n){
        if(V[i][0] != AA || V[i][2] != EE) return true;
        if(V[i][1] != CC || V[i][3] != DD) return true;            
    }  
    return false;  
}

int countT(string S){
    n = 0;
    int res = 0;
    if(S.size() < 5) return 0;
    int len = S.size();
    string A, B, C, D, E;
    
    for(int i = 1; i <= len - 4; i++){
        for(int j = 1; j <= len - i - 3; j++){
            for(int k = 1; k <= len - i - j - 2; k++){
                for(int l = 1; l <= len - i - j - k - 1; l++){
                    
                    A = S.substr(0, i);
                    B = S.substr(i, j);
                    C = S.substr(i + j, k);
                    D = S.substr(i + j + k, l);
                    E = S.substr(i + j + k + l, len - (i + j + k + l));
                    if(B != D) continue;
                    if(!check(A, C, E, D)) continue;
                    n++;
                    V[n].pb(A); V[n].pb(C); V[n].pb(E); V[n].pb(D);
                    res++;
                }
                 
            }    
        }    
    }
    
    return res;        
}

typedef struct AkariDaisukiDiv2{
    int countTuples(string S){
        int res = 0;
        res = countT(S);
        
        return res;
        }
    };


