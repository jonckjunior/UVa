import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;
import java.math.BigDecimal;
import java.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		BigInteger[] dp = new BigInteger[15001];
		int arr [] = {0,60,300,1500,15000};
		dp[0] = BigInteger.ZERO;
		dp[1] = BigInteger.ONE;
		for(int i = 2; i <= 15000; i++)
			dp[i] = dp[i-1].add(dp[i-2]);
		while(t-- != 0){
			int a = sc.nextInt(), b = sc.nextInt(), n = sc.nextInt(), m = sc.nextInt();
			n %= arr[m];
			BigInteger bb = BigInteger.valueOf(b);
			BigInteger ba = BigInteger.valueOf(a);
			BigInteger res = (bb.multiply(dp[n])).add(ba.multiply(n == 0 ? BigInteger.ONE: dp[n - 1]));
			

			String resRev = new StringBuffer(res.toString()).reverse().toString();
			String finaldigits = "";
			for(int i = 0; i < resRev.length() && i < m; i++)
				finaldigits = finaldigits + resRev.charAt(i);
			finaldigits = new StringBuffer(finaldigits).reverse().toString();
			String resposta = "";
			int primeirodigito = 0;
			for(int i = 0; i < finaldigits.length(); i++){
				if(primeirodigito == 1)
					resposta = resposta + finaldigits.charAt(i);
				else if(finaldigits.charAt(i) != '0'){
					resposta = resposta + finaldigits.charAt(i);
					primeirodigito = 1;
				}
			}
			if(resposta.length() == 0) resposta = "0";
			System.out.println(resposta);
		}	
	}
}
