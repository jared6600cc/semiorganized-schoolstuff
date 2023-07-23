
public class Ferrari488 extends SportsCar {
	public Ferrari488() {
		super();
		this.horsePower = 711;
		this.costPerDay = 900;
	}

	@Override
	public String toString() {
		return "Ferrari 488 with " + this.horsePower + " horsepower.";
	}
	
	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
