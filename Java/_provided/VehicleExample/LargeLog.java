
public class LargeLog implements Rentable{
	String purpose;
	int length;
	int costPerDay;
	
	public LargeLog() {
		this.purpose = "Ride downstream";
		this.length = 50;
		this.costPerDay = 1;
	}
	
	@Override
	public String toString() {
		return "large log thats " + this.length + "ft long";
	}
	
	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
