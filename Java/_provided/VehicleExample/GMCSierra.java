
public class GMCSierra extends Truck {
	public GMCSierra() {
		super();
		this.towingCapacity = 14500;
		this.costPerDay = 350;
	}

	@Override
	public String toString() {
		return "GMC Sierra which can tow " + this.towingCapacity + " max lbs.";
	}
	
	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
