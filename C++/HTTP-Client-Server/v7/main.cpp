// Intro


using namespace std;
// Pre-processor
#include <stdlib.h>					// exit, EXIT_FAILURE
#include "ServerException.hpp"		// Custom ServerException struct
#include "Server.hpp"				// Custom Server class


#define PORT 60001					// low= & high=


/* Main */
int main() {		// TODO: Add command line arg for variable ports
	// Try to create a running server; exit if error.
	try{
		Server s = Server(PORT);
		s.run();
	}catch(exception &e){
		// Exiting abnormally..
		cout << e.what() << endl;	// TODO: Change this
		exit(EXIT_FAILURE);
	}
	
	return 0;
}