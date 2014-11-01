#include <stdio.h>
#include <string.h>

int N;
bool High[20], Low[20];
char S[100];

void Print(){
    bool Test = true;
    for(int i = 1; i <= 10; i++){
        if((High[i] && i <= N) || (Low[i] && i >= N)){
            Test = false;
            break;
            }
        }
    if(Test) printf("Stan may be honest\n");
    else printf("Stan is dishonest\n");
    }

void Init(){
    for(int i = 1; i <= 10; i++){
        High[i] = false;
        Low[i] = false;
        }    
    }

int main () {
    Init();
    while(scanf("%d",&N) && N){
        scanf(" ");
        gets(S);
        if(strcmp(S, "too high") == 0){
            High[N] = true;
            }
        else if(strcmp(S, "too low") == 0) Low[N] = true;
        else if(strcmp(S, "right on") == 0){
            Print();
            Init();
            }
        }
    
    return 0;
    }
