#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

int a, b, Case(1);


//int Check(char Op[]){
//     if(a == b){
//          if(!strcmp(Op, ">=") || !strcmp(Op, "<=") || !strcmp(Op, "==")) return 1;
//          else return 0;
//          }
//     if(a < b){
//          if(!strcmp(Op, "<=") || !strcmp(Op, "<") || !strcmp(Op, "!=")) return 1;
//          else return 0;
//          }
//     if(a > b){
//          if(!strcmp(Op, ">=") || !strcmp(Op, ">") || !strcmp(Op, "!=")) return 1;
//          else return 0;          
//          }
//     }

int Check(char oper[]) {
    if (strcmp(oper, ">")==0) return (a>b);
    if (strcmp(oper, "<")==0) return (a<b);
    if (strcmp(oper, ">=")==0) return (a>=b);
    if (strcmp(oper, "<=")==0) return (a<=b);
    if (strcmp(oper, "!=")==0) return (a!=b);
    if (strcmp(oper, "==")==0) return (a==b);
}

main () {
     char line[50], Op[10];
    while(true){
             
             gets(line);
             sscanf(line, "%d %s %d",&a,&Op,&b);
             if(Op[0] == 'E') break;
             //if(Check(Op)) printf("Case %d: true\n",Case++);
             //else printf("Case %d: false\n",Case++);
             if(Check(Op)) cout << "Case " << Case++ <<": true";
             else cout << "Case " << Case++ << ": false";
             cout << endl;
             }
    }
