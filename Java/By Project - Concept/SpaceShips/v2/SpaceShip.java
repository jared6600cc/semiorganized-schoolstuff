/*
 * COP 3022 P2
 * Traveler class
 * 
 * @author Bernd OK
 * 
 */
public class SpaceShip {
	private static final int DEFAULT_CAPACITY = 10;
	
	// Private instance fields as specified
	private String name;
	private Traveler[] passengers;
	private Location current;
	private Location destination;
	private int capacity;
	private int numPassengers;
	
	// This is an example of a private constructor (yes, there things like that)
	// It sets all instance fields to the corresponding parameter values
	// It's private because we don't really want anyone to use it
	// The main objection is that the "passengers" array should have the specified "capacity"
	// It's possible that someone creates a smaller or larger array and then pushes it
	//    into the instance over this constructor - we're just not allowing this
	private SpaceShip(String name, Traveler[] passengers, Location current, Location destination,
			int capacity) {
		assert name != null & destination != null && capacity > 0;
		this.name = name;
		this.passengers = passengers;
		this.current = current;
		this.destination = destination;
		this.capacity = capacity;
		numPassengers = 0;
	}

	// This is the public constructor
	// It just creates an array of the "capacity" and pushes it into the private constructor
	// Do I really need the private constructor? Can't I fill fill the instance fields directly?
	// Well, yes - could have done that. The reason I didn't is that I always like to have
	//    this fully parameterized constructor which just does everthing and hide it if it's not wanted 
	public SpaceShip(String name, Location current, Location destination, int capacity) {
		this(name, new Traveler[capacity], current, destination, capacity);
	}

	// Default constructor as specified
	public SpaceShip() {
		this(null, new Traveler[DEFAULT_CAPACITY], null, null, DEFAULT_CAPACITY);
	}
	
	// Setters and Getters
	public String getName() {
		return name;
	}

	public Location getCurrent() {
		return current;
	}
	
	public Location getDestination() {
		return destination;
	}

	public void setDestination(Location destination) {
		assert destination != null;
		this.destination = destination;
	}
	
	public int getCapacity() {
		return capacity;
	}
	
	// Return the position of Traveler t in the "passengers" array (-1 if not found)
	// Not really needed (hence private!) but makes lifge a little easier
	//    in other spots
	// Do I have to explain how it works? Really?
	private int positionOf(Traveler t) {
		for (int i = 0; i < numPassengers; i++) {
			if (passengers[i].getId() == t.getId()) return i;
		}
		return -1;
	}
	
	// Check if this traveler is on board (use ID to check)
	public boolean isOnBoard(Traveler t) {
		assert t != null;
		return (positionOf(t) >= 0);
	}
	
	// Board Traveler t
	// Easy-ish: Check if there's still space and t isn't already on board
	//           If yes - put t in, increase number, return true
    //           If no - return false
	public boolean board(Traveler t) {
		assert t != null;
		if ((capacity > numPassengers) && !isOnBoard(t)) {
			passengers[numPassengers++] = t;
			return true;
		} 
		else
		{
			return false;
		}
	}
	
	// Let Traveler t off board
	// Only problem is to make sure t doesn't leave a gap in the array
	public boolean leave(Traveler t) {
		assert t != null;
		
		// 1. Is t even on board??
		int position = positionOf(t);
		if (position < 0) return false;	// Nope! Done
		
		// Ok, we know t is on index position "position" (>= 0)
		// Now here we have two choices and the specs are silent about how to do it
		// A. We can slide up all the elements after position one notch
		// B. We can just move the last passenger into the gap
		
		// Version A. maintains the sequence of passengers
		// Version B. is faster
		
		// Here is version A
		for (int i = position; i < numPassengers; i++) {
			passengers[i] = passengers[i+1];
		}
		passengers[numPassengers-1] = null; // We'll talk about this, maybe
		numPassengers--;					// Don't forget this - EVER!!
		return true;
	}

	// Move the ship from its current location to its destination
	public void move() {
		assert destination != null; // Assuming there is one, of course!
		
		current = destination;	// We're there
		destination = null;		// No idea where to go
		// Now get 'em off board!
		// Everyone is now at the current ship position
		for (int i = 0; i < numPassengers; i++) {
			passengers[i].setCurrent(current);
			passengers[i] = null; // And why do I do this???
		}
		numPassengers = 0; // All out, cleaning crew can come in
	}
	
	// toString - no comment
	@Override
	public String toString() {
		return "Spaceship [name=" + name + ", current=" + current
				+ ", destination=" + destination 
				+ ", capacity=" + capacity + ", crew=" + numPassengers + "]";
	}	
}
