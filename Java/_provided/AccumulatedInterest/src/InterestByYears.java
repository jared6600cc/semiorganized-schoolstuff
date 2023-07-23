import java.util.Scanner;

public class InterestByYears {
	public static void main(String[] args) {
		// Read initial amount, annual interest rate and run time
		// Track amount increase by year
		
		// Read input data and close the Scanner
		Scanner inp = new Scanner(System.in);
		System.out.print("Initial amount > ");
		double amount = inp.nextFloat();
		System.out.print("Annual interest (%) > ");
		double rate = inp.nextFloat();
		System.out.print("Number of years > ");
		int years = inp.nextInt();
		inp.close();
		
		for (int year = 1; year <= years; year++) {
			System.out.print(year + "\t" + amount + "\t");
			// Accumulate interest - middle school math (I hope)
			amount = amount + amount*rate/100.0;
			// Make sure its rounded to two digits
			amount = Math.round(amount*100.0)/100.0;
			System.out.println(amount);
		}
	}
}
