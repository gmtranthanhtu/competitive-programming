/*
  Name: SRM 549 div1 250 PointyWizardHats
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 2012
  Description: matching
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

template<typename T>inline T gcd(T a, T b){if (b == 0)return a;else return gcd(b, a % b);}
template<typename T>inline T lcm(T a, T b){return (a * b) / gcd(a, b);}

int n, t, m, b, c;
int matchX[100], matchY[100], Trace[100];
bool a[100][100];

vi toph, topr, both, botr;

bool ok(int th, int tr, int bh, int br){
    if(tr >= br) return false;
    double tmp = (double) bh * (double) tr / (double) br;
    if(tmp >= th) return false;
    return true;    
}

int findArgumentingPath(){
    queue <int> q;
    memset(Trace, -1, sizeof Trace);
    REP(i, m){
        if(matchX[i] == -1){
            q.push(i);    
        }    
    } 
    while(!q.empty()){
        int i = q.front();
        q.pop();
        REP(j, n){
            if(Trace[j] == -1 && a[i][j] && matchX[i] != j){
                Trace[j] = i;
                if(matchY[j] == -1) return j;
                q.push(matchY[j]);    
            }        
        }    
    } 
    return -1;  
}

void enlarge(int f){
    int x, next;
    do{
        x = Trace[f];
        next = matchX[x];
        matchX[x] = f;
        matchY[f] = x;
        f = next;    
    }while(f != -1);        
}

void solve(){
    int finish = 0;
    do{
        finish = findArgumentingPath();
        if(finish != -1) enlarge(finish);    
    }while(finish != -1);    
}

typedef struct PointyWizardHats{
    int getNumHats(vector <int> topHeight, vector <int> topRadius, vector <int> bottomHeight, vector <int> bottomRadius){
        toph = topHeight; topr = topRadius; both = bottomHeight; botr = bottomRadius;
        m = topHeight.size();
        n = bottomHeight.size();      
        memset(a, false, sizeof a);
        REP(i, m)
            REP(j, n){
                if(ok(topHeight[i], topRadius[i], bottomHeight[j], bottomRadius[j])) {a[i][j] = true;  
                cout << i << " " << j << endl;  }
            }  
        memset(matchX, -1, sizeof matchX);
        memset(matchY, -1, sizeof matchY);
        
        solve();
        int res = 0;
        REP(i, m){
            if(matchX[i] != -1) res++;    
        }
        return res;
    }    
};
