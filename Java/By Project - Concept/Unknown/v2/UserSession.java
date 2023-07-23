/* Jared Bumgardner
 * COP3055: Project 4
 * UserSession.java:		Contains data about current session
 */

import java.util.ArrayList;
import java.util.Formatter;
import java.util.Scanner;

public class UserSession {
	/* Instance Variables */
	InputFileCSV inFile;
	ArrayList<ArrayList<Object>> userInvestments; 
	
	/* Accessors & Mutators */
	public InputFileCSV getInFile() {return this.inFile;}
	public void setInFile(InputFileCSV newInFile) {this.inFile = newInFile;}
	
	/* Methods */
	public void saveResultsToFile(String outputFileName) {
		TableBuilder tb = new TableBuilder(userInvestments);
		tb.printToFile(outputFileName);
	}
	
	public InputFileCSV readInputFile(String inFName) {
		InputFileCSV inFile = null;
		try {
			inFile = new InputFileCSV(inFName);
		} catch(Exception e) {
			// Failed to successfully open & read input file
			System.out.println("[ERROR: " + e.getMessage() + "]\n...exiting...\n");
			System.exit(-1);
		}
		return inFile;
	}
	
	public void beginTrading(InputFileCSV inFile) {
		Scanner scn = new Scanner(System.in);
		String inputBuffer;
		int amountToInvest;
		Asset assetToInvest;
		
		while(true) {
			inFile.printData();
			
			System.out.print("Enter the amount to invest in dollars: ");
			inputBuffer = scn.next();
			try {
				amountToInvest = Integer.parseInt(inputBuffer);
				if(amountToInvest < 0) {
					break;
				}
			} catch(NumberFormatException e) {
				break;
			}
			
			System.out.print("Enter the asset symbol to invest in: ");
			inputBuffer = scn.next();
			assetToInvest = inFile.findSymbol(inputBuffer);
			while(assetToInvest == null) {
				System.out.println(inputBuffer + " not in the input, or had invalid input data. Choose something else to invest in.");
				inputBuffer = scn.next();
				assetToInvest = inFile.findSymbol(inputBuffer);
			}
			
			// Simulate the user's investment over time
			ArrayList<Object> newUserInvestment = new ArrayList<Object>();
			newUserInvestment.add(assetToInvest.getName());
			newUserInvestment.add(amountToInvest);
			newUserInvestment.add(-999);	// TODO CHANGEME
			userInvestments.add(newUserInvestment);
			System.out.println("Investing " + amountToInvest + " in " + inputBuffer + " has an expected future value of: ");
		}
		scn.close();
	}

	/* Constructor(s) */
	public UserSession() {
		this.inFile = null;
		this.userInvestments = new ArrayList<ArrayList<Object>>();
	}
	public UserSession(InputFileCSV inFile) {
		this.inFile = inFile;
		this.userInvestments = new ArrayList<ArrayList<Object>>();
	}
}
