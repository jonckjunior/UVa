import java.io.*;
import java.*;
import java.util.Scanner;
class Main {
   public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            String Str = sc.nextLine();
            System.out.println(Str.replaceAll("[^a-zA-Z]+", " ").trim().split(" ").length);
        }
   }
}
