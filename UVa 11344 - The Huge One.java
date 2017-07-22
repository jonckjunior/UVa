import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;
import java.math.BigDecimal;
import java.*;

class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int[] arr = new int[15];
		while(t-- != 0){
			BigInteger n = sc.nextBigInteger();
			int k = sc.nextInt();
			for(int i = 0; i < k; i++)
				arr[i] = sc.nextInt();
			int valid = 1;
			for(int i =0 ; i < k && valid == 1; i++){
				BigInteger aux = n.mod(BigInteger.valueOf(arr[i]));
				if(aux.toString() != "0") valid = 0;
			}
			if(valid == 1)
				System.out.println(n + " - Wonderful.");
			else
				System.out.println(n + " - Simple.");
		}
	}
}
