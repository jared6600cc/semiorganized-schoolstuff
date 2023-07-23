
public class FordEscape extends SUV {
	public FordEscape() {
		super();
		this.capacity = 5;
		this.costPerDay = 200;
	}
	
	@Override
	public String toString() {
		return "Ford Escape that holds " + this.capacity + " people.";
	}

	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
