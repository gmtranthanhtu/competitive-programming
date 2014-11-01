/*
  Name: SRM 548 div1 250  KingdomAndTrees
  Author: 3T //mailto:kasparovandme@gmail.com
  Date: 2012
  Description: ad hoc, binary search
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

int n, t, m, a, b, c, len;

bool ok(int q, vi h){
    vi h2;
    h2.assign(len, 0);
    FOR(i, 0, len - 1){
        if(i == 0){
            h2[i] = max(1, h[i] - q);    
            continue;
        }    
        else if(i == len - 1){
            if(h[i] + q <= h2[i - 1]) return false;
            h2[i] = h[i] + q;        
        }
        else{
            if(h[i] > h2[i - 1]){
                h2[i] = max(h2[i - 1] + 1, h[i] - q);    
            }    
            else if(h[i] <= h2[i - 1]){
                h2[i] = min(h2[i - 1] + 1, h[i] + q);    
            }
        }
    } 
    //test
    FOR(i, 0, len - 1){
        cout << h2[i] << " ";    
    }     
    cout << endl << endl;
    //
    FOR(i, 1, len - 1){
        if(h2[i] <= h2[i - 1]) return false;    
    }   
    return true;
}

typedef struct KingdomAndTrees{
    int minLevel(vector <int> heights){
        int res = 0;
        len = heights.size();
        int lo = 0, hi = INF, mi;
        //vi h2;
        //h2.assign(len, 0);
        while(hi >= lo){
            mi = (hi + lo)/2;
            cout <<hi << " "<< lo<< " " << mi << endl;
            if(ok(mi, heights)){
                res = mi;
                hi = mi - 1;    
            }
            else lo = mi + 1;    
        } 
        return res;   
    }    
};
