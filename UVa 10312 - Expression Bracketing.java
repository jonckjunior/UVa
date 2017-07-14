import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;
import java.math.BigDecimal;
import java.*;

class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger[] dp = new BigInteger[35];
		BigInteger[] superdp = new BigInteger[35];
		dp[0] = BigInteger.ONE;
		for(int i = 1; i <= 30; i++){
			dp[i] = dp[i-1].multiply(BigInteger.valueOf(2*i*(2*i-1)));
			dp[i] = dp[i].divide(BigInteger.valueOf( i * (i+1) ));
		}
		superdp[1] = BigInteger.ONE;
		superdp[2] = BigInteger.ONE;
		for(int i = 3; i <= 30; i++){
			superdp[i] = (superdp[i - 1].multiply(BigInteger.valueOf(6 * i - 9)).subtract 
                 (superdp[i - 2].multiply(BigInteger.valueOf(i - 3))).divide
                 (BigInteger.valueOf(i)));
		}

		while(sc.hasNext()){
			int n = sc.nextInt();
			System.out.println(superdp[n].subtract(dp[n-1]));
		}
	}
}
