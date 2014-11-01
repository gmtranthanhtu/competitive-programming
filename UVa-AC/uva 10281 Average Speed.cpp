#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <climits>
#include <math.h>
#include <string.h>
using namespace std;

double Convert(int h, int m, int s){
       return h + m / 60.0 + s / 3600.0;
       }

char line[50];
int h, m, s;
double Spd, Last, Cur, Tmp, Total;

int main () {
   // freopen("10281.INP", "r", stdin);
   // freopen("10281.OUT", "w", stdout);
    Total = 0.0;
    Spd = 0.0;
    Last = 0.0;
    //gets(line);
   // sscanf(line, "%d:%d:%d %lf", &h, &m, &s, &Spd);
   // Last = Convert(h, m, s);
    while(gets(line)){
                     if(strlen(line) == 8) {
                                     printf("%s ",line);
                                     sscanf(line, "%d:%d:%d", &h, &m, &s);
                                     Cur = Convert(h, m, s);
                                     Total += (Spd * (Cur - Last));
                                     printf("%.2lf km\n",Total);
                                     Last = Cur;
                           }
                     else {
                          sscanf(line, "%d:%d:%d %lf", &h, &m, &s, &Tmp);
                          Cur = Convert(h, m, s);
                          Total += (Spd * (Cur - Last));
                          Last = Cur;
                          Spd = Tmp;
                          }
    
}
    
    //getchar();
    return 0;
    }
