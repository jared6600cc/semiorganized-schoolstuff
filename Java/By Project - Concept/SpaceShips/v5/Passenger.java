/*
 * COP 3022 P3
 * Passenger class
 * 
 * @author Jared Bumgardner
 * 
 */
public class Passenger extends Traveler {
	// Private Instance Variables
	private double cost;
	private SeatCategory seat;
	private int rewardsPoints;
	
	// Constructors
	public Passenger() {	// constructor
		super("", Location.EARTH);
		this.cost = 449.00;
		this.seat = SeatCategory.COACH;
		this.rewardsPoints = 0;
	}
	public Passenger(String name, Location curr, SeatCategory seat, int rewardsPoints) {	// parameterized constructor
		super(name, curr);
		this.cost = 449.00;		// TODO: this should be set according to seatcategory
		this.seat = seat;
		this.rewardsPoints = rewardsPoints;
	}

	
	// Getters & Setters
	public double getCost() {return this.cost;}
	public void setCost(double newCost) {this.cost = newCost;}
	public SeatCategory getSeat() {return this.seat;}
	public void setSeat(SeatCategory newSeat) {
		switch(newSeat.toString()) {
			case "COACH" : 
				setCost(499.00);
				break;
			case "BUSINESS" :
				setCost(998.00);
				break;
			case "FIRST" : 
				setCost(1499.00);
				break;
		
		}
	}
	public int getRewardsPoints() {return this.rewardsPoints;}
	public void setRewardsPoints(int newRPoints) {this.rewardsPoints = newRPoints;}
	
	// Methods
	@Override
	public String toString() {
		return "Passenger [" + this.getName() + ", id=" + this.getId() + ", current=" + this.getCurrent() + ", seat=" + this.getSeat() + ", cost=" + this.getCost() + ", rewardsPoints=" + this.getRewardsPoints();
	}
	@Override
	public void move(SpaceShip s) {
		// TODO Auto-generated method stub
		
		
	}
}
