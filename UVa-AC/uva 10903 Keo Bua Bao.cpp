#include <stdio.h>
#include <string.h>

int n, k, Total,a,b, Case(1);
char line[1000], Opa[50], Opb[50];
double Win[150];
double Play[150];

void Update(){
     if(strcmp(Opa, Opb) == 0) return;
     Play[a]++; Play[b]++;
     if(strcmp(Opa, "rock") == 0){
                    if(strcmp(Opb, "paper") == 0){
                                   Win[b]++;
                                   }
                    else Win[a]++;
                    }
     else if(strcmp(Opa, "paper") == 0){
                    if(strcmp(Opb, "scissors") == 0){
                                   Win[b]++;
                                   }
                    else Win[a]++;          
          }
     else{
                    if(strcmp(Opb, "rock") == 0){
                                   Win[b]++;
                                   }
                    else Win[a]++;          
          }
     }

int main () {
    while(scanf("%d",&n) && n){
         scanf("%d",&k);  
         scanf(" ");              
         Total = k * (n - 1) * n / 2;
         for(int i = 1; i <= n; i++) {Win[i] = 0; Play[i] = 0;}
         for(int i = 1; i <= Total; i++){
                 gets(line);
                 sscanf(line,"%d %s %d %s",&a,&Opa,&b,&Opb);
                 Update();
                 }      
         if(Case > 1) printf("\n");
         Case++;  
         for(int i = 1; i <= n; i++){
                 if(Play[i] == 0) printf("-\n");
                 else{
                      printf("%.3lf\n", Win[i] / Play[i]);
                      }
                 }        
         }
    
    return 0;
    }
