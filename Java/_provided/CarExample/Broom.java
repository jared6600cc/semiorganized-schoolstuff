
public class Broom implements Rentable {
	String purpose;
	String woodType;
	int costPerDay;
	
	public Broom() {
		this.purpose = "Fly by night";
		this.woodType = "Oak wood";
		this.costPerDay = 10;
	}
	
	@Override
	public String toString() {
		return "Broom with " + this.woodType + " wood.";
	}

	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
