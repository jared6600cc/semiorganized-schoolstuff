import java.util.Formatter;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.stage.StageStyle;
import javafx.util.Duration;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.geometry.Rectangle2D;
import javafx.scene.Scene;
import javafx.stage.Screen;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.Tooltip;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;

/**Jared Bumgardner
CS225 - Final Project
The StoplightV2Main class defines the stages and main method of the stop-light simulator.
 */

public class StoplightSimV2Main extends Application {

	private TrafficSignal signal1;
	private TrafficSignal signal2;
	private TrafficSignal signal3;
	private TrafficSignal signal4;
	private int seconds = 14;
	Formatter formatter;

	@Override	/**override application class' start method*/
	public void start(Stage primaryStage) throws Exception {

		/**get information about the user's screen*/
		Rectangle2D primaryScreenSizes = Screen.getPrimary().getVisualBounds();
		double stageSideSize = primaryScreenSizes.getHeight() * (3.0 / 4.0);

		/**create pane*/
		BorderPane pane1 = new BorderPane();

		/**create and set values for background*/
		setupBackground(stageSideSize, pane1);

		/**create and add roads + labels*/
		Road roadNorthSouth = new Road();
		roadNorthSouth.setValues(roadNorthSouth, stageSideSize, true);
		Text mainStreetName = new Text(stageSideSize / 2.0, 10.0 , "Main Street");
		mainStreetName.setFont(new Font(20));
		mainStreetName.setStroke(Color.WHITE);
		//TODO add main road label

		Road roadEastWest = new Road();
		roadEastWest.setValues(roadEastWest, stageSideSize, false);
		Text sideStreetName = new Text(10.0, stageSideSize / 2.0, "Side Street");
		sideStreetName.setFont(new Font(20));
		//TODO add side road label

		pane1.getChildren().addAll(roadNorthSouth, roadEastWest, mainStreetName, sideStreetName);

		/**create and add mid-lines*/
		setupMidlines(stageSideSize, pane1, roadNorthSouth, roadEastWest);

		/**create and add traffic lights*/
		signal1 = new TrafficSignal(stageSideSize, roadNorthSouth, 0);
		signal2 = new TrafficSignal(stageSideSize, roadNorthSouth, 1);
		signal3 = new TrafficSignal(stageSideSize, roadNorthSouth, 2);
		signal4 = new TrafficSignal(stageSideSize, roadNorthSouth, 3);
		pane1.getChildren().addAll(signal1, signal2, signal3, signal4);

		/**timer and control lights*/
		Timeline animation = new Timeline(new KeyFrame(Duration.millis(1000), e -> timeBasedLights()));
		animation.setCycleCount(Timeline.INDEFINITE);
		animation.play();		// Start animation

		/**buttons*/
		createMenus(animation, pane1);

		/**keep log (file IO)*/
		try {
			formatter = new Formatter("log.txt");
		}
		catch(Exception e) {
			System.out.println("ERROR: 404 ");
		}

		/**create scene*/
		Scene scene1 = new Scene(pane1);

		/**compose stage*/
		primaryStage.initStyle(StageStyle.UNDECORATED);
		primaryStage.setScene(scene1);
		primaryStage.setWidth(stageSideSize);
		primaryStage.setHeight(stageSideSize);
		primaryStage.setResizable(false);
		primaryStage.setTitle("Stoplight Simulator 2015");
		primaryStage.show();

	}

	private static void setupBackground(double stageSideSize, Pane pane1) {
		ImageView grassImageView = new ImageView("http://ngene.wdfiles.com/local--files/tut-1-8/Grass.jpg");
		grassImageView.setFitHeight(stageSideSize);
		grassImageView.setFitWidth(stageSideSize);
		pane1.getChildren().add(grassImageView);
	}

	private static void setupMidlines(double stageSideSize, Pane pane1, Road roadNorthSouth, Road roadEastWest) {
		Line northLine = new Line((stageSideSize / 2.0), 0, (stageSideSize / 2.0), ((stageSideSize / 2.0) - (roadNorthSouth.getWidth() / 2.0)));
		northLine.setStroke(Color.WHITE);
		Line southLine = new Line((stageSideSize / 2.0), stageSideSize , (stageSideSize / 2.0), ((stageSideSize / 2.0) + (roadNorthSouth.getWidth() / 2.0)));
		southLine.setStroke(Color.WHITE);
		Line westLine = new Line(0, stageSideSize / 2.0, ((stageSideSize / 2.0) - roadEastWest.getHeight() / 2.0) , stageSideSize / 2.0);
		westLine.setStroke(Color.WHITE);
		Line eastLine = new Line(stageSideSize, stageSideSize / 2.0, ((stageSideSize / 2.0) + (roadEastWest.getHeight() / 2.0)) , stageSideSize / 2.0);
		eastLine.setStroke(Color.WHITE);

		pane1.getChildren().add(northLine);
		pane1.getChildren().add(southLine);
		pane1.getChildren().add(westLine);
		pane1.getChildren().add(eastLine);
	}

