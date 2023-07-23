
public class ToyotaHighlander extends SUV {
	public ToyotaHighlander() {
		super();
		this.capacity = 12;
		this.costPerDay = 315;
	}

	@Override
	public String toString() {
		return "Toyota Highlander that fits " + this.capacity + " people.";
	}
	
	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
