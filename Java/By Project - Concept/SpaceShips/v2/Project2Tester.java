
public class Project2Tester {
	public static void main(String[] args) {
		Traveler t1 = new Traveler("Naomi", Location.EARTH);
		Traveler t2 = new Traveler("Klaes", Location.BELT);
		Traveler t3 = new Traveler("Drummer", Location.EARTH);
		Traveler t4 = new Traveler("Amos", Location.EARTH);
		
		System.out.println(t1);
		System.out.println(t2);
		System.out.println(t3);
		System.out.println(t4);

		
		SpaceShip s1 = new SpaceShip("Rocinante",Location.EARTH, Location.BELT,10);
		SpaceShip s2 = new SpaceShip("Behemoth",Location.BELT, Location.MARS,500);
		System.out.println(s1);
		System.out.println(s2);
		
		s1.board(t1);
		s1.board(t3);
		s1.board(t4);
		System.out.println(s1);
		s1.leave(t3);
		s1.move();
		System.out.println(t1);
		System.out.println(t3);
		System.out.println(t4);
		System.out.println(s1);
	}
}
