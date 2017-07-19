import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;
import java.math.BigDecimal;
import java.*;

class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t;
		while(true){
		    t = sc.nextInt();
		    if(t == 0) break;
		    BigInteger res = BigInteger.ONE;
		    for(int i = 2; i <= t; i++)
		        res = res.multiply(BigInteger.valueOf(i));
		    String ss = res.toString();
		    int[] arr = new int[10];
		    for(int i = 0; i < 10; i++) arr[i] = 0;
		    for(int i = 0; i < ss.length(); i++)
		        arr[ ss.charAt(i)-'0' ] += 1;
		    System.out.println(t+"! --");
		    System.out.println("   (0)   " + arr[0] + "   (1)   " + arr[1] + "   (2)   " + arr[2] + "   (3)   " + arr[3] + "   (4)   " + arr[4]);
		    System.out.println("   (5)   " + arr[5] + "   (6)   " + arr[6] + "   (7)   " + arr[7] + "   (8)   " + arr[8] + "   (9)   " + arr[9]);
		    
		}
	}
}
