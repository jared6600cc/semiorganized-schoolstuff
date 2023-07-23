/*
 * COP 3022 P3
 * ExpanseTester class : Contains main()
 * 
 * @author Jared Bumgardner
 * 
 */

public class ExpanseTester {
	public static AvailableTravelers createPopulatedAvailTravelersObject() {
		AvailableTravelers availT = new AvailableTravelers();
		
		// Populate with 4 passengers
		Passenger p1 = new Passenger("Abe", Location.EARTH, SeatCategory.FIRST, 0);
		availT.addTraveler(p1);
		Passenger p2 = new Passenger("Bushra", Location.EARTH, SeatCategory.FIRST, 0);
		availT.addTraveler(p2);
		Passenger p3 = new Passenger("Carlos", Location.EARTH, SeatCategory.FIRST, 0);
		availT.addTraveler(p3);
		Passenger p4 = new Passenger("Delta", Location.EARTH, SeatCategory.FIRST, 0);
		availT.addTraveler(p4);
		// Populate with 6 crew members
		Crew c1 = new Crew("Eric", Location.EARTH, "Captain", 0);
		availT.addTraveler(c1);
		Crew c2 = new Crew("Ffff", Location.EARTH, "Captain", 0);
		availT.addTraveler(c2);
		Crew c3 = new Crew("Geri", Location.EARTH, "Cocaptain", 0);
		availT.addTraveler(c3);
		Crew c4 = new Crew("Heem", Location.EARTH, "Cocaptain", 0);
		availT.addTraveler(c4);
		Crew c5 = new Crew("Ira", Location.EARTH, "Crew", 0);
		availT.addTraveler(c5);
		Crew c6 = new Crew("Jared", Location.EARTH, "Crew", 0);
		availT.addTraveler(c6);
		
		return availT;
	}
	
	public static void main(String[] args) {
		// TODO: Create an Available Travelers object & 2 SpaceShips
		AvailableTravelers availT = createPopulatedAvailTravelersObject();
		SpaceShip spaceships[] = new SpaceShip[2];
		SpaceShip s1 = new SpaceShip("Rocinante", Location.EARTH, Location.BELT, 10);	// "...heading for the heart of cygnus..
		spaceships[0] = s1;
		SpaceShip s2 = new SpaceShip("Behemoth", Location.BELT, Location.MARS, 500);
		spaceships[1] = s2;
		
		// Enter text based menu
		UserIO io = new UserIO();
		io.printMenu();
		String choicePrompt = "Enter choice (1-6) ";
		int choice = io.readRange(choicePrompt, 1, 6);
		while(choice != 6) {
			String buffer = "";
			switch(choice) {
			case 1 : // Add traveler to a spaceship from the available travelers object
				System.out.println("Available Passengers: \n" + availT.toString());
				break;
			case 2 : // Search for traveler on a spaceship
				buffer = io.readString("Searching for traveler: ");
				availT.findTravelerByName(buffer);
				break;
			case 3 : // TODO: Option3: move a spaceship to a new location
				buffer = io.readString("Moving spaceship: ");
				for(int i = 0; i < spaceships.length; i++) {
					if(spaceships[i].getName().equals(buffer)) {
						spaceships[i].move();
					} else {
						System.out.println("ERROR MOVING");
					}
				}
				break;
			case 4 : // Option4: displays a list of available travelers
				availT.toString();
				break;
			case 5 : // Displays a list of travelers on a specific spaceship (ID by name)
				buffer = io.readString("Ship to lists its travelers: ");
				for(int i = 0; i < availT.getNumOfTravelers(); i++) {
					availT.toString(buffer);
				}
				break;
			}
			choice = io.readRange(choicePrompt, 1, 6);
		}
		System.out.println("Bye!");
	}
}