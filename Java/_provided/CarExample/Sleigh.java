
public class Sleigh implements Rentable {
	String purpose;
	int numPullers;
	int costPerDay;
	
	public Sleigh() {
		this.purpose = "Slide on snow";
		this.numPullers = 12;
		this.costPerDay = 1231;
	}

	@Override
	public String toString() {
		return "Sleigh with " + this.numPullers + " animals pulling it.";
	}
	
	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
