
public class TrackerPro extends Boat {
	public TrackerPro() {
		super();
		this.lengthFt = 17;
		this.costPerDay = 500;
	}

	@Override
	public String toString() {
		return "Tracker Pro thats " + this.lengthFt + "ft long";
	}
	
	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
