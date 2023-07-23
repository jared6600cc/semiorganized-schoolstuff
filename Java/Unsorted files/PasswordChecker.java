/*
 * Jared Bumgardner
 * COP3022 : Lab 4
 * PasswordChecker.java : Object that checks given strings for acceptability.
 * 30 Oct. 2022
 */

package Lab4;

public class PasswordChecker {
	/* isAcceptable(String givenPass) : 
	 * Returns boolean value based on argument givenPass. 
	 */
	public boolean isAcceptable(String givenPass) {
		// Initialize flags
		boolean correctLength = false;
		boolean atLeastOneDigit = false;
		boolean atLeastOneUpperCaseLetter = false;
		boolean atLeastOneLowerCaseLetter = false;
		boolean atLeastOneSpecialSymbol = false;
		boolean result = false;

		/* Check argument for specified properties */
		if(givenPass.length() >= 10) {
			// argument is long enough
			correctLength = true;

			for(int i = 0; i < givenPass.length(); i++) {
				if(Character.isDigit(givenPass.charAt(i))) {
					// argument contains a digit
					atLeastOneDigit = true;
				}

				if(Character.isUpperCase(givenPass.charAt(i))) {
					// argument contains an upper-case letter
					atLeastOneUpperCaseLetter = true;
				}

				if(Character.isLowerCase(givenPass.charAt(i))) {
					// argument contains a lower-case letter
					atLeastOneLowerCaseLetter = true;
				}

				if(givenPass.charAt(i) == '!' || givenPass.charAt(i) == '*' || givenPass.charAt(i) == '?') {
					// argument contains '!', '*', or '?'.
					atLeastOneSpecialSymbol = true;
				}
			}
		}

		/* Did it meet all criteria? */
		if(correctLength && atLeastOneDigit && atLeastOneUpperCaseLetter && atLeastOneLowerCaseLetter && atLeastOneSpecialSymbol) {
			result = true;
		}
		return result;
	}

	/* Constructor(s) */
	public PasswordChecker() {}
}
