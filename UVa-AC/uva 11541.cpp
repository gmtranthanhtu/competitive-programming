#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
int N,Tempd;
string S;
char Tempc;

int main (){
    cin >> N;
    for(int i = 1; i <= N; i++){
            cin >> S;
            printf("Case %d: ",i);
            Tempd = 0;
            for(int j = 0; j < S.length(); j++){
                    if(S[j] >= '0' && S[j] <= '9'){
                            Tempd = Tempd * 10 + S[j] - '0';
                            }
                    else if(S[j] <= 'Z' && S[j] >= 'A'){
                         for(int k = 1; k <= Tempd; k++){
                                 printf("%c",Tempc);
                                 }
                         Tempc = S[j];
                         Tempd = 0;
                         }
                    if(j == S.length() - 1){
                         for(int k = 1; k <= Tempd; k++){
                                 printf("%c",Tempc);
                                 }
                         printf("\n");
                         }
                    
                    }
            }
    return 0;
    }
