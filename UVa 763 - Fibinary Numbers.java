import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;
import java.math.BigDecimal;
import java.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String n1,n2;
		BigInteger dp[] = new BigInteger[105];
		BigInteger first = BigInteger.ONE;
		BigInteger second = BigInteger.ONE;
		dp[0] = first;
		dp[1] = second;
		BigInteger c = null;
		for(int i = 2; i <= 104; i++){
			c = first.add(second);
			first = second;
			second = c;
			dp[i] = c;
		}
		int firstline = 0;
		while(sc.hasNext()){
			n1 = sc.next();
			n2 = sc.next();
			if(firstline == 1) System.out.println(); 
			n1 = new StringBuffer(n1).reverse().toString();
			n2 = new StringBuffer(n2).reverse().toString();
			BigInteger b1 = BigInteger.ZERO;
			BigInteger b2 = BigInteger.ZERO;
			for(int i = 0; i < n1.length(); i++){
				if(n1.charAt(i) == '1')
					b1 = b1.add( dp[i+1] );
			}
			for(int i = 0; i < n2.length(); i++){
				if(n2.charAt(i) == '1')
					b2 = b2.add( dp[i+1] );
			}
			BigInteger ans = b1.add(b2);
			String res = "";
			int firstNumber = 0;
			for(int i = 104; i >= 1; i--){
				if(ans.compareTo(dp[i]) >= 0){
					ans = ans.subtract(dp[i]);
					res = res + "1";
					firstNumber = 1;
				}
				else if(firstNumber == 1)
					res = res + "0";
			}
			if(res.length() == 0) res = "0";
			System.out.println(res);
			firstline = 1;
		}
	}

}
