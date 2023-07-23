package withtostring;

public class Person {
	// Instance fields (Instance variables)
	private String name;
	private int age;
	private Address addr;
	
	// Constructors
	public Person() {	// Default constructor (no-arg constructor)
		name = null;
		age = -1;
		addr = null;
	}
	
	public Person(String name, int age, Address addr) { 	// Fully parameterized constructor
		this.name = name;
		this.age = age;
		this.addr = addr;
	}

	// Get/Set methods
	// You don't have to implements every one - your choice!
	// Note that the names should REALLY look like this:
	//    getXyz and setXyz, where xyz is the variable name
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public Address getAddr() {
		return addr;
	}

	public void setAddr(Address addr) {
		this.addr = addr;
	}

	@Override
	public String toString() {
		return "Person [name=" + name + ", age=" + age + ", addr=" + addr + "]";
	}
}
