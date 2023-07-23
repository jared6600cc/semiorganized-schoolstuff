
public class FordF150 extends Truck {
	public FordF150() {
		super();
		this.towingCapacity = 11300;
		this.costPerDay = 375;
	}

	@Override
	public String toString() {
		return "Ford F150 which can tow " + this.towingCapacity + " max lbs.";
	}
	
	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
