import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;
import java.math.BigDecimal;
import java.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		BigInteger dp[] = new BigInteger[1005];		
		dp[0] = BigInteger.ONE;
		dp[1] = BigInteger.valueOf(2);
		for(int i = 2; i <= 1001; i++){
			dp[i] = dp[i-1].add(dp[i-2]);
		}
		int n;
		while(sc.hasNext()){
			n = sc.nextInt();
			System.out.println(dp[n]);
		}
	}

}