	public static void upperLeftCoordinates(Rectangle frame, int position, double stageSideSize, Rectangle road) {

		/**determine x and y values based on position it is*/
		if (position == 0) {		//NE
			frame.setX((stageSideSize / 2.0) + road.getWidth() / 2.0 + frame.getWidth() / 2.0);
			frame.setY((stageSideSize / 2.0) - road.getWidth() / 2.0 - frame.getHeight() - 10.0);
		}
		else if (position == 1) {		//NW
			frame.setX((stageSideSize / 2.0) - road.getWidth() / 2.0 - frame.getWidth() - 10.0);
			frame.setY((stageSideSize / 2.0) - road.getWidth());
		}
		else if (position == 2) {		//SW
			frame.setX((stageSideSize / 2.0) - road.getWidth() / 2.0 - frame.getWidth() - 10.0);
			frame.setY((stageSideSize / 2.0) + road.getWidth() / 2.0 + 10.0);
		}
		else {		//SE
			frame.setX((stageSideSize / 2.0) + road.getWidth() / 2.0 + 10.0);
			frame.setY((stageSideSize / 2.0) + road.getWidth() / 2.0 + 10.0);
		}
	}

	private void timeBasedLights() {
		int cycleStep = seconds % 27;		// The stop-light runs a 14-second cycle
		switch(cycleStep){
		case 0:	case 1: case 2: case 3:		// Seconds 0-3
			System.out.println("Main St: Green, Side St: Red");
			signal1.setGreen();
			signal2.setRed();
			signal3.setGreen();
			signal4.setRed();
			break;

		case 4: case 5: case 6:				// Seconds 4-6
			System.out.println("Main St: Yellow, Side St: Red");
			signal1.setYellow();
			signal2.setRed();
			signal3.setYellow();
			signal4.setRed();
			break;

		case 7: case 8: case 9: case 10:	// Seconds 7-10
			System.out.println("Main St: Red, Side St: Green");
			signal1.setRed();
			signal2.setGreen();
			signal3.setRed();
			signal4.setGreen();
			break;

		case 11: case 12: case 13:			// Seconds 11-13
			System.out.println("Main St: Red, Side St: Yellow");
			signal1.setRed();
			signal2.setYellow();
			signal3.setRed();
			signal4.setYellow();

			seconds = 0;
			break;		

		case 14: case 16:		//Case 14 - only red
			signal1.setRed();
			signal2.setRed();
			signal3.setRed();
			signal4.setRed();

			System.out.println("***ALL RED***");
			break;

		case 15: case 17:		//Case 15 - all off
			signal1.setAllOff();
			signal2.setAllOff();
			signal3.setAllOff();
			signal4.setAllOff();

			System.out.println("*ALL OFF*");
			break;

		case 18:		//return to start
			seconds = 0;

			System.out.println("*");
			break;

		case 19: case 20: case 21: case 22:		//pedestrian crossing side street
			signal1.setGreen();
			signal2.setRed();
			signal3.setGreen();
			signal4.setRed();

			System.out.println("*Pedestrian crossing side street*");
			seconds = 0;
			break;

		case 23: case 24: case 25: case 26:		//pedestrian crossing main street
			signal1.setRed();
			signal2.setGreen();
			signal3.setRed();
			signal4.setGreen();

			System.out.println("*Pedestrian crossing main street*");
			seconds = 0;
			break;
		}
		seconds++;
	}

