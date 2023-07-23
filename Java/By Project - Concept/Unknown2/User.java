/*
 * Jared Bumgardner
 * COP3022
 * Lab 3:  14Oct2022
 * User.java: User class declaration.
 * 
 */

public class User {
	// Instance variables
	private String name;
	private String email;
	private int salary;

	// Constructor(s)
	public User() {
		this.email = null;
		this.name = null;
		this.salary = Integer.MIN_VALUE;	// Default to lowest int value (negative)
	}	

	// Getters & Setters
	public String getName() {
		return this.name;
	}
	public String getEmail() {
		return this.email;
	}	
	public int getSalary() {
		return this.salary;
	}

	public void setName(String newName) {
		this.name = newName;
	}
	public void setEmail(String newEmail) throws MalformedEmailAddressException {
		int ampIndex = -1;		// ampersand index
		for(int i=0; i<newEmail.length(); i++) {
			if(newEmail.charAt(i) == '@') {
				if(ampIndex != -1)	// duplicate ampersand in string detected
					throw new MalformedEmailAddressException("Malformed Email Address");
				ampIndex = i;
			}
		}
		if((ampIndex == -1) || (ampIndex == 0) || (ampIndex == newEmail.length() - 1)) {
			throw new MalformedEmailAddressException("Malformed Email Address");
		} else {
			this.email = newEmail;
		}
	}
	public void setSalary(String newSalary) throws NumberFormatException {
		this.salary = Integer.parseInt(newSalary);
	}

	// Public Methods
	public String toString() {
		String s = "";
		s += super.toString() + " [";
		s += "name= " + this.name;
		s += ", email= " + this.email;
		s += ", salary= " + this.salary;
		s += "]";
		return s;
	}
}