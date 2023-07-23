/*
 * COP 3022 P3
 * AvailableTravelers class
 * 
 * @author Jared Bumgardner
 * 
 */
public class AvailableTravelers {	
	// Private instance fields
	private int numOfTravelers;
	private Traveler[] travelers;
	
	// Constructors
	public AvailableTravelers() {
		this.numOfTravelers = 0;
		this.travelers = new Traveler[20];
	}
	public AvailableTravelers(int numOfTravelers, int capacity) {
		this.numOfTravelers = 0;
		this.travelers = new Traveler[capacity];
	}
	
	// Setters & Getters // TODO
	public int getNumOfTravelers() {return this.numOfTravelers;}
	
	// Methods
	public Traveler findTravelerByName(String name) {
		Traveler t = null;
		for(int i = 0; i < this.numOfTravelers; i++) {
			if(travelers[i].getName().equals(name)) {
				t = travelers[i];
			}
		}
		return t;
	}
	public boolean addTraveler(Traveler t) {
		boolean added = false;
			if(numOfTravelers <= this.travelers.length) {
				this.travelers[numOfTravelers] = t;
				numOfTravelers++;
				added = true;
			}
		return added;
	}
	public String toString() {
		String s = "";
		for(int i = 0; i < this.numOfTravelers; i ++) {
			s = s + travelers[i].toString() + '\n';
		}
		return s;
	}
	public String toString(String onShip) {
		String s = "";
		for(int i = 0; i < this.numOfTravelers; i++) {
			if(travelers[i].toString().contains(onShip))
				s = s + travelers[i].toString() + '\n';
		}
		return s;
	}
}
