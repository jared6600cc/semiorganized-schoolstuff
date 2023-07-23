/*
 * COP 3022 P2
 * Traveler class
 * 
 * @author Bernd OK with additions by Jared Bumgardner
 * 
 */
public abstract class Traveler {
	private static int idCounter = 0;	// Static variable to hold the ID counter
	
	// Provate instance fields (see specs)
	private String name;
	private int id;
	private Location current;
	
	// Constructor
	// The asserts are there as placeholders of
	// what would need to be checked in the outer code
	public Traveler(String name, Location current) {
		assert name != null && current != null;
		this.name = name;
		this.id = ++idCounter;	// This is how you use the static counter
								// Note that idCounter++ would have given
								// the first Traveler instance an ID of 0
		this.current = current;
	}

	// Setters/getters and toString (not commenting any of that)
	public String getName() {
		return name;
	}
	public int getId() {
		return id;
	}
	public Location getCurrent() {
		return current;
	}
	public void setCurrent(Location current) {
		assert current != null;
		this.current = current;
	}

	// abstract methods
	public abstract String toString();
	public abstract void move(SpaceShip s);
}