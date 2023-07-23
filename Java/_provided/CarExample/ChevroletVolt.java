
public class ChevroletVolt extends Subcompact {
	public ChevroletVolt() {
		super();
		this.mpg = 42;
		this.costPerDay = 100;
	}
	
	@Override
	public String toString() {
		return "Chevrolet Volt that gets " + this.mpg + " mpg.";
	}

	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
