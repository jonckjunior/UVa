import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
	private static final String VERB = "(hate|love|know|like|hates|loves|knows|likes)";
	private static final String NOUN = "(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)";
	private static final String ARTICLE = "(a|the)";
	private static final String ACTOR = "(" + NOUN + "|" + ARTICLE + " " + NOUN
			+ ")";
	private static final String ACTIVE_LIST = "(" + ACTOR + " and )*" + ACTOR;
	private static final String ACTION = ACTIVE_LIST + " " + VERB + " "
			+ ACTIVE_LIST;
	private static final String STATEMENT = ACTION + "([ ]?,[ ]?" + ACTION + ")*";

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s;
		while (sc.hasNext()) {
			s = sc.nextLine();
			//System.out.println("entrada = " + s);
			s = s.replaceAll("[ ]{2,}", " ");
			s = s.trim();
		    //System.out.println("entrada = " + s);
			if (s.matches(STATEMENT)) {
			    System.out.println("YES I WILL");
			} else {
			    System.out.println("NO I WON'T");
			}
		}
	}
}
