/* Jared Bumgardner
 * COP3055: Project 4
 * tester.java:		Contains main
 */

public class tester {
	public static void main(String[] args) {
		//** Initialize & Read input file **//
		UserSession sess = new UserSession();
		InputFileCSV inFile = sess.readInputFile("assetData.csv");
		
		//** Enter user interaction loop **//
		sess.beginTrading(inFile);
		
		// Output results to screen & file
		sess.saveResultsToFile("portfolio.txt");
	}
}