package staticStuff;

import java.util.Scanner; // Needed for the Scanner class

/**
 * This program demonstrates the Scanner class.
 */

public class Payroll {

	/*
	 * This is how to call a function from a main: it's the same as a normal method,
	 * just using the "static" modifier This needs to be the case if you call it
	 * from another static method
	 * 
	 * This reads from the given Scanner an int number It will complain if something
	 * else it put in (inputted?) Uses the standard "hasNextInt - nextInt" idiom
	 */
	private static int readInt(Scanner sc, String prompt) {
		System.out.print(prompt);
		while (!sc.hasNextInt()) {
			System.out.println("Input must a an int!");
			sc.next(); // Consume the wrong token from the input
			System.out.print(prompt);
		}
		return sc.nextInt(); // Now it's safe!
	}
	
	/*
	 * Same for double inputs
	 */
	private static double readDouble(Scanner sc, String prompt) {
		System.out.print(prompt);
		while (!sc.hasNextDouble()) {
			System.out.println("Input must a a double!");
			sc.next(); // Consume the wrong token from the input
			System.out.print(prompt);
		}
		return sc.nextDouble(); // Now it's safe!
	}

	public static void main(String[] args) {
		
		// "final" variables are named constants
		// They allow for initialization, but no more assignments
		final String prompt1 = "How many hours did you work this week? ";
		final String prompt2 = "What is your hourly pay rate? ";

		String name; // To hold a name
		int hours; // Hours worked
		double payRate; // Hourly pay rate
		double grossPay; // Gross pay

		// Create a Scanner object to read input.
		Scanner keyboard = new Scanner(System.in);

		// Get the user's name.
		System.out.print("What is your name? ");
		name = keyboard.nextLine();

		// Get the number of hours worked this week.
		hours = readInt(keyboard, prompt1);

		// Get the user's hourly pay rate.
		payRate = readDouble(keyboard, prompt2);
		keyboard.close();

		// Calculate the gross pay.
		grossPay = hours * payRate;

		// Display the resulting information.
		System.out.println("Hello " + name);
		System.out.println("Your gross pay is $" + grossPay);
	}
}
