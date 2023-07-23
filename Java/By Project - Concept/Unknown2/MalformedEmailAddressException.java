/*
 * Jared Bumgardner
 * COP3022
 * Lab 3:  14Oct2022
 * MalformedEmailAddressException.java: custom exception indicating that an email address is formatted incorrectly.
 * 
 */

public class MalformedEmailAddressException extends Exception {
	public MalformedEmailAddressException(String errorMessage) {
		super(errorMessage);
	}
}