
public class CadillacATS extends LuxurySedan {
	public CadillacATS() {
		super();
		this.seatMaterial = "Faux Leather";
		this.costPerDay = 450;
	}

	@Override
	public String toString() {
		return "Cadillac ATS with " + this.seatMaterial + " seats.";
	}
	
	@Override
	public int rent(int numDays) {
		return (this.costPerDay * numDays);
	}
}