	private void createMenus(Timeline animation, BorderPane pane1) {
		/**create menu items*/
		//create top menu items
		MenuItem miReset = new MenuItem("Reset");
		MenuItem miDisplayLog = new MenuItem("Display Log");
		MenuItem miExit = new MenuItem("Exit");
		MenuItem miAuto = new MenuItem("Auto Mode");
		MenuItem miManual = new MenuItem("Manual Mode");
		MenuItem miAbout = new MenuItem("About");

		//create right button items
		Button resetBt = new Button("Reset");
		resetBt.setTooltip(new Tooltip("Press this to reset the simulation."));

		Button mainStreetManualBt = new Button("Main Street\nManual Control");
		mainStreetManualBt.setTooltip(new Tooltip("Enter to manually switch lights."));
		mainStreetManualBt.setDisable(true);

		Button allStopBt = new Button("All Stop");
		allStopBt.setTooltip(new Tooltip("Turn all lights red."));

		Button malfunctionBt = new Button("Malfunction");
		malfunctionBt.setTooltip(new Tooltip("Turn all lights green."));

		//create manual mode buttons
		Button mainStreetGreenBt = new Button("Main Street Green");
		mainStreetGreenBt.setDisable(true);
		mainStreetGreenBt.setTooltip(new Tooltip("Turn main street lights green."));

		Button mainStreetRedBt = new Button("Main Street Red");
		mainStreetRedBt.setDisable(true);
		mainStreetRedBt.setTooltip(new Tooltip("Turn main street lights red."));

		Button sideStreetGreenBt = new Button("Side Street Green");
		sideStreetGreenBt.setDisable(true);
		sideStreetGreenBt.setTooltip(new Tooltip("Turn side street lights green."));

		Button sideStreetRedBt = new Button("Side Street Red");
		sideStreetRedBt.setDisable(true);
		sideStreetRedBt.setTooltip(new Tooltip("Turn side street lights red."));

		//create bottom pedestrian buttons
		Button pedestrianMainStreetBt = new Button("Pedestrian Main Street");
		pedestrianMainStreetBt.setTooltip(new Tooltip("Simulate pedestrian crossing main street."));

		Button pedestrianSideStreetBt = new Button("Pedestrian Side Street");	
		pedestrianSideStreetBt.setTooltip(new Tooltip("Simulate pedestrian crossing side street."));

		/**set up top menu*/
		Menu menuFile = new Menu("File");
		Menu menuOptions = new Menu("Options");
		Menu menuHelp = new Menu("Help");

		MenuBar menuBar = new MenuBar();
		menuFile.getItems().addAll(miReset, miDisplayLog, miExit);
		menuOptions.getItems().addAll(miAuto, miManual);
		menuHelp.getItems().addAll(miAbout);
		menuBar.getMenus().addAll(menuFile, menuOptions, menuHelp);

		pane1.setTop(menuBar);

		/**set up bottom right buttons*/
		VBox buttonMenu = new VBox(10);
		buttonMenu.setAlignment(Pos.BOTTOM_CENTER);
		buttonMenu.setPadding(new Insets(10));
		buttonMenu.getChildren().addAll(resetBt, allStopBt, malfunctionBt, mainStreetManualBt);
		mainStreetManualBt.setDisable(true);

		pane1.setRight(buttonMenu);

		/**set up bottom left buttons*/
		VBox leftButtonMenu = new VBox(10);
		leftButtonMenu.setAlignment(Pos.BOTTOM_CENTER);
		leftButtonMenu.setPadding(new Insets(10));
		leftButtonMenu.getChildren().addAll(mainStreetGreenBt, mainStreetRedBt, sideStreetGreenBt, sideStreetRedBt);
		pane1.setLeft(leftButtonMenu);

		/**set up bottom pedestrian buttons*/
		VBox topRightButtons = new VBox(10);
		topRightButtons.setAlignment(Pos.BOTTOM_CENTER);
		topRightButtons.setPadding(new Insets(10));
		topRightButtons.getChildren().addAll(pedestrianMainStreetBt, pedestrianSideStreetBt);
		pane1.setBottom(topRightButtons);

		/**top menu listeners*/
		miReset.setOnAction(e -> {		//reset button
			//write to log'
			formatter.format("Reset at %d seconds." , seconds);
			formatter.format("At Reset: Main Street is %s and Side Street is %s.", "TODO", "TODO");		//TODO add color

			//disable manual buttons
			mainStreetGreenBt.setDisable(true);
			mainStreetRedBt.setDisable(true);
			sideStreetGreenBt.setDisable(true);
			sideStreetRedBt.setDisable(true);
			mainStreetManualBt.setDisable(true);

			//enable buttons
			allStopBt.setDisable(false);
			malfunctionBt.setDisable(false);

			//restart animation
			animation.stop();
			seconds = 14;
			animation.play();

		});

		miDisplayLog.setOnAction(e -> {		//display log button
			//TODO Display Log
			System.out.println("FOR NOW: Log on console");

		});

		miExit.setOnAction(e -> {		//exit program button
			formatter.close();
			System.exit(0);

		});

		miAuto.setOnAction(e -> {		//auto button
			formatter.format("Change to Auto at %d seconds.", seconds);

			//enable buttons
			malfunctionBt.setDisable(false);
			allStopBt.setDisable(false);

			//disable buttons
			mainStreetGreenBt.setDisable(true);
			mainStreetRedBt.setDisable(true);
			sideStreetGreenBt.setDisable(true);
			sideStreetRedBt.setDisable(true);
			mainStreetManualBt.setDisable(true);

			//restart animation
			animation.stop();
			animation.play();
		});

		miManual.setOnAction(e -> {			//manual button
			formatter.format("Change to Manual at %d seconds.", seconds);

			//enable manual buttons
			mainStreetGreenBt.setDisable(false);
			mainStreetRedBt.setDisable(false);
			sideStreetGreenBt.setDisable(false);
			sideStreetRedBt.setDisable(false);
			mainStreetManualBt.setDisable(false);

			//disable right side buttons
			allStopBt.setDisable(true);
			malfunctionBt.setDisable(true);

			//stop animation
			animation.pause();
		});

		miAbout.setOnAction(e -> {		//about button
			showAbout();
		});

		/**bottom right button listeners*/
		resetBt.setOnAction(e -> {		//reset button
			formatter.format("Reset at %d seconds.", seconds);
			formatter.format("At Reset: Main Street is %s and Side Street is %s", "TODO", "TODO");		//TODO add colors

			if (seconds < 14) {

				//stop animation
				animation.stop();

				//disable manual buttons
				mainStreetGreenBt.setDisable(true);
				mainStreetRedBt.setDisable(true);
				sideStreetGreenBt.setDisable(true);
				sideStreetRedBt.setDisable(true);
				mainStreetManualBt.setDisable(true);

				//reactivate buttons
				allStopBt.setDisable(false);
				malfunctionBt.setDisable(false);

				//restart animation
				seconds = 14;
				animation.play();
			}

		});

		mainStreetManualBt.setOnAction(e -> {		//manual main street button
			//stop animation
			animation.stop();

			//enable manual control buttons
			mainStreetGreenBt.setDisable(false);
			mainStreetRedBt.setDisable(false);
			mainStreetManualBt.setDisable(false);

			//disable buttons
			allStopBt.setDisable(true);
			malfunctionBt.setDisable(true);
			sideStreetGreenBt.setDisable(true);
			sideStreetRedBt.setDisable(true);

		});

		allStopBt.setOnAction(e -> {		//all stop button

			if (seconds < 14) {
				//set all lights to redS
				signal1.setRed();
				signal2.setRed();
				signal3.setRed();
				signal4.setRed();
				animation.stop();

				//disable buttons
				mainStreetManualBt.setDisable(true);
				allStopBt.setDisable(true);
				malfunctionBt.setDisable(true);
			}
		});

		malfunctionBt.setOnAction(e -> {		//malfunction button
			formatter.format("Malfunction at %s seconds.", seconds);

			if (seconds < 14) {
				//set all lights to green
				signal1.setGreen();
				signal2.setGreen();
				signal3.setGreen();
				signal4.setGreen();
				animation.stop();

				try {
					int x = 10;
					x = 10 / 0;
					System.out.println(x);
				}
				catch (ArithmeticException ex) {
					System.out.println("This is me proving that I can make a simple exception handler");
					System.out.println("I tried to divide something by 0.");
				}

				//disable buttons
				mainStreetManualBt.setDisable(true);
				allStopBt.setDisable(true);
				malfunctionBt.setDisable(true);
			}
		});

		/**bottom left buttons listeners*/
		mainStreetGreenBt.setOnAction(e -> {		//main street green manual button
			//set main street lights to green
			signal1.setGreen();
			signal3.setGreen();
		});

		mainStreetRedBt.setOnAction(e -> {		//main street red manual button
			//set main street lights to red
			signal1.setRed();
			signal3.setRed();
		});

		sideStreetGreenBt.setOnAction(e -> {		//side street green manual button
			//set side street lights to green
			signal2.setGreen();
			signal4.setGreen();
		});

		sideStreetRedBt.setOnAction(e -> {		//side street red manual button
			//set side street lights to red
			signal2.setRed();
			signal4.setRed();
		});

		/**bottom buttons listener*/
		pedestrianMainStreetBt.setOnAction(e -> {		//pedestrian crossing main street
			if (seconds < 14) {
				seconds = 23;
			}
		});

		pedestrianSideStreetBt.setOnAction(e -> {		//pedestrian crossing side street
			if (seconds < 14) {
				seconds = 19;
			}
		});
	}



	private void showAbout(){

		final String aboutText = "This stoplight simulator was created at great cost by Jared Bumgardner.\nThis simulator simulates a four-way stoplight that is tons of fun.\nFour lights are capable of being run in auto or manual mode and allows for pedestrian input. It also allows for malfunctions and all-lights-stop.";

		// Create the text label
		Label aboutLabel = new Label();
		aboutLabel.setWrapText(true);
		aboutLabel.setTextAlignment(TextAlignment.CENTER);
		aboutLabel.setFont(Font.font("Comic Sans MS", 14));
		aboutLabel.setText(aboutText);

		// Add the label to a StackPane
		StackPane pane = new StackPane();
		pane.getChildren().add(aboutLabel);

		// Create and display said the aforementioned pane in a new stage 	
		Scene scene = new Scene(pane, 550, 100);
		Stage stage = new Stage();
		stage.setScene(scene);
		stage.setTitle("About this program");
		stage.setResizable(false);
		stage.show();
	}


	public static void main(String[] args) {
		launch(args);
	}	
}