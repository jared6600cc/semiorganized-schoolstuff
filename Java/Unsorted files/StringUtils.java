/* Jared Bumgardner
 * COP3022: Lab 5: Theme JUnit
 * 13 Nov 2022
 */

import java.util.Stack;

/* StringUtils (class) provides string utilities */
public class StringUtils {
	/* StringUtils.reverse(String s): Returns a string representing s reversed. */
	public static String reverse(String s) {
		Stack<Character> stk = new Stack<Character>();			
		String result = "";
		
		// Push s onto stack
		for(int i = 0; i < s.length(); i++) {
			stk.push(s.charAt(i));
		}
		// Pop s from stack
		for(int i = 0; i < s.length(); i++) {
			result += stk.pop();
		}
		
		return result;
	}
}
