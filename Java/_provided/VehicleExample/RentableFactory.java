import java.util.Random;

public class RentableFactory {
	public static Rentable create(String purpose) {
		// Initializations
		Rentable obj = null;
		Random rng = new Random();
		int rngChoice = rng.nextInt(Integer.MAX_VALUE);
		String purposeLC = purpose.toLowerCase();

		// Set return obj
		if(purposeLC.contentEquals("fly by night")) {
			obj = new Broom();
		} else if(purposeLC.contentEquals("slide on snow")) {
			obj = new Sleigh();
		} else if(purposeLC.contentEquals("fly by day")) {
			obj = new Carpet();			
		} else if(purposeLC.contentEquals("ride downstream")) {
			obj = new LargeLog();
		} else if(purposeLC.contentEquals("heel around")) {
			obj = new Heelys();
		} else if(purposeLC.contentEquals("ride on water")) {
			rngChoice = rngChoice % 2;
			switch(rngChoice) {
			case 0:
				obj = new TrackerPro();
				break;
			case 1:
				obj = new Carver500();
				break;
			}
		} else if(purposeLC.contentEquals("ride slowly")) {
			rngChoice = rngChoice % 2;
			switch(rngChoice) {
			case 0:
				obj = new MarinRift();
				break;
			case 1:
				obj = new TommasoImola();
				break;
			}
		} else if(purposeLC.contentEquals("racing")) {
			rngChoice = rngChoice % 3;
			switch(rngChoice) {
			case 0:
				obj = new Ferrari488();
				break;
			case 1:
				obj = new BugattiVeyron();
				break;
			case 2:
				obj = new Porsche911();
				break;
			}
		} else if(purposeLC.contentEquals("family vehicle")) {
			rngChoice = rngChoice % 2;
			switch(rngChoice) {
			case 0:
				obj = new ToyotaHighlander();
				break;
			case 1:
				obj = new FordEscape();
				break;
			}
		} else if(purposeLC.contentEquals("inner city ride")) {
			rngChoice = rngChoice % 2;
			switch(rngChoice) {
			case 0:
				obj = new KiaRio();
				break;
			case 1:
				obj = new ChevroletVolt();
				break;
			}
		} else if(purposeLC.contentEquals("transporting stuff")) {
			rngChoice = rngChoice % 2;
			switch(rngChoice) {
			case 0:
				obj = new FordF150();
				break;
			case 1:
				obj = new GMCSierra();
				break;
			}
		} else if(purposeLC.contentEquals("smooth ride")) {
			rngChoice = rngChoice % 2;
			switch(rngChoice) {
			case 0:
				obj = new CadillacATS();
				break;
			case 1:
				obj = new AudiA8();
				break;
			}
		} else {
			obj = null;
		}
		return obj;
	}
}
