/*
  Name: UVa 11849 CD
  Copyright: 
  Author: 3T
  Date: 04/10/10 03:08
  Description: Hash
*/
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;


int N, M, Total, a;

int main (){
    while(scanf("%d%d",&N,&M)){
           if(N == 0 && M == 0) break;
           Total = 0;
           map <int, int> mymap;
           for(int i = 1; i <= N; i++) {
                   scanf("%d",&a);
                   mymap[a] = i;
                   }
           for(int i = 1; i <= M; i++){
                   scanf("%d",&a);
                       if(mymap[a] == 0) continue;
                       else Total++;
                   } 
           printf("%d\n",Total);                   
           }
    return 0;
    }
