
public class Traveler {
	
	// Fields
	static int nextIDNum = 0;
	String name;
	int id;
	Location current;
	
	// Methods
	public Traveler() {
		name = null;
		current = null;
	}
	
	public Traveler(String name, Location location) {
		this.name = name;
		current = location;
		id = nextIDNum;
		nextIDNum++;
	}
	
	public String getName() {return name;}
	
	public int getID() {return id;}
	
	public Location getLocation() {return current;}
	
	public void setLocation(Location newL) {this.current = newL;}	
	
	public void setName(String newN) {this.name = newN;}

	public String toString() {
		return ("Traveler [name=" + name + ", id=" + id + ", current=" + current + "]");
	}	
	
}
