import java.util.Scanner; // to perform input from the keyboard


/* Jared Bumgardner
 * COP3022
 * Project 1
 * 4 Sept. 2022
 */


// Implements the game of Stix (a simplified version of an ancient game).
public class Stix {
	// Read an integer from the user
	private static int readInt(Scanner sc, String message) {
		System.out.print(message);
		while(!sc.hasNextInt()) {
			System.out.println("Value must be an integer");
			sc.next();//consume wrong token
			System.out.println(message);
		}
		return sc.nextInt();
	}


	// Read an integer that falls within a range from the user
	private static int readRange(Scanner sc, String message, int low, int high) {
		int i = readInt(sc, message);
		while(i < low || i > high) {
			System.out.println("Input must be between " + low + " and " + high);
			i = readInt(sc, message);
		}
		return i;
	}


	// Read a char (don't matter what) from user
	private static char readChar(Scanner sc, String message) {
		System.out.print(message);
		return sc.next().charAt(0);
	}


	// Read a char 'y' or 'n' (AND NAUGHT ELSE) from user
	private static char readYOrN(Scanner sc, String message) {
		char y = 'y'; char n = 'n';
		char c = readChar(sc, message);
		while((Character.compare(c, y) != 0) && (Character.compare(c, n) != 0)) {
			System.out.println("Input must be 'y' or 'n' ");
			c = readChar(sc, message);
		}
		return c;
	}


	// Print out the current number of sticks to the display
	private static void printStix(int quantity) {
		System.out.print("Stix on the table: ");
		for(int i = 0; i < quantity; i++) {
			System.out.print("| ");
		}
		System.out.print("\n");
	}


	// Set flag according to parameters from user
	private static boolean setTurn(char computerFirstAnswer) {
		boolean b = false;
		if(Character.compare(computerFirstAnswer, 'y') == 0) {
			b = true;
		}
		return b;
	}


	// The computer's 'turn'
	private static int computerPlay(int currNumStix) {
		int computerNumTake = 1;

		// Aim for closest (lower) amount odd numbers of stix
		if(currNumStix > 4) {
			if(currNumStix % 2 == 1) {
				// keep it odd
				computerNumTake = 2;
			}
		}
		// Force a win!
		if((currNumStix <= 4) && (currNumStix >= 2)) {
			computerNumTake = currNumStix - 1;
		}

		String outputLine = "Computer takes ";
		System.out.println(outputLine+computerNumTake);
		return computerNumTake;
	}


	// Prompts for & returns the users choice
	private static int userPlay(Scanner sc, int currNumStix) {
		// Construct the prompt
		String message = "How many stix to take? [";
		int low = 1;
		message += low;
		message += '-';
		int high = 0;
		// Alter bounds at low stick numbers
		if(currNumStix < 3) {
			high = currNumStix;
		} else {
			high = 3;
		}
		message += high;
		message += "] > ";
		return readRange(sc, message, low, high);
	}


	// Displays winner of game
	private static void displayWinner(boolean computersTurnOnFinish) {
		if(computersTurnOnFinish) {
			System.out.print("You win!");			// computer took last stick
		} else {
			System.out.print("Computer wins...");	// you took last stick
		}
	}


	// MAIN FUNCTION
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);		// input object

		// Get user input
		int numStix = readRange(input, "How many stix to begin with? [5-30] > ", 5, 30);
		char computerFirst = readYOrN(input, "Computer goes first? [y/n] > ");

		// Begin game according to user input
		boolean computersTurn = setTurn(computerFirst);
		while(numStix > 0) {
			printStix(numStix);
			if(computersTurn == true) {
				numStix = numStix - computerPlay(numStix);
			} else {
				numStix = numStix - userPlay(input, numStix);
			}
			if(numStix == 0) {
				// GAME OVER
				displayWinner(computersTurn);
			}
			computersTurn = !computersTurn;
		}

		input.close(); // gone!
	}
}