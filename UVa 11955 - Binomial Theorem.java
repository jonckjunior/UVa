import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;
import java.math.BigDecimal;
import java.*;

class Main {



	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt(), caso = 0;
		BigInteger[][] dp = new BigInteger[55][55];
		for(int k = 0; k < 55; k++) dp[k][k] = dp[k][0] = BigInteger.ONE;
		for(int n = 1; n < 55; n++)
			for(int k = 1; k < n; k++)
				dp[n][k] = dp[n-1][k-1].add(dp[n-1][k]);
		
		while(t-- != 0){
			String entrada = sc.next();
			String first = "";
			String second = "";
			String num = "";
			int i, j;
			for(i = 1; i < entrada.length() && entrada.charAt(i) != '+'; i++)
				first = first + entrada.charAt(i);
			for(j = i + 1; j < entrada.length() && entrada.charAt(j) != ')'; j++)
				second = second + entrada.charAt(j);
			for(int k = j+2; k < entrada.length(); k++)
				num = num + entrada.charAt(k);
			int k = Integer.parseInt(num);
			caso +=1;
			System.out.print("Case " + caso + ": ");
			for(int l = 0; l <= k; l++){
				BigInteger aux = dp[k][l];
				int coef1 = k-l, coef2 = l;
				if(aux.toString().equals("1") == false)
					System.out.print(aux+"*");
				if(coef1 != 0){
					if(coef1 == 1) System.out.print(first);
					else 		   System.out.print(first+"^"+coef1);
				}
				if(coef1 != 0 && coef2 != 0) System.out.print("*");
				if(coef2 != 0){
					if(coef2 == 1) System.out.print(second);
					else		   System.out.print(second+"^"+coef2);
				}
				if(l != k) System.out.print("+");
			}
			System.out.println();
		}
	}
}
