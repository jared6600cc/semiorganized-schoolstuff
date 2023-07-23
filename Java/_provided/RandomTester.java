

import java.util.Random;

public class RandomTester {
	public static void main(String[] args) {
		int k;

		//invoke random using random class
		Random ran = new Random();
		System.out.println("***Random Class***");

		for (k = 0 ; k < 9 ; k++) {
			System.out.println(ran.nextDouble());
		}

		//random using math class
		System.out.println("***Math Class***");

		for (k = 0 ; k < 9 ; k++) {
			System.out.println(Math.random());
		}
	}
}