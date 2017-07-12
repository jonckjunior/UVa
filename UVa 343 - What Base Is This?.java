import java.util.Scanner;
import java.math.BigInteger;
import java.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			String a = sc.next(), b = sc.next();
			int b1=-1,b2=-1;
			int mini_a = 1, mini_b=1;
			for(int i = 0; i < a.length(); i++){
				char ax = a.charAt(i);
				if(ax >= '0' && ax <= '9') mini_a = mini_a > (ax-'0') ? mini_a : (ax-'0');
				else mini_a = mini_a > (ax-'A'+10) ? mini_a : (ax-'A'+10);
			}
			for(int i = 0; i < b.length(); i++){
				char ax = b.charAt(i);
				if(ax >= '0' && ax <= '9') mini_b = mini_b > (ax-'0') ? mini_b : (ax-'0');
				else mini_b = mini_b > (ax-'A'+10) ? mini_b : (ax-'A'+10);
			}
			mini_a += 1;
			mini_b += 1;
			for(int i = mini_a; i <= 36 && b1 == -1; i++){
				BigInteger p = new BigInteger(a, i);
				String sp = p.toString();
				for(int j = mini_b; j <= 36; j++){
					BigInteger q = new BigInteger(b, j);
					String sq = q.toString();
					//System.out.println(sp.toUpperCase() + " e " + sq.toUpperCase());
					if( (sp.toUpperCase()).equals(sq.toUpperCase())){
						b1 = i;
						b2 = j;
						break;
					}
				}
			}
			if(b1 != -1 && b2 != -1) System.out.println(a + " (base " + b1 + ") = " + b + " (base " + b2 +")");
			else 					 System.out.println(a + " is not equal to " + b + " in any base 2..36");
		}
	}

}
