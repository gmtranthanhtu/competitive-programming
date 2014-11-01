/* 
 * Problem: UVa 10541 Stripe
 * Author: 3T - mailto:gm.tranthanhtu@gmail.com
 * Time Limit: 2.000s
 * Algorithm: BigInteger, dp
 */

import java.util.Scanner;
import java.math.BigInteger;


public class Main {
	static int T, x, ak[];
	
	static BigInteger solve(int[] b, int N, int K) {
		BigInteger[][] f = new BigInteger[205][205];
		BigInteger res = BigInteger.ZERO;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < K; j++)
				f[i][j] = BigInteger.ZERO;
		for(int i = 0; i < N; i++) {
			if(i - b[0] + 1 >= 0 && i - b[0] + 1 < N) f[i][0] = BigInteger.ONE;
			else f[i][0] = BigInteger.ZERO;
		}
		for(int i = 0; i < N; i++) {
			for(int j = 1; j < K; j++) {
				int tmp = i - b[j] - 1;
				BigInteger cnt = BigInteger.ZERO;
				if(tmp >= 0 && tmp < N) 
				for(int u = tmp; u >= 0; u--) {
					cnt = cnt.add(f[u][j - 1]);
				}
				f[i][j] = cnt; 
			}
		}
		for(int i = 0; i < N; i++) res = res.add(f[i][K - 1]);
		return res;
	}
	
	public static void main(String[] args) {
		ak = new int[205];
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		while(T-- > 0) {
			int n = sc.nextInt(); int k = sc.nextInt();
			if(k == 0) {
				System.out.println("1");
				continue;
			}
			for(int i = 0; i < k; i++) ak[i] = sc.nextInt();
			System.out.println(solve(ak, n, k));
		}
	}
}
