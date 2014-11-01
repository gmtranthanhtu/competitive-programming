#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <iostream>

using namespace std;

string a, b,line;
map <string, string> Dic;

int main (){
    while(getline(cin, line) && line.length()){
        size_t Pos = line.find(" ");
        a = line.substr(0, Pos);
        b = line.substr(Pos + 1, line.length());
        Dic[b] = a;               
        }
    while(cin >> line){
              if(Dic[line].compare("") != 0) cout << Dic[line] << endl;
              else printf("eh\n");
              }
    return 0;
    }
