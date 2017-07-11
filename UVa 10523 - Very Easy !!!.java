import java.util.Scanner;
import java.math.BigInteger;
import java.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNextInt()){
			int n = sc.nextInt(), a = sc.nextInt();
			BigInteger res = BigInteger.ZERO;
			
			for(int i = 1; i <= n; i++){
				BigInteger k = BigInteger.valueOf(i);
				BigInteger ba = BigInteger.valueOf(a);
				ba = ba.pow(i);	
				ba = ba.multiply(k);
				res = res.add(ba);
			}
			System.out.println(res);
		}
	}

}
