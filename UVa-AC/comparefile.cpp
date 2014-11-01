#include <stdio.h>
#include <string.h>

char line1[1000], line2[1000];

//bool Check(){
//     for(int i = 1; i <= 11999; i++){
//             fgets(line1, 1000, f1);
//             fgets(line2, 1000, f2);
//             if(strcmp(line1, line2)) return false;
//             }
//     return true;
//     }

int main () {
    freopen("ANS.OUT", "w", stdout);
    FILE *f2 = fopen("khungdien.OUT", "r");
    FILE *f1 = fopen("myrelation.ans", "r");

    bool Test = true;
    int sai;
    //printf(Check() ? "TRUE" : "FALSE");
     for(int i = 1; i <= 11999; i++){
             fgets(line1, 1000, f1);
             fgets(line2, 1000, f2);
             if(strcmp(line1, line2)) {Test = false; sai = i; break;}
}

//fgets(line2, 1000, f2);            // }    
//fgets(line1, 1000, f1);

//puts(line1);
//puts(line2);
//int len2 = strlen(line2);
//printf("%d\n",len2);
         printf(Test ? "TRUE" : "FALSE");
         printf("\n%d\n",sai);
    return 0;
    }
