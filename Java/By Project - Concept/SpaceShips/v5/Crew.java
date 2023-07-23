/*
 * COP 3022 P3
 * Crew class
 * 
 * @author Jared Bumgardner
 * 
 */
public class Crew extends Traveler {
	// Private Instance Variables
	private String position;		// rank represented by a string
	private int flightHours;		// number of accumulated flight hours
	
	// Constructors
	public Crew() {
		super("", Location.EARTH);
		this.position = "";
		this.flightHours = 0;
	}
	public Crew(String name, Location curr, String position, int flightHours) {
		super(name, curr);
		this.position = position;
		this.flightHours = flightHours;
	}
	
	// Getters & Setters
	public int getFlightHours() {return this.flightHours;}
	public void setFlightHours() {}
	public String getPosition() {return this.position;}
	public void setPosition() {}
	
	// Methods
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		String s1, s2, s3;
		s1 = "Crew [ " + this.getName() + ", id=" + this.getId();
		s2 = ", current=" + this.getCurrent() + ", position=" + this.getPosition();
		s3 = ", flight hours=" + this.getFlightHours();
		return s1 + s2 + s3;
	}
	@Override
	public void move(SpaceShip s) {
		// TODO Auto-generated method stub
		return;
	}	
}