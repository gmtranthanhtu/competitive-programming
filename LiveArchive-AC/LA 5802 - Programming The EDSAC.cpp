/*
  Name: LA 5802 - Programming The EDSAC
  Author: 3T - mailto: gm.tranthanhtu@gmail.com
  Date: 14/12/2012
  Algorithm: binary search, pre calculation
  Time Limit: 3.000s
*/

//COMPETITIVE PROGRAMMING TEMPLATE

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <utility>
#include <deque>
#include <list>
#include <sstream>
#include <fstream>
#include <complex>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <utility>
#include <iterator>
#include <numeric>
#include <climits>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it,ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar,val) memset(ar, val, sizeof(ar))
#define fill0(ar) fill((ar), 0)
#define fillinf(ar, n) fr(i,0,(n)) ar[i] = INF
#define debug(x) cout<<#x<<": "<<x<<endl
#define arr1d(a,n) cout << #a << " : "; fr(_,1,n) cout << a[_] << ' '; cout << endl;
#define arr1d0(a,n) cout << #a << " : "; rep(_,n) cout << a[_] << ' '; cout << endl;
#define arr2d(a,n,m) cout << #a << " :" << endl; fr(_,1,n) {fr(__,1,m) cout << a[_][__] << ' '; cout << endl;}
#define arr2d0(a,n,m) cout << #a << " :" << endl; rep(_,n) {rep(__,m) cout << a[_][__] << ' '; cout << endl;}

#define ull unsigned long long
#define ll long long
#define ld double
#define ui unsigned int
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define y0 yyyyyy0
#define y1 yyyyyy1

#define BIT(n) (1<<(n))
#define SQR(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
#define LSOne(S) (S) & (-S)
inline bool EQ(double a, double b) {return fabs(a - b) < 1e-9;}

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;

template<typename T>inline T gcd(T a, T b){if (b == 0)return a;else return gcd(b, a % b);}
template<typename T>inline T lcm(T a, T b){return (a * b) / gcd(a, b);}
template<typename T> string toStr(T x) {stringstream st; st << x; string s; st >> s; return s;}
template<class T>
void splitStr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

inline int two(int n) {return 1 << n;}
inline int isOnBit(int n, int b) {return (n >> b) & 1;}
inline void onBit(int & n, int b) {n = two(b);}
inline void offBit(int & n, int b) {n &= ~two(b);}
inline int lastBit(int n) {return n & (-n);}
inline int cntBit(int n) {int res = 0; while(n && ++res) n -= n &(-n); return res;}

const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
const int dx8[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy8[] = {0, 1, 0, -1, -1, 1, -1, 1};

#define INP "test.inp"
#define OUT "test.out"

#define PI 3.1415926535897932385
#define INF 1000111222
#define EPS 1e-7
#define MAXN 200000
#define MOD 1000000007

//END OF COMPETITVE PROGRAMMING TEMPLATE

typedef struct Four{
  char c1, c2;
  ld val;
  int num;
};

char s[] = "PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV";
ld pow2[25];

vector <Four> F;

int n, tt, sz, ze, ans;
char line[100];
ld x;

string getBinary(int N, int len){
	string res = "";
	while(N){
		res += (N % 2) + '0';
		N /= 2;
	}
	fr(_, 1, len - res.length()) res += '0';
	reverse(all(res));
	return res;
}

void update(int i, int j, int k){
	string code = "";
	code += getBinary(i, 5);
	code += getBinary(j, 11);
	code += k + '0';
	ld ans = 0;
	rep(ii, 17) if(code[ii] == '1') ans += pow2[ii];
	if(code[0] == '1') ans = 2 - ans, ans *= -1;
	Four tmp; tmp.c1 = s[i]; tmp.c2 = k ? 'D' : 'F'; tmp.num = j; tmp.val = ans;
	F.pb(tmp);
}

bool cmp(const Four& F1, const Four& F2){
	return F1.val < F2.val;
}

void pre(){
	pow2[0] = 1;
	fr(i, 1, 20) pow2[i] = pow2[i-1] * 0.5;

	rep(i, 32) rep(j, 2048) rep(k, 2){
		update(i, j, k);
	}
	sort(all(F), cmp);
	sz = F.size();
	rep(i, sz) if(fabs(F[i].val - 0) <= 1e-20){
		ze = i;
		break;
	}
}

int cal1(){
	int l = 0, h = ze, tmp, mi;
	while(l <= h){
		mi = (l + h) / 2;
		if(fabs(F[mi].val - x) <= 1e-20) return mi;
		else if(F[mi].val < x) l = mi + 1;
		else h = mi - 1;
	}
	return l;
}

int cal2(){
	int l = ze, h = sz - 1, tmp, mi;
	while(l <= h){
		mi = (l + h) / 2;
		if(fabs(F[mi].val - x) <= 1e-20) return mi;
		else if(F[mi].val < x) l = mi + 1;
		else h = mi - 1;
	}
	return h;
}

bool ok(){
	char tmp[20];
	char neone[]="-1.0000000000000000";
	if(line[0] == '-' && strlen(line) < 19){
		fr(i, strlen(line), 18) line[i] = '0';
		line[19] = '\0';
	}
	else if(line[0] != '-' && strlen(line) < 18){
		fr(i, strlen(line), 17) line[i] = '0';
		line[18] = '\0';
	}
	if(line[0] >= '1' && line[0] <= '9') return false;
	if(line[0] == '0') return true;
	if(strcmp(line, neone) == 0) return true;
	if(line[1] == '0') return true;
	return false;
}


int main () {
    #ifndef ONLINE_JUDGE
    freopen(INP, "r", stdin); freopen(OUT, "w", stdout);
    #endif

    pre();
    scanf(" %d \n", &n);
    fr(i, 1, n){
    	gets(line);
		sscanf(line, "%d %s", &tt, &line);
		sscanf(line, "%lf", &x);
		if(!ok()){
			printf("%d INVALID VALUE\n", tt);
			continue;
		}
		else if(fabs(x - 0) <= 1e-20) ans = ze;
		else if(x < 0) ans = cal1();
		else ans = cal2();
		printf("%d %c %d %c\n", tt, F[ans].c1, F[ans].num, F[ans].c2);
    }



    return 0;
}
