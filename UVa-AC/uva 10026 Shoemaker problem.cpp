#include <iostream>
#include <algorithm>

using namespace std;
typedef struct Shoe{
        int Time, Fine, Index;
        };
int T, N;
Shoe S[1005];

bool myfun(const Shoe S1, const Shoe S2){
     return (S1.Fine > S2.Fine || (S1.Fine == S2.Fine && S1.Index < S2.Index));
     }

int main () {
    scanf("%d",&T);
    for(int c = 1; c <= T; c++){
            scanf("%d",&N);
            for(int i = 1; i <= N; i++){
                    scanf("%d%d",&S[i].Time, &S[i].Fine);
                    S[i].Index = i;
                    }
            sort(S + 1, S + N + 1,myfun);
            printf("%d",S[1].Index);
            for(int i = 2; i <= N; i++){
                    printf(" %d",S[i].Index);
                    }
            printf("\n");
            }
    
    return 0;
    }
