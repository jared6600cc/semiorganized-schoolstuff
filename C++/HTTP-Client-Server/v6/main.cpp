// Intro


using namespace std;
// Pre-processor
#include <cstdlib>
#include <iostream>
#include "HTTPServer.hpp"


// Port Values
#define LOWEST_PORT 60001
#define HIGHEST_PORT 65000		// TODO: Change this value

int processCommandLineArguments(int argc, char **argv){
	int useThisPort;
	
	if(argc == 2){
		cout << "Custom port : ";
		cout << argv[1] << endl;
		if((atoi(argv[1]) < LOWEST_PORT)||(atoi(argv[1]) > HIGHEST_PORT)){
			cout << "Error : Port num out of bounds (low = " << LOWEST_PORT << ", high = " << HIGHEST_PORT << ")" << endl;
			cout << "Defaulting to " << LOWEST_PORT << endl;
			useThisPort = LOWEST_PORT;
		} else {
			useThisPort = atoi(argv[1]);
		}
	} else {
		cout << "Default port : ";
		cout << LOWEST_PORT << endl;
		useThisPort = LOWEST_PORT;
	}
	
	return useThisPort;
}

/* Main */
// Takes exactly 1 command line argument: a custom port number. If custom port number is invalid, default to lowest defined port.
int main(int argc, char** argv) {
	
	// Define port
	int chosenPort = processCommandLineArguments(argc, argv);
	
	// Try to create a running http server. Exit if failure.
	try{
		HTTPServer s = HTTPServer(chosenPort);
		s.run();
	} catch (exception const&e){
		// Report failure & exit abnormally...
		cerr << e.what() << endl;
		exit(EXIT_FAILURE);
	}
	
	return 0;
}