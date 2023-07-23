
public class MarinRift extends Bicycle {
	public MarinRift() {
		super();
		this.numGears = 11;
		this.costPerDay = 25;
	}

	@Override
	public String toString() {
		return "Marin Rift that has " + this.numGears + " gears.";
	}
	
	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
