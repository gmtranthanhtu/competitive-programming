#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

string a, b;
int T;

bool Vowel(char a){
     if(a == 'a' || a == 'o' || a == 'e' || a == 'i' || a == 'u') return true;
     return false;
     }

bool Check(){
     int lena = a.length();
     int lenb = b.length();
     if(lena != lenb) return false;
     for(int i = 0; i < lena; i++){
             if(Vowel(a[i]) && !Vowel(b[i])) return false;
             if(!Vowel(a[i]) && a[i] != b[i]) return false;
             }
     return true;
     }

int main (){
    cin >> T;
    for(int i = 1; i <= T; i++){
            cin >> a >> b;
            printf(Check() ? "Yes\n" : "No\n");
            }
    return 0;
    }
