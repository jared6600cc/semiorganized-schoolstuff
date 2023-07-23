import java.util.ArrayList;


public class Stock extends Asset{
	/* Instance Variables */
	String stockTicker;
	String nameOfStock;
	double fiveYearReturn;
	double oneYearReturn;
	double ninetyDayReturn;
	
	/* Accessors & Mutators */
	public String getStockTicker() {return this.stockTicker;}
	public void setStockTicker(String newST) {this.stockTicker = newST;}
	public String getNameOfStock() {return this.nameOfStock;}
	public void setNameOfStock(String newNS) {this.nameOfStock = newNS;}
	public double getFiveYearReturn() {return this.fiveYearReturn;}
	public void setFiveYearReturn(double new5YR) {this.fiveYearReturn = new5YR;}
	public double getOneYearReturn() {return this.oneYearReturn;}
	public void setOneYearReturn(double new1YR) {this.oneYearReturn = new1YR;}
	public double getNinetyDayReturn() {return this.ninetyDayReturn;}
	public void setNinetyDayReturn(double new90DR) {this.ninetyDayReturn = new90DR;}
	
	/* Methods */
	
	
	/* Constructor(s) */
	public Stock() {
		super();
	}
	public Stock(ArrayList<Object> description) {
		if(description.size() < 4) {
			
		}
	}
}
