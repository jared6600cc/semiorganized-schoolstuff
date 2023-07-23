import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

/**Jared Bumgardner
CS225 - Final Project
The TrafficSignal class creates a traffic light with lights
 */

public class TrafficSignal extends Pane {

	private Light redLight0, yellowLight0, greenLight0;
	
	public TrafficSignal(double stageSideSize, Rectangle road, int position){
		/**add lights to grid-pane*/
		GridPane trafficGridPane0 = new GridPane();

		redLight0 = new Light(0);
		trafficGridPane0.add(redLight0, 1, 1);

		yellowLight0 = new Light(1);
		trafficGridPane0.add(yellowLight0, 1, 2);

		greenLight0 = new Light(2);
		trafficGridPane0.add(greenLight0, 1, 3);

		/**add grid-pane to rectangle to pane & return*/
		Rectangle trafficLight0 = new Rectangle(30, 93);
		trafficLight0.setStroke(Color.DARKGRAY);

		getChildren().add(trafficLight0);
		getChildren().add(trafficGridPane0);

		if (position == 0) {
			setLayoutX(stageSideSize / 2.0 + road.getWidth() / 2.0 + 10.0);
			setLayoutY(stageSideSize / 2.0 - road.getWidth() / 2.0 - trafficLight0.getHeight() - 10.0);
		}
		else if (position == 1) {
			setLayoutX(stageSideSize / 2.0 - road.getWidth() / 2.0 - trafficLight0.getHeight() - 10.0);
			setLayoutY(stageSideSize / 2.0 - road.getWidth() / 2.0 - 10.0);
			setRotate(270);
		}
		else if (position == 2) {
			setLayoutX(stageSideSize / 2.0 - road.getWidth() / 2.0 - 10.0);
			setLayoutY(stageSideSize / 2.0 + road.getWidth() / 2.0 + trafficLight0.getHeight() + 10.0);
			setRotate(180);
		}
		else {
			setLayoutX(stageSideSize / 2.0 + road.getWidth() / 2.0 + trafficLight0.getHeight() + 10.0);
			setLayoutY(stageSideSize / 2.0 + road.getWidth() / 2.0 + 10.0);
			setRotate(90);
		}
	}
	
	public void setRed() {
		redLight0.turnOn();
		yellowLight0.turnOff();
		greenLight0.turnOff();
	}
	
	public void setYellow() {
		redLight0.turnOff();
		yellowLight0.turnOn();
		greenLight0.turnOff();
	}

	public void setGreen() {
		redLight0.turnOff();
		yellowLight0.turnOff();
		greenLight0.turnOn();
	}
	
	public void setAllOff() {
		redLight0.turnOff();
		yellowLight0.turnOff();
		greenLight0.turnOff();
	}
	
	public void setAllOn() {
		redLight0.turnOn();
		yellowLight0.turnOn();
		greenLight0.turnOn();
	}
}
