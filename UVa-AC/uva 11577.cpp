#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int T, Total[26], Max;
string S;

int main () {
   // cin >> T;
   scanf("%d ",&T);
    //cin >> S;
    for(int i = 1; i <= T; i++){
            //cin >> S;
            getline(cin, S);
            memset(Total, 0, sizeof Total);
            for(int j = 0; j < 26; j++){
                    for(int t = 0; t < S.length(); t++){
                            if(S[t] == (char) j + 65 || S[t] == (char) j + 97){
                                    Total[j] ++;
                                    }
                            }
                    }
            Max = *max_element(Total, Total + 26);
           // cout << Max << endl;
            for(int t = 0; t < 26; t++){
                    if(Total[t] == Max) printf("%c",(char) t + 97);
                    }
            printf("\n");
            }
    return 0;
    }
