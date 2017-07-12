import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;
import java.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- != 0){
			BigInteger a = sc.nextBigInteger();
			String dispose = sc.next();
			BigInteger b = sc.nextBigInteger();
			BigInteger gcd = a.gcd(b);
			System.out.println(a.divide(gcd) + " / " + b.divide(gcd));
		}
	}

}
