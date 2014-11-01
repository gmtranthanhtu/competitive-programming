/*
  Name: UVa 10158 War
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 23/5/2012
  Description: disjoint set
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
#define MAXN 20000
#define MOD 1000000007

#define INP "test.inp"
#define OUT "test.out"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, t(1), a, b, c;

vi pset, ene;

void iniSet(int N){
    pset.assign(N + 1, 0);
    ene.assign(N + 1, 0);
    REP(i, N) {pset[i] = i; ene[i] = -1;}    
}
int findSet(int i){
    return ((pset[i] == i) ? i : (findSet(pset[i])));    
}
bool isSameSet(int i, int j){
    return (findSet(i) == findSet(j));    
}
void unionSet(int i, int j){ pset[findSet(i)] = findSet(j);}

int isFriend(int x, int y){
    if(isSameSet(x, y)) return 1;
    return 0;    
}

int isEnemy(int x, int y){
    if(ene[findSet(x)] == findSet(y)) return 1;
    return 0;    
}

void setFriend(int x, int y){
    if(isSameSet(x, y)) return;
    int fs1 = findSet(x), fs2 = findSet(y);
    pset[fs1] = fs2;
    if(ene[fs1] != -1 && ene[fs2] != -1) setFriend(ene[fs1], ene[fs2]);
    else if(ene[fs1] != -1 && ene[fs2] == -1){
        ene[fs2] = ene[fs1];
        ene[ene[fs1]] = fs2;    
    }    
}

void setEnemy(int x, int y){
    int fs1 = findSet(x), fs2 = findSet(y);    
    if(ene[fs1] == -1 && ene[fs2] == -1){ene[fs1] = fs2; ene[fs2] = fs1;}
    else if(ene[fs1] == -1 && ene[fs2] != -1) setFriend(ene[fs2], fs1);
    else if(ene[fs1] != -1 && ene[fs2] == -1) setFriend(ene[fs1], fs2);    
    else {setFriend(ene[fs2], fs1); setFriend(ene[fs1], fs2);}     
}

int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif
    
    scanf("%d", &n);
    iniSet(n);
    while(scanf("%d %d %d", &a, &b, &c)){
        if (a + b + c == 0) break;
        if(a == 1){
            if(isEnemy(b, c)) printf("-1\n");
            else setFriend(b, c);    
        }
        else if(a == 2){
            if(isFriend(b, c)) printf("-1\n");
            else setEnemy(b, c);    
        }
        else if(a == 3){
            printf("%d\n", isFriend(b, c));   
        }
        else if(a == 4) printf("%d\n", isEnemy(b, c));
    }

    return 0;
}
