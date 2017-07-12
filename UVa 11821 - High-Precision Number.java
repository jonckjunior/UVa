import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;
import java.math.BigDecimal;
import java.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- != 0){
			ArrayList<String> v = new ArrayList<String>();
			while(true){
				String ss = sc.next();
				if(ss.equals("0"))break;
				v.add(ss);
			}
			BigDecimal res = BigDecimal.ZERO;
			for(int i = 0; i < v.size(); i++)
				res = res.add(new BigDecimal(v.get(i)));
			System.out.println(res.stripTrailingZeros().toPlainString());
		}
	}

}
