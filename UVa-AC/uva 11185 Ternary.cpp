#include <stdio.h>
#include <stack>
using namespace std;
int  a, b;
stack <int> S;

void Convert(){
     while(!S.empty()) S.pop();
     if(a == 0){
          S.push(0);
          return;
          }
//     S.clear();
     while(a >= 3){
             S.push(a % 3);
             a = a / 3;
             }
     S.push(a);
     }
     
void Print(){
     while(!S.empty()){
           printf("%d",S.top());
           S.pop();            
           }
     }

int main (){
    while(scanf("%d",&a) && a >= 0){
           Convert();
           Print();
           printf("\n");              
           }
    return 0;
    }
