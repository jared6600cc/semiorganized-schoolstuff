import java.util.Scanner;

/*
 * COP 3022 P3
 * UserIO class
 * 
 * @author Jared Bumgardner
 * 
 */

public class UserIO {
	static Scanner input;
	
	public static int readInt(String message) {
		System.out.print(message);
		while(!input.hasNextInt()) {
			System.out.println("Value must be an integer");
			input.next();//consume wrong token
			System.out.println(message);
		}
		return input.nextInt();
	}
	public int readRange(String message, int low, int high) {
		int i = readInt(message);
		while(i < low || i > high) {
			System.out.println("Input must be between " + low + " and " + high);
			i = readInt(message);
		}
		return i;
	}
	public String readString(String message) {
		System.out.println(message);
		return input.nextLine();
	}
	public static Location readLocation(String message) {
		Location newLocation = null;
		String inline;
		
		while(true) {
			System.out.println(message);
			inline = input.nextLine();
			switch(inline.toLowerCase()) {
			case "earth" :
				newLocation = Location.EARTH;
				break;
			case "belt" :
				newLocation = Location.BELT;
				break;
			case "mars" :
				newLocation = Location.MARS;
				break;
			case "ring" :
				newLocation = Location.RING;
				break;
			}
				
			if(newLocation == null) {
				System.out.println("Not a valid location...");
				System.out.print("Locations: ");
				for(Location l : Location.values()) {
					System.out.print(l + " ");
				}
				System.out.println();
				continue;
			} else {break;}
		}
		
		// loop through enum if not in, retry, if not set newLocation
		return newLocation;
	}
	public void printMenu() {
		System.out.println("Choose an option");
		System.out.println("1. Add traveler to a spaceship from available travelers.");
		System.out.println("2. Search for Traveler on SpaceShip.");
		System.out.println("3. Move SpaceShip to new Location.");
		System.out.println("4. Displays a list of available travelers.");
		System.out.println("5. Displays a list of travelers on a specific spaceship (ID by name).");
		System.out.println("6. Exit");
	}
	public UserIO() {
		input = new Scanner(System.in);
	}
}