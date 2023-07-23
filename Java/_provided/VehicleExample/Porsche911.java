
public class Porsche911 extends SportsCar {
	public Porsche911() {
		super();
		this.horsePower = 640;
		this.costPerDay = 750;
	}

	@Override
	public String toString() {
		return "Porsche 911 that has " + this.horsePower + " horsepower.";
	}
	
	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
