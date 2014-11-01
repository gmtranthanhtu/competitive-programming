/*
  Name: UVa 10128 Queue
  Copyright: 
  Author: 3T
  Date: 02/05/10 23:34
  Description: DP, Memoization table
*/

/*
  NHAT KY: Tac gia nghi toi cach sinh 1 bang ket qua truoc, khi nhap input chi can tra vao bang roi in ra output.
     Ban dau, tac gia ve vai bang ket qua voi n nho truoc, nhung nhin mai khong thay gi. Cuoi cung, tu nhien mat tac gia sang len, tac gia da
  tim duoc quy luat de sinh cac hang tu 2 den n khi co hang 1. Wow! Di dung huong roi! Nhung lam the nao de sinh hang 1 day?? Khong le phai 
  viet thang vao code. Tac gia suy nghi mai khong duoc danh skip. Mot thoi gian sau tac gia quay lai. Cung tiep tuc mo mam voi nhung con so.
  Sau do, tac gia quyet dinh nhin van de 1 lan nua duoi goc do toan hoc. Va tac gia da thanh cong. Hihi, tac gia vui qua nen moi viet may
  dong nay.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INP "10128.txt"
#define Max 14

int T,N,P,R,i,l,m,n,k,j;
int Hehe[Max][Max][Max];

void Initiate_Table(){
     memset(Hehe,0,sizeof(Hehe));
     Hehe[1][1][1] = 1;
     for(l = 2; l <= Max - 1; l++){
           m = l;
           for(n = 1; n <= l; n++){
                 for(k = 1; k <= m; k++){
                       if(n == 1){
                            j = k - 1;
                            int Sum = 0;
                            for(int p = 1; p < l; p++) Sum += Hehe[l - 1][p][j];
                            Hehe[l][n][k] = Hehe[l][k][n] = Sum;
                            }
                       else{
                            if(Hehe[l][n][k]) continue;
                            Hehe[l][n][k] = Hehe[l][k][n] = (Hehe[l][n - 1][k + 1] * k) / (n - 1);
                            }
                       }
                 m--;
                 }
           }
     
     }

int main () {
//    FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    fscanf(f,"%d",&T);
    Initiate_Table();
    for(i = 1; i <= T; i++){
          fscanf(f,"%d%d%d",&N,&P,&R);
          if(P < 1 || R < 1 || P > N || R > N){
               printf("%d\n",0);
               }
          else printf("%d\n",Hehe[N][P][R]);
          }

    return 0; 
    }
