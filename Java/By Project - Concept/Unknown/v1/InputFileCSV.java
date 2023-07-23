/* Jared Bumgardner
 * COP3055: Project 4
 * InputFileCSV.java:		Contains input file code
 */

import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;

public class InputFileCSV {
	/* Instance Variables */
	String fileName;
	File inputFile;
	ArrayList<Asset> data;

	/* Accessors & Mutators */
	/* Methods */
	public Asset findSymbol(String symToCheck) {
		for(Asset a: this.data) {
			if(a.getName().equals(symToCheck)) {
				return a;
			}
		}
		return null;
	}
	public void printData() {
		System.out.println("Available assets for investment\n-------------------------------");
		for(Asset a: this.data) {
			System.out.println(a.toString());
		}
	}
	private void readDataFromFile() throws FileNotFoundException {
		/* Initializations */
		Scanner rowScanner, elemScanner;
		String newLine = "", newElem = "";

		if(this.inputFile == null) {
			// Input file not opening correctly
			throw new FileNotFoundException("Error: Input file missing or not opening.");			
		}
		else {
			// Input file opened successfully
			// Now read row by row
			rowScanner = new Scanner(this.inputFile);
			while(rowScanner.hasNextLine()) {
				ArrayList<Object> newRow = new ArrayList<Object>();				
				newLine = rowScanner.nextLine();
				elemScanner = new Scanner(newLine);
				elemScanner.useDelimiter(",");
				while(elemScanner.hasNext()) {
					newElem = elemScanner.next();
					newRow.add(newElem);
				}
				elemScanner.close();

				// Construct object & add to list of assets
				try {
					if(newRow.size() == 3) {
						// Stable asset
						StableAsset newSA;
						newSA = new StableAsset(newRow);
						this.data.add(newSA);
					} else if(newRow.size() == 4 || newRow.size() == 5) {
						// Stock
						Stock newST = new Stock(newRow);
						this.data.add(newST);
					} else {
						// Malformed row
						System.out.println("MALFORMED*");
					}
				} catch(Exception e) {
					// Failed to successfully read in data
					System.out.print("THE DATA READ FOR " + newRow.get(1) + "(" + newRow.get(0) + ")");
					System.out.println(" WAS NOT VALID, SO IT WILL NOT BE AN AVAILABLE INVESTMENT!");
				}
			}
			rowScanner.close();
		}
	}


	/* Constructor(s) */
	public InputFileCSV() {
		this.fileName = "";
		this.inputFile = null;
		this.data = new ArrayList<Asset>();
	}
	public InputFileCSV(String givenFileName) throws FileNotFoundException{
		this.fileName = givenFileName;
		this.inputFile = new File(givenFileName);
		this.data = new ArrayList<Asset>();
		readDataFromFile();		// populate data field
	}
}
