import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;
import java.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- != 0){
			BigInteger bx = sc.nextBigInteger();
			BigInteger by = sc.nextBigInteger();
			BigInteger bn = sc.nextBigInteger();
			BigInteger res = bx.modPow(by,bn);
			System.out.println(res);
		}
		int dispose = sc.nextInt();
	}

}
