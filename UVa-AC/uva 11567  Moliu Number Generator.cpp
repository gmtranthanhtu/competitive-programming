/*
  Name: UVa 11567 Moliu Number Generator
  Author: 3T
  Date: 06-04-12 21:47
  Description: 
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

#define INP "11567.INP"
#define OUT "11567.OUT"

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

long a;
int b;


int main () {
   // freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    while(scanf("%ld", &a) != EOF){
        b = 0;
        while(a){
            //if(a % 2) a--;
            if(a == 1){b++; break;}
            if(a == 3){b += 3; break;}
            //if(a % 2 == 0) a /= 2;
            if(!(a & 1)) a >>= 1;
            else{
                //else a--;
                //if(((a - 1)/2) % 2 == 0) a--;
                if(!((a - 1) & 2)) a--;
                //else if (((a + 1)/2) % 2 == 0) a++;
                else if(!((a + 1) & 2)) a++;
                else a--;
                }
            b++;
        }
        printf("%d\n", b);
    }
    return 0;
}
