import java.util.List;

public class SpaceShip {
	
	// Fields
	String name;
	int capacity;
	List<Traveler> travelers;
	int numTravelers;
	Location current, destination;
	
	// Methods
	public SpaceShip() {
		setName(null);
		setCurrent(null);
		setDestination(null);
		setCapacity(10);
		//create travelers array? set size to capacity? :(
	}
	
	public SpaceShip(String name) {
		setName(name);
	}
	
	public SpaceShip(String name, Location current, Location destination, int capacity) {
		setName(name);
		setCurrent(current);
		setDestination(destination);
		setCapacity(capacity);
	}
	
	public String getName() {return this.name;}
	
	public int getCapacity() {return this.capacity;}
	
	public Location getCurrent() {return this.current;}
	
	public Location getDestination() {return this.destination;}
	
	public void setName(String name) {this.name = name;}
	
	public void setCurrent(Location current) {this.current = current;}
	
	public void setCapacity(int capacity) {this.capacity = capacity;}
	
	public void setDestination(Location destination) {this.destination = destination;}

	public boolean board(Traveler t) {
		boolean added = false;
		if(t.current != this.current) {
			if(this.capacity != this.numTravelers) {
				if(!isOnBoard(t)) {
					travelers.add(t);
					numTravelers++;
					added = true;
				}
			}
		}
		return added;
	}

	public void leave(Traveler t) {
		if(isOnBoard(t))
			travelers.remove(t);
	}
	
	public boolean isOnBoard(Traveler t) {
		boolean isOnBoard = false;
		for(int i=0; i<this.travelers.size(); i++) {
			if(travelers.contains(t));
				isOnBoard = true;
		}
		return isOnBoard;
	}
	
	public void move() {
		current = destination;
		destination = null;
		Traveler tmp;
		for(int i=0; i<this.travelers.size(); i++){
			tmp = travelers.get(i);
			tmp.current = this.current;
			travelers.remove(i);
		}
	}
	
	public String toString() {
		return ("Spaceship [name=" + name + ", current=" + current + ", destination=" + destination + ", capacity=" + capacity + "]");
	}
}