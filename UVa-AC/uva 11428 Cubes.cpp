#include <stdio.h>
#include <map>
#include <math.h>
using namespace std;

#define MAX 10000

int N;
int Cube[70], IsCube[MAX + 5], X[MAX + 5], Y[MAX + 5];

void GenCube(){
     for(int i = 1; i <= 60; i++){
        Cube[i] =  i * i * i;
        }
     }

void GenIsCube(){
     for(int i = 1; i <= MAX; i++){
             IsCube[i] = 0;
             Y[i] = 199999999;
             }
     for(int i = 60; i > 1; i--){
             for(int j = i - 1; j >= 1; j--){
                     int Tmp = Cube[i] - Cube[j];
                     if(Tmp > MAX) break;
                     IsCube[Tmp] = 1;
                     if(j < Y[Tmp]){
                     X[Tmp] = i;
                     Y[Tmp] = j;
                          }
                     }
             }
     }

int main (){
    GenCube();
    GenIsCube();
    while(scanf("%d",&N) && N){
         if(IsCube[N]) printf("%d %d\n",X[N],Y[N]);
         else printf("No solution\n");                
         }
    
    return 0;
    }
