/*
 * Problem: LightOJ 1214 - Large Division 
 * Author: 3T - //mailto:gm.tranthanhtu@gmail.com
 * Date: 30 March 2013
 * Algorithm: BigInteger
 * Time Limit: 1s
 * */

import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	static int T;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		T = sc.nextInt();
		for(int i = 1; i <= T; i++) {
			BigInteger a = sc.nextBigInteger();
			BigInteger b = sc.nextBigInteger();
			a = a.abs();
			b = b.abs();
			BigInteger c = a.mod(b);
			if(c == BigInteger.ZERO) System.out.println("Case " + i + ": divisible");
			else System.out.println("Case " + i + ": not divisible");
		}
	}
}
