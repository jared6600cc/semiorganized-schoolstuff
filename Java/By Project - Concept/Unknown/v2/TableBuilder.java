/* Jared Bumgardner
 * COP3055: Project 4
 * TableBuilder.java:		Contains output table code.
 */

import java.util.ArrayList;

public class TableBuilder {
	ArrayList <String> headers;
	ArrayList<ArrayList<Object>> rows;
	
	public void printToFile(String outFileName) {	// this is trash; not enough time to figure it out; i wanna quit my job so i can pass
		// Get dimensions
		int maxColWidth = 0;
		for(String s: headers) {
			if(maxColWidth < s.length()) {
				maxColWidth = s.length();
			}
		}
		
		// Print header	
		for(String s: headers) {
			System.out.print(String.format("|%s", s));
		}
		System.out.println("|");
		// Print body
		for(ArrayList<Object> alo: rows) {
			for(Object o: alo) {
				System.out.print(String.format("|%s", o.toString()));
			}
			System.out.println("|");
		}
		// Print footer
		System.out.print("|TOTAL");
	}
		
	public TableBuilder(ArrayList<ArrayList<Object>> inData) {
		headers = new ArrayList<String>();
		this.headers.add("ASSET SYMBOL");
		this.headers.add("AMOUNT INVESTED");
		this.headers.add("VALUE IN TEN YEARS");
		rows = inData;
	}
}
