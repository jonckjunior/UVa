import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;
import java.math.BigDecimal;
import java.*;

class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger[] dp = new BigInteger[305];
		BigInteger[] fat = new BigInteger[305];
		dp[0] = BigInteger.ONE;
		fat[0] = BigInteger.ONE;
		for(int i = 1; i <= 300; i++){
			dp[i] = dp[i-1].multiply(BigInteger.valueOf(2*i*(2*i-1)));
			dp[i] = dp[i].divide(BigInteger.valueOf( i * (i+1) ));
		}
		for(int i = 1; i <= 300; i++)
			fat[i] = fat[i-1].multiply(BigInteger.valueOf(i));

		while(sc.hasNext()){
			int n = sc.nextInt();
			if(n == 0) break;
			BigInteger res = dp[n].multiply(fat[n]);
			System.out.println(res);
		}
	}
}
