import static org.junit.Assert.*;
import org.junit.Test;

public class Lab5Tests {
	
	@Test
	public void test1() {
		// Test normal string for success (baseline)
		assertTrue(StringUtils.reverse("qwertyuiop").equals("poiuytrewq"));
	}
	
	@Test
	public void test2() {
		// Test string of special symbols for success
		assertTrue(StringUtils.reverse("~!@#$%^&*()_+").equals("+_)(*&^%$#@!~"));
	}
	
	@Test
	public void test3() {
		// Test empty string for success (edge case)
		assertTrue(StringUtils.reverse("").equals(""));
	}
	
	@Test
	public void test4() {
		// Test numerical input for failure (illegal input)
		assertFalse(StringUtils.reverse("123456789") == "987654321");
	}
}
