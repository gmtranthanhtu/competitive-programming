//UVa 499 - Tran Thanh Tu

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

char line[1000];
int maxx, arr[200];

#define INP "uva499.INP"
#define OUT "uva499.OUT"

int main (){
	//freopen(INP, "r", stdin);
	//freopen(OUT, "w", stdout);
	while(gets(line)){
		memset(arr, 0, sizeof arr);
		maxx = -1;
		for(int i = 0; i < strlen(line); i++){
			if((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z')){
				arr[(int) line[i]]++;
				if(arr[(int) line[i]] > maxx) maxx = arr[(int) line[i]];
			}
		}
		for(char i = 'A'; i <= 'Z'; i++){
			if(arr[(int) i] == maxx) printf("%c",i);
		}
		for(char i = 'a'; i <= 'z'; i++){
			if(arr[(int) i] == maxx) printf("%c",i);
		}
		printf(" %d\n",maxx);
	}
	return 0;
}