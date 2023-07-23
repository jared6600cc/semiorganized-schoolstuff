public class ArrayDemo {
	public static void main(String[] args) {
		int limit = 10;							// Capacity can be a variable!
		double[] numbers = new double[limit];	// Declaration and initialization apart!
		
		for (int i = 0; i < limit; i++) {		// Fill in the array
			numbers[i] = Math.PI*i;
		}

		for (int i = 0; i < limit; i++) {		// Read the array
			System.out.println(numbers[i]);
		}
		
	}
}
