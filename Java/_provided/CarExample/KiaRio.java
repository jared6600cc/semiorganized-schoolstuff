
public class KiaRio extends Subcompact {
	public KiaRio() {
		super();
		this.mpg = 36;
		this.costPerDay = 200;
	}

	@Override
	public String toString() {
		return "Kia Rio that gets " + this.mpg + "mpg.";
	}
	
	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
