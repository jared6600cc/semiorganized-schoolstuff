import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

/** Jared Bumgardner
CS225 - Final Project
The Light class creates a circular light with varying radius, center-point position, & on/off property
 */

public class Light extends Circle {

	/**constructors*/
	public Light() {
		super(15);
	}		//default constructor

	public Light(int color) {		//color constructor
		super(15);
		this.setFillAndStroke(color);
	}

	public void setFillAndStroke(int color) {
		switch (color) {
		case 0:
			this.setFill(Color.RED);
			this.setStroke(Color.DARKRED);
			break;

		case 1:
			this.setFill(Color.YELLOW);
			this.setStroke(Color.DARKGOLDENROD);
			break;

		case 2:
			this.setFill(Color.YELLOWGREEN);
			this.setStroke(Color.DARKGREEN);
		}
	}

	/**methods*/
	public void turnOff() {		//turn off light

		/**turn off light based on current color*/
		if (this.getFill().equals(Color.RED)) {
			this.setFill(Color.DARKRED);
		}
		else if (this.getFill().equals(Color.YELLOW)) {
			this.setFill(Color.DARKGOLDENROD);
		}
		else if (this.getFill().equals(Color.YELLOWGREEN)) {
			this.setFill(Color.DARKGREEN);
		}
		else {
			/**Light is already off*/
		}
	}

	public void turnOn() {		//turn on light

		/**turn off light based on current color*/
		if (this.getFill().equals(Color.DARKRED)) {
			this.setFill(Color.RED);
		}
		else if (this.getFill().equals(Color.DARKGOLDENROD)) {
			this.setFill(Color.YELLOW);
		}
		else if (this.getFill().equals(Color.DARKGREEN)) {
			this.setFill(Color.YELLOWGREEN);
		}
		else {
			/**Light is already on*/
		}
	}
}