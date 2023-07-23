import java.util.Scanner;

/*
 * Jared Bumgardner
 * COP3022
 * Lab 3:  14Oct2022
 * UserTest: Contains main().
 * 
 */

public class UserTest {	
	public static void main(String[] args) {
		// Declarations
		Scanner sc = new Scanner(System.in);

		// Prompt user for info & create corresponding object
		User u = new User();

		System.out.println("Enter your name: ");
		u.setName(sc.nextLine());

		while(u.getSalary() < 0) {
			System.out.println("Enter your salary: ");			
			try {
				u.setSalary(sc.nextLine());
			} catch(NumberFormatException e) {
				// Wrong number! Get right type of number
				System.out.println("Error: Please enter an integer value.");
			}
		}

		while(u.getEmail() == null) {
			System.out.println("Enter your email address: ");
			try {
				u.setEmail(sc.nextLine());
			} catch (MalformedEmailAddressException e) {
				// Not a valid email address! Get a good one
				System.out.println("Error: Please enter a valid email address.");
			}
		}

		// Print the properties of User object
		System.out.println(u.toString());

		// Cleanup
		sc.close();
	}
}