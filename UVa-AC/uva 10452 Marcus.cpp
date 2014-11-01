/*
  Name: UVa 10452 Marcus
  Copyright: 
  Author: 3T
  Date: 23/08/10 19:44
  Description: backtracking
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INP "10452.INP"

int N,m,n,sx,sy,s,ok;
char c,C[10][10], I[]={"IEHOVA"},P[10],r,line[100];

void Try(int sx, int sy, int r){
     if(r == 6){
          if(C[sx - 1][sy] == '#'){
                  P[r] = 'f';
                  ok = 1;
                  return;
                  } 
          if(C[sx][sy - 1] == '#'){
                  P[r] = 'l';
                  ok = 1;
                  return;
                  }
          if(C[sx][sy + 1] == '#'){
                  P[r] = 'r';
                  ok = 1;
                  return;    
                  }
          }
     if(ok) return;
     if(C[sx - 1][sy] == I[r]){
             P[r] = 'f';
             Try(sx - 1, sy, r + 1);
             if(ok) return;
             else
             P[r] = 'a';
             }
     if(ok) return;
     if(C[sx][sy - 1] == I[r]){
          P[r] = 'l';
          Try(sx, sy - 1, r + 1);
             if(ok) return;
             else
          P[r] = 'a';
          }
     if(ok) return;
     if(C[sx][sy + 1] == I[r]){
          P[r] = 'r';
          Try(sx, sy + 1, r + 1);
             if(ok) return;
             else
          P[r] = 'a';
          }
//     if(ok) return;
     }


int main () {
   // FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    fscanf(f,"%d",&N);
    for(int i = 1; i <= N; i++){
            fscanf(f,"%d%d",&m,&n);
            fgets(line, 100, f);
            memset(C, '\0', sizeof C);
            for(int j = 1; j <= m; j++){
                    fgets(line, 100, f);
                    for(int k = 1; k <= n; k++){
                            C[j][k] = line[k - 1];
                            if(line[k - 1] == '@'){
                                      sx = j;
                                      sy = k;
                                      }
                            }
                    }
//            for(int j = 1; j <= m; j++){
//                    for(int k = 1; k <= n; k++){ printf("%c",C[j][k]);}
//                    printf("\n");
 //                   }
//                    printf("sx: %d sy: %d \n",sx,sy);
            memset(P,'a',sizeof P);
            ok = 0;
            r = 0;
            Try(sx, sy, r);
//            printf("Chuoi: %s\n",P);
            for(int t = 0; t <= 5; t++){
                    if(P[t] == 'f') printf("forth ");
                    else if(P[t] == 'r') printf("right ");
                    else if(P[t] == 'l') printf("left ");
                    }
                    if(P[6] == 'f') printf("forth\n");
                    else if(P[6] == 'r') printf("right\n");
                    else if(P[6] == 'l') printf("left\n");            
            }
   // getchar();
    return 0;
    }
