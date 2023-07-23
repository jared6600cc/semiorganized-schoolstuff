
public class Carpet implements Rentable{
	String purpose;
	String pattern;
	int costPerDay;
	
	public Carpet() {
		this.purpose = "Fly by day";
		this.pattern = "red and black";
		this.costPerDay = 50;
	}
	
	@Override
	public String toString() {
		return "Carpet with a " + this.pattern + " pattern.";
	}

	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
