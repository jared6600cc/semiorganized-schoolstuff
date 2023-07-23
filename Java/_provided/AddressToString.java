
/*
 * This represents an address of a person, company, etc
 */
public class AddressToString {
	private String street;
	private String city;
	private int zip;
	
	// No default constructor!
	public AddressToString(String street, String city, int zip) {
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

	// The "toString" methods returns a String representation suitable for displaying
	@Override
	public String toString() {
		return "AddressToString [street=" + street + ", city=" + city + ", zip=" + zip + "]";
	}
}
