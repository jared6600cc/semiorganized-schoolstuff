/*
Jared Bumgardner
5/12/15
1.7
*/

public class Ch1N7 {
	public static void main(String[] args) {
		double pi6;
		double pi7;
		
		//Approximate pi
		pi6 = 4 * (1.0 - (1/3) + (1/5) - (1/7) + (1/9) - (1/11));
		pi7 = 4 * (1.0 - (1/3) + (1/5) - (1/7) + (1/9) - (1/11) + (1/13));
		
		//Print both pi's
		System.out.println("The value of PI using six n's is: " + pi6);
		System.out.println("The value of PI using seven n's is: "+ pi7);
		
	}
}