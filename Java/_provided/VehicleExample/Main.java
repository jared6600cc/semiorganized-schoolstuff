/*
 * Jared Bumgardner
 * COP3022: Project 5
 * note: My objects' purposes are 'heel around' & 'ride downstream'
 */

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declarations & Initializations
		boolean chosen = false;							// True if user has chosen an object to rent
		String userIn = null;							// Buffer for user input
		Scanner sc = new Scanner(System.in);
		RentableFactory rf = new RentableFactory();
		Rentable rentableObject = null;


		// Get purpose from user & find appropriate vehicle
		System.out.println("Hello & welcome to Rent-A-Thingy");
		while(!chosen) {
			System.out.println("Please tell me the purpose of the object you want to rent: ");
			userIn = sc.nextLine();
			rentableObject = rf.create(userIn);

			if(rentableObject != null) {
				System.out.println("Here is a brand new " + rentableObject.toString() + " costing " + rentableObject.rent(1) + "$ per day.");
				System.out.println("Would you like to rent it? (y/n) ");
				userIn = sc.nextLine();
				if(userIn.charAt(0) == 'y') {
					chosen = true;
				}
			}
		}


		// Duration choice & cost calculation
		int numDaysRenting = Integer.MIN_VALUE;
		while(numDaysRenting < 0) {
			System.out.println("How many days? ");
			userIn = sc.nextLine();
			try {
				numDaysRenting = Integer.parseInt(userIn);
			} catch(NumberFormatException e) {
				System.out.println("Error: Not an integer.");
			}
		}
		System.out.println("That would be " + (rentableObject.rent(numDaysRenting)) + "$. Thank you!");


		// Cleanup
		sc.close();
	}
}