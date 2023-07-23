
public class Heelys implements Rentable {
	String purpose;
	String laceColor;
	int costPerDay;
	
	public Heelys() {
		this.purpose = "heel around";
		this.laceColor = "rainbow";
		this.costPerDay = 10;
	}
	
	@Override
	public String toString() {
		return "Heelys with " + this.laceColor + " laces.";
	}
	
	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
