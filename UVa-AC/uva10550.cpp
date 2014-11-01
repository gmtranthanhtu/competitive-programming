//UVa 10550 - Tran Thanh Tu

#include <stdio.h>

int cur, a, b, c, total;

int clockwise(int cur, int tar){
	if(tar >= cur){
		return 9 * (tar - cur);
	}
	else return 9 * (40 - (cur - tar));
}


int main () {
	while(scanf("%d%d%d%d",&cur, &a, &b, &c)){
		if(cur == 0 && a == 0 && b == 0 && c == 0) break;
		total = 0;
		total += 720;
		total += clockwise(a, cur);
		cur = a;
		total += 360;
		total += clockwise(cur, b);
		cur = b;
		total += clockwise(c, cur);
		printf("%d\n", total);
		
	}
	return 0;
}