
public class PersonTester {
	public static void main(String[] args) {
		// Create a Person instance (object) via default constructor
		Person p1 = new Person();
		System.out.print(p1.getName() + " ");
		System.out.println(p1.getAge());
		
		// Create a Person instance (object) via parameterized constructor
		Person p2 = new Person("Hugo",27);
		System.out.print(p2.getName() + " ");
		System.out.println(p2.getAge());
		
		// Change values in p1 and check
		p1.setName("Helga");
		p1.setAge(31);
		System.out.print(p1.getName() + " ");
		System.out.println(p1.getAge());
		System.out.print(p2.getName() + " ");
		System.out.println(p2.getAge());	
	}
}
