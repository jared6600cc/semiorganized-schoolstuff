package withtostring;

public class PersonTester {
	public static void main(String[] args) {
		// Create a Person instance (object) via default constructor
		Person p1 = new Person();
		System.out.println(p1);
		
		// Create a Person instance (object) via parameterized constructor
		Address a1 = new Address("222 Google Drive", "Mountain View, CA", 94043);
		Person p2 = new Person("Hugo",27,a1);
		System.out.println(p2);
		
		// Change values in p1 and check
		Address a2 = new Address("11000 University Parkway", "Pensacola, FL", 32514);
		p1.setName("Helga");
		p1.setAge(31);
		p1.setAddr(a2);
		System.out.println(p1);
		System.out.println(p2);
	}
}
