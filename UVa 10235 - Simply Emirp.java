import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;
import java.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		while(sc.hasNext()){
			int p1 = sc.nextInt();
			BigInteger first = BigInteger.valueOf(p1);
			String s2 = new StringBuffer(first.toString()).reverse().toString();
			BigInteger second = new BigInteger(s2);
			Boolean isFirstPrime = first.isProbablePrime(10);
			Boolean isSecondPrime = second.isProbablePrime(10);
			int p2 = Integer.parseInt(s2);
			if(isFirstPrime == false)
				System.out.println(p1 + " is not prime.");
			else if(isFirstPrime == true && isSecondPrime == true && p1 != p2)
				System.out.println(p1 + " is emirp.");
			else if(isFirstPrime == true)
				System.out.println(p1 + " is prime.");
		}
	}

}
