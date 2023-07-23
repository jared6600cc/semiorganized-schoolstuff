/* Jared Bumgardner
 * Project 7
 * 2 Dec.
 * DaleksGame: contains main logic of game
 */

import java.util.ArrayList;
import java.util.Random;

public class DaleksGame {
	// Private Instance Fields
	private static final int gameWorldSize = 30;
	
	// Instance Fields
	public int numMoves = 0;
	Random rng = new Random();
	int doctorPosition;
	ArrayList<Integer> dalekPositions = new ArrayList<Integer>();

	public int safeRandomPosition() throws Exception {
		if(dalekPositions.size() + 1 == gameWorldSize) {
			throw new Exception("No safe spaces exist.");
		}
		int newPosition = -1;
		boolean safe = false;
		while(!safe) {
			newPosition = rng.nextInt(gameWorldSize - 1);
			safe = true;
			for(Integer i: dalekPositions) {
				if(i == newPosition) {
					 safe = false;
				}
			}
		}
		return newPosition;
	}
	
	public DaleksGame() {
		// POSITIONS
		try {
			dalekPositions.add(safeRandomPosition());
			dalekPositions.add(safeRandomPosition());
			doctorPosition = safeRandomPosition();
		} catch(Exception e) {
			System.out.println(e.getMessage());
		}
		
	}
	
	public void moveDaleks() {
		for(Integer i: dalekPositions) {
			if(i < doctorPosition) {	// move left
				dalekPositions.set(dalekPositions.indexOf(i), i + 1);
			} else {	// move right
				dalekPositions.set(dalekPositions.indexOf(i), i - 1);
				i--;
			}
		}
	}
	public void moveDoctor() {
		numMoves++;
		try {
			doctorPosition = safeRandomPosition();
		} catch(Exception e) {
			System.out.println(e.getMessage());
		}
		
	}
	public void moveDoctor(int incr) {
		numMoves++;
		//Check if the dr is on the wall
		if(doctorPosition != 0 && doctorPosition != gameWorldSize - 1) {
			doctorPosition = doctorPosition + incr;
		} else if(doctorPosition == 0 && (incr > 0)) {
			doctorPosition = doctorPosition + incr;
		} else if((doctorPosition == gameWorldSize - 1) && (incr < 0)) {
			doctorPosition = doctorPosition + incr;
		}
	}
	
	public String getWorld() {
		String world = "";
		for(int i = 0; i < gameWorldSize; i++) {
			if(i == doctorPosition) {
				world = world + "D";
			} else if(dalekPositions.contains(i)) {
				world = world + "*";
			} else {
				world = world + "_";
			}
		}
		return world + '\n';
	}
	
	public boolean doctorCaught() {
		boolean caught = false;
		for(Integer i: dalekPositions) {
			if(i == doctorPosition) {
				caught = true;
			}
		}
		return caught;
	}
}
