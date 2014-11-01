/*
  Name: SRM 550 div1 250 RotatingBot
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 2012
  Description: adhoc
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

int n, t, m, a, b, c;

bool ok(int x, int y, vi move){
    int dx, dy;
    if(x <= move[1] || y <= move[0]) return false;
    int curx = move[1] + 1;
    int cury = y - move[0];
    bool v[55][55];
    memset(v, false, sizeof v);
    v[curx][cury] = true;
    FOR(i, 0, x + 1){
        v[i][0] = v[i][y + 1] = true;    
    }
    FOR(i, 0, y + 1){
        v[0][i] = v[x + 1][i] = true;    
    }
    REP(i, move.size()){
        if(i % 4 == 0){
            dx = 0; dy = 1;            
        } 
        else if(i % 4 == 1){
            dx = -1; dy = 0;    
        } 
        else if(i % 4 == 2){
            dx = 0; dy = -1;    
        }      
        else{
            dx = 1; dy = 0;    
        }
        
        FOR(j, 1, move[i]){
            curx += dx; cury += dy;
            if(v[curx][cury]) return false;
            v[curx][cury] = true;               
        }
        if(i != move.size() - 1 && !v[curx + dx][cury + dy]) return false;
    }   
    return true;  
}

typedef struct RotatingBot{
    int minArea(vector <int> moves){
        int sz = moves.size();
        if(sz == 1) return moves[0] + 1;
        if(sz == 2) return (moves[0] + 1) * (moves[1] + 1);
        int res = INF;
        FOR(i, 2, 51)
            FOR(j, 2, 51){
                if(ok(i, j, moves)){
                    res = min(res, i * j);    
                }    
            }    
        if(res == INF) return -1;
        return res;
    };    
};
