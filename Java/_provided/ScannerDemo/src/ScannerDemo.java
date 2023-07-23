import java.util.Scanner;

public class ScannerDemo {
	public static void main(String[] args) {
		Scanner inp = new Scanner(System.in);
		System.out.print("First value > ");
		int n1 = inp.nextInt();
		System.out.print("Second value > ");
		int n2 = inp.nextInt();
		inp.close();
		System.out.println(n1 + " + " + n2 + " = " + (n1+n2));
	}
}
