import java.util.Scanner;
import java.math.BigInteger;
import java.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(true){
			String entrada = sc.next();
			if(entrada.equals("0")) break;
			BigInteger res = new BigInteger(entrada);
			BigInteger x = BigInteger.valueOf(17);
			BigInteger zero = BigInteger.ZERO;
			res = res.remainder(x);
			if(res.compareTo(zero) == 0)
				System.out.println("1");
			else
				System.out.println("0");
		}
	}

}
