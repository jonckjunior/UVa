import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;
import java.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ArrayList<String> v = new ArrayList<String>();
		int caso = 0, offset = 0;
		while(sc.hasNext()){
			String ns = sc.next();
			int base_origem = sc.nextInt();
			int base_destino = sc.nextInt();
			BigInteger bb = new BigInteger(ns, base_origem);
			String res = (bb.toString(base_destino)).toUpperCase();
			if(res.length() > 7)
				res = "ERROR";
			v.add(res);
			if(res.length() > offset) offset = res.length();
		}
		for(int i = 0; i < v.size(); i++){
			String att = v.get(i);
			for(int j = att.length(); j < offset; j++)
				System.out.printf(" ");
			System.out.println(att);
		}
		
	}

}
