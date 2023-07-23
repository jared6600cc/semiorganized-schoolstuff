
public class AudiA8 extends LuxurySedan {
	public AudiA8() {
		super();
		this.seatMaterial = "Leather";
		this.costPerDay = 750;
	}
	
	@Override
	public String toString() {
		return "Audi A8 with " + this.seatMaterial + " seats.";
	}

	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
