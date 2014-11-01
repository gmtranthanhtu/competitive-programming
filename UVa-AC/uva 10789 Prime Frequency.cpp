#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool Prime[2010];
int N, F[130];
char S[2010];

void GenPrime(){
     Prime[1] = false;
     for(int i = 2; i <= 2010; i++){
             Prime[i] = true;
             }
     for(int i = 2; i <= 2010; i++){
             if(!Prime[i]) continue;
             for(int j = 2; j * i <= 2010; j++) Prime[i * j] = false;
             }
     }

int main () {
    //printf("%d %d %d %d %d %d\n",'0', '9', 'a', 'z', 'A', 'Z');
    //48 57 65 90 97 122
    GenPrime();
    scanf("%d",&N);
    scanf(" ");
    for(int i = 1; i <= N; i++){
            gets(S);
            memset(F, 0, sizeof(F));
            for(int j = 0; j < strlen(S); j++){
                    int Tmp = (int) S[j];
                    F[Tmp] ++;
                    }
            printf("Case %d: ",i);
            int Emp = 0;
            for(int j = 48; j <= 57; j++){
                    if(Prime[F[j]]) {printf("%c",j);
                    Emp++;}
                    }
            for(int j = 65; j <= 90; j++){
                    if(Prime[F[j]]) {printf("%c",j);
                    Emp++;}
                    }
            for(int j = 97; j <= 122; j++){
                    if(Prime[F[j]]) {printf("%c",j);
                    Emp++;}
                    }     
            //printf("%d\n",Emp);     
            if(Emp == 0) printf("empty");
            printf("\n");                              
            }
    //system("pause");
    return 0;
    }
