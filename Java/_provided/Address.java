
/*
 * This represents an address of a person, company, etc
 */
public class Address {
	private String street;
	private String city;
	private int zip;
	
	// No default constructor!
	public Address(String street, String city, int zip) {
		this.street = street;
		this.city = city;
		this.zip = zip;
	}

	// Getters/Setters
	public String getStreet() {
		return street;
	}

	public void setStreet(String street) {
		this.street = street;
	}

	public String getCity() {
		return city;
	}

	public void setCity(String city) {
		this.city = city;
	}

	public int getZip() {
		return zip;
	}

	public void setZip(int zip) {
		this.zip = zip;
	}
	
	
	
	
}
