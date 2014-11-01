/*
  Name: UVa 10420 List of Conquests
  Copyright: 
  Author: 3T
  Date: 06/12/10 01:43
  Description: ad hoc, sorting
*/
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef struct Array{
        string Name;
        int Num;
        };
Array A[2010];
int N, t;
string line, S, Tmp;
map <string, int> Country;

bool myfun(Array a, Array b){
     return a.Name < b.Name;
     }

int main () {
    //freopen("10420.INP", "r", stdin);
    //freopen("10420.OUT", "w", stdout);
    scanf("%d",&N);
    scanf(" ");
    t = 0;
    for(int i = 1; i <= N; i++){
            getline(cin, line);
            size_t F;
            F = line.find(" ");
            S = line.substr(0, F);
            //cout << S << endl;
            int Tmp2 = Country[S];
            if(Tmp2){
                     A[Tmp2].Num++;
                     }
            else{
                 t++;
                 A[t].Name = S;
                 A[t].Num = 1;
                 Country[S] = t;
                 }
            }
    sort(A + 1, A + t + 1, myfun);
    for(int i = 1; i <= t; i++){
            cout << A[i].Name << " " << A[i].Num << endl;
            }
    return 0;
    }
