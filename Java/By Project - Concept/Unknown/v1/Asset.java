/* Jared Bumgardner
 * COP3055: Project 4
 * Asset.java:		Contains abstract class
 */

public abstract class Asset {
	/* Instance Variables */
	private String name;
	private double expectedReturn;
	
	/* Accessors & Mutators */
	public String getName() {return this.name;}
	public void setName(String newName) {this.name = newName;}
	public double getExpectedReturn() {return this.expectedReturn;}
	public void setExpectedReturn(double newER) {this.expectedReturn = newER;}
	
	/* Methods */
	
	/* Constructor(s) */
	public Asset() {
		this.expectedReturn = 0;
	}
}
