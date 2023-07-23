
public class Carver500 extends Boat {
	public Carver500() {
		super();
		this.lengthFt = 50;
		this.costPerDay = 750;
	}
	
	@Override
	public String toString() {
		return "Carver500 thats " + this.lengthFt + "ft long";
	}

	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
