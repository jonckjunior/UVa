import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;
import java.math.BigDecimal;
import java.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int[] number = new int[105];
		while(t-- != 0){
			int tam = sc.nextInt(), nn = sc.nextInt();
			int whitesquares = 0, blacksquares = 0;
			for(int i = 0; i < nn; i++){
				number[i] = sc.nextInt();
				blacksquares += number[i];
			}
			whitesquares = tam-blacksquares;
			if(whitesquares < nn-1)
				System.out.println("0");
			else if(nn == 0)
				System.out.println("1");
			else{
				whitesquares += 1;
				int m = whitesquares-nn;
				BigInteger high = BigInteger.ONE;
				BigInteger low  = BigInteger.ONE;
				for(int i = m+1; i <= whitesquares; i++){
					high = high.multiply(BigInteger.valueOf(i));
					low  = low.multiply(BigInteger.valueOf(whitesquares-i+1));
				}
				System.out.println(high.divide(low));
			}
		}
	}
}
