#include <stdio.h>
#include <algorithm>
using namespace std;

int M[5];
int T;

int main () {
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            scanf("%d%d%d%d",&M[1],&M[2],&M[3],&M[4]);
            sort(M + 1, M + 5);
            //printf("%d %d %d %d",M[1],M[2],M[3],M[4]);
            if(M[1] == M[2] && M[2] == M[3] && M[3] == M[4]) printf("square\n");
            else if(M[1] == M[2] && M[3] == M[4]) printf("rectangle\n");
            else if(M[1] + M[3] + M[2] > M[4]) printf("quadrangle\n");
            else printf("banana\n");
            }
    return 0;
    }
