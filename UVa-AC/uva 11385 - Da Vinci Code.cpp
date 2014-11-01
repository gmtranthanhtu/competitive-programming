// 11385 - Da Vinci Code
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#define LL unsigned long long
using namespace std;

LL F[100];
int T, N, A[200];
map <LL, int> M;
string S;
char R[300];
char line[10];

void Init(){
    F[1] = 1;
    F[2] = 1;
    for(int i = 3; i <= 60; i++){
        F[i] = F[i - 1] + F[i - 2];
        }
    for(int i = 2; i <= 60; i++){
        M[F[i]] = i - 1;
        }
    }

int main () {
   // freopen("A.INP", "r", stdin);
   // freopen("A.OUT", "w", stdout);
    Init();
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> N;
        for(int j = 1; j <= N; j++){
            cin >> A[j];
            }
        gets(line);
        getline(cin, S);
        int Tmp = 0;
        memset(R, ' ', sizeof R);
        for(int j = 0; j < S.length(); j++){
                if(Tmp == N) break;
            if(S[j] <= 'Z' && S[j] >= 'A'){
                Tmp++;
                if(Tmp > N) break;
                R[M[A[Tmp]]] = S[j];
                } 
            }
        int Tmp2 = 0;
        for(int j = 1; j <= 110; j++){
            if(Tmp2 == Tmp) break;
            if(R[j] != ' '){
                printf("%c",R[j]);
                Tmp2++;
                }
            else {printf(" ");}
            
            }
        printf("\n");
        }
    return 0;
    }
