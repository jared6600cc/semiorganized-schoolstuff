import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;



/*
 * Jared Bumgardner
 * Project 2
 * 18 Sept. 2022
 */



public class SpaceShipTester {
	
	public static List<Traveler> createInitialTravelers(UserIO io , int numTravelers) {
		String newName;
		Location newLocation;
		
		List<Traveler> travelers = new ArrayList<Traveler>();
		for(int i=1; i <= numTravelers; i++) {
			System.out.println("Data for Traveler " + i);
			newName = io.readString("Name: ");
			newLocation = io.readLocation("Current: ");
			Traveler t = new Traveler(newName, newLocation);
			System.out.println("Traveler " + i + " " + t.toString());
			travelers.add(t);
		}
		return travelers;
	}
	
	public static List<SpaceShip> createInitialSpaceShips(UserIO io, int numSpaceShips){
		String newName;
		Location newLocation;
		
		List<SpaceShip> spaceships = new ArrayList<SpaceShip>();
		for(int i=1; i <= numSpaceShips; i++) {
			SpaceShip s = new SpaceShip();
			System.out.println("Data for Ship " + i);
			s.setName(io.readString("Name: "));
			s.setCurrent(io.readLocation("Current: "));
			s.setDestination(io.readLocation("Destination: "));
			System.out.println("Spaceship " + i + " " + s.toString());
			spaceships.add(s);
		}
		return spaceships;
	}
	
	public static void main(String[] args) {
		/* A */		// Asks for 4 travelers & 2 spaceships
		UserIO io = new UserIO();
		List<Traveler> travelers = createInitialTravelers(io, 4);
		List<SpaceShip> spaceships = createInitialSpaceShips(io, 2);

		/* B */
		io.printMenu();
		String choicePrompt = "Enter choice (1-4) ";
		int choice = io.readRange(choicePrompt, 1, 4);
		while(choice != 4) {
			switch(choice) {
			case 1 : // Add traveler to a spaceship
				break;
			case 2 : // Search for traveler on a spaceship
				break;
			case 3 : // Move a spaceship
				break;
			}
			choice = io.readRange(choicePrompt, 1, 4);
		}
	}
}