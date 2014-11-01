/*
  Name: UVa 750 8-queens problem
  Author: 3T
  Date: 06-04-12 21:47
  Description:
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

#define INP "750.INP"
#define OUT "750.OUT"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

int a, b, c, d, e, f, g, h, n, inrow[10];

void printHeader(){
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    //cout << endl;
    }
    
int Abs(int a){
    if(a < 0) return a * -1;
    return a;
    }    

bool canPut(int col, int row){
    FOR(i, 1, col - 1){
        if(inrow[i] == row || (Abs(inrow[i] - row) == Abs(i - col))) return false;
        }
    return true;
    }
    
void printSolution(){
    printf("%2d      ",++c);
    FOR(i, 1, 8){
        if(i > 1) printf(" ");
        printf("%d", inrow[i]);
        }
    cout << endl;
    }

void backtrack(int col){
    FOR(i, 1, 8){
        if(canPut(col, i)){
            inrow[col] = i;
            if(col == 8 && inrow[b] == a) printSolution();
            else backtrack(col + 1);
            }
        }
    }

int main () {
    //freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    scanf("%d", &n);
           
    while(n--){
        scanf("%d%d",&a,&b);
        printHeader(); 
        fill(inrow, 0);
        c = 0;
        backtrack(1);
        if(n)cout << endl;
        }
    return 0;
    }
