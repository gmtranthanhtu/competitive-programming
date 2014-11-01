//#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int start_col,k,i;
char solution[500][500];


void zero(int s, int j){
     start_col = j * (s + 3);
     for(k = start_col + 1;k <= start_col + s; k++){
           solution[0][k] = '-';
           solution[s * 2 + 2][k] = '-';
           }
     for(i = 1;i <= s; i++){
            solution[i][start_col + s + 1] = '|';
            solution[i][start_col] = '|';
            }
     for(i = s + 2; i <= 2 * s + 1; i++ ){
            solution[i][start_col + s + 1] = '|';
            solution[i][start_col] = '|';
            }
     }

void one(int s, int j){
     start_col = j * (s + 3);
     for(i = 1;i <= s; i++) solution[i][start_col + s + 1] = '|';
     for(i = s + 2; i <= 2 * s + 1; i++ ) solution[i][start_col + s + 1] = '|';
     }
     
void two(int s, int j){
     start_col = j * (s + 3);
     for(k = start_col + 1;k <= start_col + s; k++){
           solution[0][k] = '-';
           solution[s * 2 + 2][k] = '-';
           solution[s + 1][k] = '-';
           }
     for(i = 1;i <= s; i++) solution[i][start_col + s + 1] = '|';
     for(i = s + 2; i <= 2 * s + 1; i++ ) solution[i][start_col] = '|';
     }
     
void three(int s, int j){
     start_col = j * (s + 3);
     for(k = start_col + 1;k <= start_col + s; k++){
           solution[0][k] = '-';
           solution[s * 2 + 2][k] = '-';
           solution[s + 1][k] = '-';
           }
     for(i = 1;i <= s; i++) solution[i][start_col + s + 1] = '|';
     for(i = s + 2; i <= 2 * s + 1; i++ ) solution[i][start_col + s + 1] = '|';
     }
     
void four(int s, int j){
     start_col = j * (s + 3);
     for(k = start_col + 1;k <= start_col + s; k++){
           solution[s + 1][k] = '-';
           }
     for(i = 1;i <= s; i++){
            solution[i][start_col + s + 1] = '|';
            solution[i][start_col] = '|';
            }
     for(i = s + 2; i <= 2 * s + 1; i++ ) solution[i][start_col + s + 1] = '|';
     }

void five(int s, int j){
     start_col = j * (s + 3);
     for(k = start_col + 1;k <= start_col + s; k++){
           solution[0][k] = '-';
           solution[s * 2 + 2][k] = '-';
           solution[s + 1][k] = '-';
           }
     for(i = 1;i <= s; i++) solution[i][start_col] = '|';
     for(i = s + 2; i <= 2 * s + 1; i++ ) solution[i][start_col + s + 1] = '|';
     }
     
void six(int s, int j){
     start_col = j * (s + 3);
     for(k = start_col + 1;k <= start_col + s; k++){
           solution[0][k] = '-';
           solution[s * 2 + 2][k] = '-';
           solution[s + 1][k] = '-';
           }
     for(i = 1;i <= s; i++){
            solution[i][start_col] = '|';
            }
     for(i = s + 2; i <= 2 * s + 1; i++ ){
            solution[i][start_col + s + 1] = '|';
            solution[i][start_col] = '|';
            }
     }
     
void seven(int s, int j){
     start_col = j * (s + 3);
     for(i = 1;i <= s; i++) solution[i][start_col + s + 1] = '|';
     for(i = s + 2; i <= 2 * s + 1; i++ ) solution[i][start_col + s + 1] = '|';
          for(k = start_col + 1;k <= start_col + s; k++){
           solution[0][k] = '-';
           }
     }

void eight(int s, int j){
     start_col = j * (s + 3);
     for(k = start_col + 1;k <= start_col + s; k++){
           solution[0][k] = '-';
           solution[s * 2 + 2][k] = '-';
           solution[s + 1][k] = '-';
           }
     for(i = 1;i <= s; i++){
            solution[i][start_col + s + 1] = '|';
            solution[i][start_col] = '|';
            }
     for(i = s + 2; i <= 2 * s + 1; i++ ){
            solution[i][start_col + s + 1] = '|';
            solution[i][start_col] = '|';
            }
     }
     
void nine(int s, int j){
     start_col = j * (s + 3);
     for(k = start_col + 1;k <= start_col + s; k++){
           solution[0][k] = '-';
           solution[s * 2 + 2][k] = '-';
           solution[s + 1][k] = '-';
           }
     for(i = 1;i <= s; i++){
            solution[i][start_col + s + 1] = '|';
            solution[i][start_col] = '|';
            }
     for(i = s + 2; i <= 2 * s + 1; i++ ) solution[i][start_col + s + 1] = '|';
     } 

int main ()
{   
    int j,s;
    char n[10];
    while(cin >> s >> n && s!=0){
                    int length = strlen(n);
    //Khoi tao mang solution
                    int row = 2 * s + 3;
                    int col = (s + 3) * length - 1;
                    for(i = 0;i < row; i++ )
                        for(j = 0;j < col;j++)
                           solution[i][j] = ' ';
                    for(j = 0;j < length; j++){
                          if (n[j]=='0') zero(s,j);
                          else if (n[j]=='1') one(s,j);
                          else if (n[j]=='2') two(s,j);
                          else if (n[j]=='3') three(s,j);
                          else if (n[j]=='4') four(s,j);
                          else if (n[j]=='5') five(s,j);
                          else if (n[j]=='6') six(s,j);
                          else if (n[j]=='7') seven(s,j);
                          else if (n[j]=='8') eight(s,j);
                          else if (n[j]=='9') nine (s,j);                                 
                          }
    //Xuat output
                   for(i = 0;i < row; i++ )
                        {
                               for(j = 0;j < col;j++) cout << solution[i][j];
                               cout<<endl;
                               }
                  cout<<endl;  
                   } 
    return 0;    
}
