#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define BIG INT_MAX
typedef struct Bin{
        int B, G, C;
        };
Bin One, Two, Three;
int Min,Tmp;
char S[4];

int main () {
    while(scanf("%d %d %d %d %d %d %d %d %d", &One.B, &One.G, &One.C, &Two.B, &Two.G, &Two.C, &Three.B, &Three.G, &Three.C) == 9){
           Min = BIG;
           //GCB
           Tmp = Two.G + Three.G + One.C + Three.C + One.B + Two.B;
           if(Tmp <= Min) { Min = Tmp; strcpy(S, "GCB");}
           //GBC
           Tmp = Two.G + Three.G + One.B + Three.B + One.C + Two.C;
           if(Tmp <= Min) { Min = Tmp; strcpy(S, "GBC"); }  
           //CGB
           Tmp = Two.C + Three.C + One.G + Three.G + One.B + Two.B;
           if(Tmp <= Min) { Min = Tmp;strcpy(S, "CGB"); }   
           //CBG
           Tmp = Two.C + Three.C + One.B + Three.B + One.G + Two.G;
           if(Tmp <= Min) { Min = Tmp;strcpy(S, "CBG"); }
           //BGC
           Tmp = Two.B + Three.B + One.G + Three.G + One.C + Two.C;
           if(Tmp <= Min) { Min = Tmp;strcpy(S, "BGC"); }  
           //BCG
           Tmp = Two.B + Three.B + One.C + Three.C + One.G + Two.G;
           if(Tmp <= Min) { Min = Tmp;strcpy(S, "BCG"); }    
           
           printf("%s %d\n",S,Min);                                               
           }
    return 0;
    }
