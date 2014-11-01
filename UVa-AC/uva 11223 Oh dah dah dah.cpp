/*
  Name: UVa 11223 Oh Dah dah dah
  Copyright: 
  Author: 3T
  Date: 17/11/10 01:16
  Description: string
*/
#include <stdio.h>
#include <string>
#include <map>
#include <iostream>
using namespace std;

int T;
string S, Tmp;
map <string, char> Morse;

void Init(){
     Morse[".-"] = 'A';      Morse[".---"] = 'J';   Morse["..."] = 'S'; 
     Morse["-..."] = 'B';    Morse["-.-"] = 'K';    Morse["-"] = 'T';
     Morse["-.-."] = 'C';    Morse[".-.."] = 'L';   Morse["..-"] = 'U';
     Morse["-.."] = 'D';     Morse["--"] = 'M';     Morse["...-"] = 'V';
     Morse["."] = 'E';       Morse["-."] = 'N';     Morse[".--"] = 'W';
     Morse["..-."] = 'F';    Morse["---"] = 'O';    Morse["-..-"] = 'X';
     Morse["--."] = 'G';     Morse[".--."] = 'P';   Morse["-.--"] = 'Y';
     Morse["...."] = 'H';    Morse["--.-"] = 'Q';   Morse["--.."] = 'Z';
     Morse[".."] = 'I';      Morse[".-."] = 'R';    Morse["-----"] = '0';
     
     Morse[".----"] = '1';   Morse[".-.-.-"] = '.'; Morse["---..."] = ':';
     Morse["..---"] = '2';   Morse["--..--"] = ','; Morse["-.-.-."] = ';';
     Morse["...--"] = '3';   Morse["..--.."] = '?'; Morse["-...-"] = '=';
     Morse["....-"] = '4';   Morse[".----."] = '\'';  Morse[".-.-."] = '+';
     Morse["....."] = '5';   Morse["-.-.--"] = '!'; Morse["-....-"] = '-';
     Morse["-...."] = '6';   Morse["-..-."] = '/';  Morse["..--.-"] = '_';
     Morse["--..."] = '7';   Morse["-.--."] = '(';  Morse[".-..-."] = '\"';
     Morse["---.."] = '8';   Morse["-.--.-"] = ')'; Morse[".--.-."] = '@';
     Morse["----."] = '9';   Morse[".-..."] = '&';
     }

int main () {
    //freopen("11223.INP", "r", stdin);
   // freopen("11223.OUT", "w", stdout);
    Init();
    scanf("%d",&T);
    scanf(" ");
    for(int i = 1; i <= T; i++){
            getline(cin, S);
            if(i > 1) printf("\n");
            printf("Message #%d\n",i);
            Tmp = "";
            for(int j = 0; j < S.length(); j++){
                if(S[j] != ' ') Tmp.push_back(S[j]);
                else{
                    if(Tmp.compare("") != 0) {printf("%c",Morse[Tmp]); Tmp = "";}
                    else printf(" ");
                    }
                }
            printf("\n");
            }
    return 0;
    }
