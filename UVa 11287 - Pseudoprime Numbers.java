import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;
import java.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		while(sc.hasNext()){
			int p = sc.nextInt(), a = sc.nextInt();
			if(p == 0 && a == 0) break;
			BigInteger bp = BigInteger.valueOf(p);
			BigInteger ba = BigInteger.valueOf(a);
			BigInteger res1 = ba.modPow(bp,bp);
			BigInteger res2 = ba.mod(bp);
			int n1 = Integer.parseInt(res1.toString());
			int n2 = Integer.parseInt(res2.toString());
			if(n1 == n2 && bp.isProbablePrime(10) == false) System.out.println("yes");
			else		 System.out.println("no");
		}
	}

}
