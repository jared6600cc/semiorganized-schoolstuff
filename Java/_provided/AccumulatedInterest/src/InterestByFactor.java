import java.util.Scanner;

public class InterestByFactor {
	public static void main(String[] args) {
		// Read initial amount, annual interest rate and increase factor
		// Track amount increase by year
		
		// Read input data and close the Scanner
		Scanner inp = new Scanner(System.in);
		System.out.print("Initial amount > ");
		double amount = inp.nextFloat();
		System.out.print("Annual interest (%) > ");
		double rate = inp.nextFloat();
		System.out.print("Increased by factor > ");
		double factor = inp.nextFloat();
		double target = amount*factor;
		inp.close();
		
		int year = 1;
		while (amount < target) {
			System.out.print(year++ + "\t" + amount + "\t");
			// Accumulate interest - middle school math (I hope)
			amount = amount + amount*rate/100.0;
			// Make sure its rounded to two digits
			amount = Math.round(amount*100.0)/100.0;
			System.out.println(amount);
		}
	}
}
