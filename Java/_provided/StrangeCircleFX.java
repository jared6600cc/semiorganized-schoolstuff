import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;

public class StrangeCircleFX extends Application {
	public void start(Stage primaryStage) {
		//create pane for circle
		Pane pane1 = new Pane();

		//create circle
		Circle circle1 = new Circle();
		circle1.centerXProperty().bind(pane1.widthProperty().divide(2));
		circle1.centerYProperty().bind(pane1.heightProperty().divide(2));
		circle1.radiusProperty().bind(pane1.heightProperty().divide(pane1.widthProperty()).multiply(100));
		circle1.setStroke(Color.GOLDENROD);
		circle1.setFill(Color.ALICEBLUE);

		//put things in pane
		pane1.getChildren().add(circle1);

		//put pane in scene & launch
		Scene scene1 = new Scene(pane1, 750, 750);
		primaryStage.setTitle("Strange Circle");
		primaryStage.setScene(scene1);
		primaryStage.show();
	}

	public static void main(String[] args) {
		//launch
		Application.launch();
	}
}