/* Jared Bumgardner
 * COP3055: Project 4
 * Stock.java:		Contains stock implementation of asset
 */

import java.util.ArrayList;

public class Stock extends Asset{
	/* Instance Variables */
	String nameOfStock;
	double fiveYearReturn;
	double oneYearReturn;
	double ninetyDayReturn;
	
	/* Accessors & Mutators */
	public String getNameOfStock() {return this.nameOfStock;}
	public void setNameOfStock(String newNS) {this.nameOfStock = newNS;}
	public double getFiveYearReturn() {return this.fiveYearReturn;}
	public void setFiveYearReturn(double new5YR) {this.fiveYearReturn = new5YR;}
	public double getOneYearReturn() {return this.oneYearReturn;}
	public void setOneYearReturn(double new1YR) {this.oneYearReturn = new1YR;}
	public double getNinetyDayReturn() {return this.ninetyDayReturn;}
	public void setNinetyDayReturn(double new90DR) {this.ninetyDayReturn = new90DR;}
	
	/* Methods */
	public double calculateER(int numYears) {
		double result = 0;
//		if(numYears == 0) {					I give up
//			if(this.fiveYearReturn == )		out of time to figure it out
//		} else {							I may just no call no show my work.
//			result += calculateER(numYears - 1);	Ghost mode.
//		}
		return result;
	}
	@Override
	public String toString() {
		return nameOfStock + "(" + getName() + ")";
	}
	
	/* Constructor(s) */
		public Stock(ArrayList<Object> description) throws Exception {
			if((description.size() >= 4) && (description.size() <= 5)) {	// Correct # of fields
				try {
					this.setName((String) description.get(0));
					this.nameOfStock = (String) description.get(1);
					if(description.size() == 4) {
						// young stock
						this.fiveYearReturn = Double.MIN_VALUE;
						this.oneYearReturn = Double.parseDouble((String) description.get(2));
						this.ninetyDayReturn = Double.parseDouble((String) description.get(3));
					} else {
						// old stock
						this.fiveYearReturn = Double.parseDouble((String) description.get(2));
						this.oneYearReturn = Double.parseDouble((String) description.get(3));
						this.ninetyDayReturn = Double.parseDouble((String) description.get(4));	
					}
					this.setExpectedReturn(calculateER(10));	// TODO: Change from magic #
				} catch(Exception e) {
						throw new Exception("Unable to read in data as expected");
				}
			}
		}
	}