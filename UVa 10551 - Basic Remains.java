import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;
import java.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		while(sc.hasNext()){
			int base = sc.nextInt();
			if(base == 0) break;

			String n1 = sc.next(), n2 = sc.next();
			BigInteger p = new BigInteger(n1, base), q = new BigInteger(n2, base);
			System.out.println( (p.mod(q)).toString(base) );
		}
	}

}
