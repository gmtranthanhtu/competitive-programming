#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char m[105],n[105];
int M[10][10];

void Init(){
     M[2][1] = 2; M[2][2] = 4; M[2][3] = 8; M[2][0] = 6;
     M[3][1] = 3; M[3][2] = 9; M[3][3] = 7; M[3][0] = 1;
     M[7][1] = 7; M[7][2] = 9; M[7][3] = 3; M[7][0] = 1;
     M[8][1] = 8; M[8][2] = 4; M[8][3] = 2; M[8][0] = 6;
     M[4][1] = 4; M[4][0] = 6;
     M[9][1] = 9; M[9][0] = 1;
     }

int findLastDigit(){
     int ln = strlen(n);
     int lm = strlen(m);
     int lastm = m[lm - 1] - '0';
     int lastn = n[ln - 1] - '0';
     if(lastm == 0) return 0;
     if(lastm == 1) return 1;
     if(ln == 1 && lastn == 0) return 1;
     if(lastm == 5 || lastm == 6) return lastm;
     if(lastm == 4 || lastm == 9) return M[lastm][lastn % 2];
     if(ln >= 2) lastn += (n[ln - 2] - '0') * 10;
     return M[lastm][lastn % 4];
     }

int main () {
    Init();
    FILE *f = stdin;
    while(fscanf(f,"%s %s",&m,&n) && (strcmp(m,"0") || strcmp(n,"0"))){
          printf("%d\n",findLastDigit());             
          }
    return 0;
    }
