/*
  Name: UVa 11405 Can you Win?
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 12/9/2012
  Description: bfs, bitmask
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

template<typename T>inline T gcd(T a, T b){if (b == 0)return a;else return gcd(b, a % b);}
template<typename T>inline T lcm(T a, T b){return (a * b) / gcd(a, b);}


int X[]={-2,-2,-1,-1,1,1,2,2};
int Y[]={1,-1,2,-2,2,-2,1,-1};

int n, t, m, a, b, c, p, kx, ky, bitmask;
typedef struct Point{
    int x, y;    
};

Point P[10];

char board[10][10];
int state[10][10][500];
bool ok = false;

typedef struct St{
    int xk; int yk; int bm; int step;    
};


int Pow2(int i){
    if(!i) return 1;
    int res = 1;
    FOR(j,1,i) res*=2;
    return res;    
}

int findP(int xx, int yy){
    REP(i,p) if(P[i].x == xx && P[i].y == yy) return i;    
}

void bfs(){
    queue <St> q;
    St s, ss; s.xk = kx; s.yk = ky; s.bm = bitmask; s.step = 0;
    int xx, yy;
    q.push(s);
    while(!q.empty() && !ok){
        s = q.front();
        q.pop();
        REP(i,8){
            xx = s.xk + X[i];
            yy = s.yk + Y[i];
            if(xx < 0 || xx > 7 || yy < 0 || yy > 7) continue;
            if(board[xx][yy] == 'K' || board[xx][yy] == 'p') continue;
            if(board[xx][yy] == '.' || board[xx][yy] == 'k'){
                if(state[xx][yy][s.bm]) continue;
                ss.xk = xx; ss.yk = yy; ss.bm = s.bm; ss.step = s.step+1;
                state[xx][yy][s.bm] = 1;
                if(ss.step < n) q.push(ss); 
                continue;      
            }        
            if(board[xx][yy] == 'P'){
                int ind = findP(xx, yy);
                if (!(s.bm & (1 << ind))){
                if(state[xx][yy][s.bm]) continue;
                ss.xk = xx; ss.yk = yy; ss.bm = s.bm; ss.step = s.step+1;
                state[xx][yy][s.bm] = 1;
                if(ss.step < n) q.push(ss);                         
                }   
                else{
                    int nbm = s.bm & ~(1<<ind);
                    if(nbm == 0 && s.step + 1 <= n){
                        ok = true;
                        return;    
                    }    
                    state[xx][yy][nbm] = 1;
                    ss.xk = xx; ss.yk = yy; ss.bm = nbm; ss.step = s.step+1;
                    if(ss.step < n) q.push(ss);
                } 
            }
        }    
    }        
}


int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    scanf("%d", &t);
    while(t--){
        ok = false;
        //gets(line);
        scanf(" %d ", &n);
        REP(i,8) gets(board[i]);
        p = 0;
        REP(i,8)
            REP(j,8){
                if(board[i][j] == 'k'){
                    kx = i; ky = j;    
                }
                if(board[i][j] == 'P'){
                    p++;
                    P[p-1].x = i;
                    P[p-1].y = j;   
                }    
            }
        if(!p) {printf("Yes\n"); continue;}
        
        //bitmask
         bitmask = Pow2(p) - 1;   
         REP(i,8)
            REP(j,8)
                REP(k,bitmask + 5) state[i][j][k] = 0;
        state[kx][ky][bitmask] = 1;
        bfs();        
        if(ok) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
