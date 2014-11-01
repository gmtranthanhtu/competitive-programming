/*
  Name: UVa 481 What goes up?   
  Copyright: 
  Author: 3T
  Date: 23/07/11 17:57
  Description: DP, LIS
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>

#define MAXN 100005
#define INF 999999999
using namespace std;

int a;

/* Finds longest strictly increasing subsequence. O(n log k) algorithm. */
void find_lis(vector<int> &a, vector<int> &b)
{
	vector<int> p(a.size());
	int u, v;
 
	if (a.empty()) return;
 
	b.push_back(0);
 
	for (size_t i = 1; i < a.size(); i++) 
        {
                // If next element a[i] is greater than last element of current longest subsequence a[b.back()], just push it at back of "b" and continue
		if (a[b.back()] < a[i]) 
                {
			p[i] = b.back();
			b.push_back(i);
			continue;
		}
 
                // Binary search to find the smallest element referenced by b which is just bigger than a[i]
                // Note : Binary search is performed on b (and not a). Size of b is always <=k and hence contributes O(log k) to complexity.    
		for (u = 0, v = b.size()-1; u < v;) 
                {
			int c = (u + v) / 2;
			if (a[b[c]] < a[i]) u=c+1; else v=c;
		}
 
                // Update b if new value is smaller than previously referenced value 
		if (a[i] < a[b[u]]) 
                {
			if (u > 0) p[i] = b[u-1];
			b[u] = i;
		}	
	}
 
	for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}

int main () {
    //freopen("481.INP", "r", stdin); freopen("481.OUT", "w", stdout);
    vector<int> seq;
    vector<int> lis;
    while(scanf("%d",&a) != EOF) seq.push_back(a);
    find_lis(seq, lis);
    
    printf("%d\n",lis.size());
    printf("-\n");
   	for (size_t i = 0; i < lis.size(); i++)
         printf("%d\n", seq[lis[i]]);

    return 0;
    }
