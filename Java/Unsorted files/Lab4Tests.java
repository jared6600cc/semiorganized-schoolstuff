/*
 * Jared Bumgardner
 * COP3022 : Lab 4
 * Lab4Tests.java : JUnit 4 tests for PasswordChecker.java
 * 30 Oct. 2022
 */

package Lab4;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import org.junit.Before;
import org.junit.Test;

/* JUnit 4 Tests */
public class Lab4Tests {
	private static PasswordChecker pwc;

	@Before
	public void beforeMethod() {
		pwc = new PasswordChecker();
	}

	@Test
	public void testAcceptable() {
		assertTrue(pwc.isAcceptable("qwertyuiopASDFGHJKL1234567890@#$%^&*()_+"));
	}

	@Test
	public void testUnacceptable() {
		assertFalse(pwc.isAcceptable("abc"));
	}
}
