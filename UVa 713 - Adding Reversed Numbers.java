import java.util.Scanner;
import java.math.BigInteger;
import java.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- != 0){
			String a = sc.next(), b = sc.next();
			StringBuffer ra = new StringBuffer(a);
			StringBuffer rb = new StringBuffer(b);
			ra.reverse();
			rb.reverse();
			BigInteger na = new BigInteger(ra.toString());
			BigInteger nb = new BigInteger(rb.toString());
			na = na.add(nb);
			StringBuffer res = new StringBuffer(na.toString());
			res.reverse();
			int flag = 0;
			for(int i = 0; i < res.length(); i++){
				char c = res.charAt(i);
				if(flag == 1) System.out.print(c);
				else if(c != '0'){
					System.out.print(c);
					flag = 1;
				}

			}
			System.out.println();
		}
	}

}
