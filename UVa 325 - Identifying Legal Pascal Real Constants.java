import java.io.*;
import java.*;
import java.util.Scanner;
class Main {
   public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            String Str = sc.next();
            if(Str.equals("*") == true) break;
            Boolean res = Str.matches("[-+]?\\d+(\\.\\d+([eE][-+]?\\d+)?|[eE][-+]?\\d+)");
            if(res == true)
                System.out.println(Str + " is legal.");
            else
                System.out.println(Str + " is illegal.");
        }
   }
}
