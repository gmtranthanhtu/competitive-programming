
/*
  Name: UVa 11340 
  Copyright: 
  Author: 
  Date: 01/11/10 16:15
  Description: 
*/
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

int T, K, c, v, M, R;
char line[50], News[10005];

int main () {
    //freopen("inp.inp", "r", stdin);
   // freopen("out.out", "w", stdout);
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
            map <char, int> mymap;
            scanf("%d",&K);
            scanf(" ");
            for(int j = 1; j <= K; j++){
                    gets(line);
                    sscanf(line, "%c %d",&c,&v);
                    mymap[c] = v;
                    }
            R = 0;
            scanf("%d",&M);
            scanf(" ");
            
            for(int j = 1; j <= M; j++){
                    gets(News);
                    for(int k = 0; k < strlen(News); k++){
                            R = R + mymap[News[k]];
                            }
                    }
            printf("%d.%d%d$\n",R / 100, (R % 100) / 10, (R % 100) % 10);
            }
    
    return 0;
    }
