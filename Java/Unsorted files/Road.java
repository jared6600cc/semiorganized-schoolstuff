import javafx.scene.shape.Rectangle;

/** Jared Bumgardner
CS225 - Final Project
The road class defines a road for which cars will drive on
 */

public class Road extends Rectangle {
	/**variable fields*/
	boolean isVertical;

	/**constructors*/
	public Road() {}		//default constructor

	/**getters & setters*/
	public boolean getIsVertical() {		//get is-vertical
		return this.isVertical;
	}

	public void setIsVertical(boolean isVertical) {		//set is-vertical
		this.isVertical = isVertical;
	}

	/**methods*/
	public void setValues(Rectangle road, double stageSideSize, boolean isVertical) {
		/**determine values based on orientation*/
		if (isVertical == true) {			
			road.setWidth(stageSideSize / 5.0);
			road.setHeight(stageSideSize);
			road.setX((stageSideSize / 2.0) - (road.getWidth() / 2.0));
			road.setY(0);
			this.isVertical = true;

		}

		else {
			road.setWidth(stageSideSize);
			road.setHeight(stageSideSize / 5.0);
			road.setX(0);
			road.setY((stageSideSize / 2.0) - (road.getHeight() / 2.0));
			this.isVertical = false;
		}
	}
}