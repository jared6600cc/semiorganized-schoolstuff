
public class TommasoImola extends Bicycle {
	public TommasoImola() {
		super();
		this.numGears = 24;
		this.costPerDay = 35;
	}
	
	@Override
	public String toString() {
		return "Tommaso Imola with " + this.numGears + " gears.";
	}

	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
