import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Date;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.stage.FileChooser;
import javafx.stage.FileChooser.ExtensionFilter;
import javafx.stage.Stage;


public class LinesOfCodeCounter extends Application {

	@Override
	public void start(Stage arg0) throws Exception {
		FileChooser fileChooser = new FileChooser();
		fileChooser.setTitle("Open Resource File");
		fileChooser.getExtensionFilters().add(
				new ExtensionFilter("Java Source Files", "*.java"));
		File selectedFile = fileChooser.showOpenDialog(arg0);

		BufferedReader input;
		try {
			input = new BufferedReader(new FileReader(selectedFile));
		} catch (FileNotFoundException e) {
			System.out.println("File not found.");
			throw new Exception("404");
		}

		int linesOfCode = 0;
		String line;

		//Check for brackets, whitespace, or commentsS
		while ((line = input.readLine()) != null) {
			line = line.trim();

			if(!(line.equals("}") || line.equals("")) || line.startsWith("//") || line.startsWith("/*") || line.startsWith("*")) {
				//It's code
				linesOfCode++;
			}
		}

		//close input scanner
		input.close();

		//create a writer to write to the file
		File outputFile = new File("LinesOfCode.txt");
		outputFile.createNewFile();
		BufferedWriter output = new BufferedWriter(new FileWriter(outputFile, true));

		//write the data
		output.write(String.format("[%s] %s: %d LOC\n", new Date().toString(), selectedFile.getName(), linesOfCode));

		//close the writer
		output.close();

		Platform.exit();
	}

	public static void main(String[] args) {
		launch("");
	}
}
