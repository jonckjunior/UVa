import java.util.Scanner;
import java.math.BigInteger;

class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t;
		while(sc.hasNext()){
		    t = sc.nextInt();
		    BigInteger res = BigInteger.ONE;
		    for(int i = 2; i <= t; i++)
		        res = res.multiply(BigInteger.valueOf(i));
		    System.out.println(t+"!");
		    System.out.println(res);
		}
	}
}
