
public class BugattiVeyron extends SportsCar {
	public BugattiVeyron() {
		super();
		this.horsePower = 1200;
		this.costPerDay = 850;
	}
	
	@Override
	public String toString() {
		return "Bugatti Veyron with " + this.horsePower + " horsepower.";
	}

	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
