#include <string>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

bool CP[10005];
int T;
string S;
char M[110][110];

bool chinhphuong(int i){
     double Tmp = sqrt(i);
     int Tmp2 = (int) Tmp;
     if(Tmp2 * Tmp2 == i) return true;
     return false;
     }

void Init(){
     for(int i = 1; i <= 10000; i++){
             CP[i] = chinhphuong(i) ? true : false;
             }
     }


int main () {
    Init();
    cin >> T;
    scanf( " ");
    for(int i = 1; i <= T; i++){
            getline(cin, S);
            if(!CP[S.length()]){
                                printf("INVALID\n");
                                continue;
                                }
            int n = sqrt(S.length());
            int a = 0;
            for(int j = 1; j <= n; j++){
                    for(int k = 1; k <= n; k++){
                            M[j][k] = S[k - 1 + a * n];
                            }
                    a ++;
                    }
            for(int j = 1; j <= n; j++){
                    for(int k = 1; k <= n; k++){
                            printf("%c",M[k][j]);
                            }
                    } 
            printf("\n");           
            }
    return 0;
    }
