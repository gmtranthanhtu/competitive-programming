/*
 * Problem: UVa 12143 Stopping Doomday
 * Author: 3T - mailto:gm.tranthanhtu@gmail.com
 * Time Limit: 3.000s
 * Algorithm: math, factorial, formula simplyfing
 */

import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static final int[] facto = {120, 720, 5040, 40320, 362880, 3628800};
	public static final int[] d = {120, 2480, 15280, 38720, 42800, 17120};
	public static final int[] ans = {0, 0, 0, 120, 3200, 5139, 6959, 3988, 8968, 4108, 9728, 444, 2199};
	public static int n;
	public static final int ba = 10007;
	
	public static BigInteger solve() {
		if(n <= 12) return BigInteger.valueOf(ans[n]);
		int t = n - 7;
		BigInteger[] a = new BigInteger[6];
		a[0] = BigInteger.ONE;
		for(int i = 5; i <= 9; i++) a[0] = a[0].multiply(BigInteger.valueOf(t + i));
		
		for(int i = 1; i <= 5; i++) {
			a[i] = BigInteger.ZERO;
            BigInteger tmp = a[i - 1].multiply(BigInteger.valueOf(t + 5 - i));
			a[i] = a[i].add(tmp);
		}
		
		BigInteger[] a2 = new BigInteger[6];
		for(int i = 0; i <= 5; i++) {
			a2[i] = a[i].multiply(BigInteger.valueOf(d[i]));
            a2[i] = a2[i].divide(BigInteger.valueOf(facto[i]));
		}
		BigInteger SumAll = BigInteger.ZERO;
		for(int i = 0; i <= 5; i++) {
			SumAll = SumAll.add(a2[i]);
			SumAll = SumAll.remainder(BigInteger.valueOf(ba));
		}
		
		return SumAll;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		while(n != 0) {
			BigInteger res = solve();
			System.out.println(res);
			n = sc.nextInt();
		}
	}
}
