
public class PersonWithAddressToStringTester {
	public static void main(String[] args) {
		// Create a Person instance (object) via default constructor
		PersonWithAddressToString p1 = new PersonWithAddressToString();
		System.out.println(p1);
		
		// Create a Person instance (object) via parameterized constructor
		AddressToString a1 = new AddressToString("222 Google Drive", "Mountain View, CA", 94043);
		PersonWithAddressToString p2 = new PersonWithAddressToString("Hugo",27,a1);
		System.out.println(p2);
		
		// Change values in p1 and check
		AddressToString a2 = new AddressToString("11000 University Parkway", "Pensacola, FL", 32514);
		p1.setName("Helga");
		p1.setAge(31);
		p1.setAddr(a2);
		System.out.println(p1);
		System.out.println(p2);
	}
}
