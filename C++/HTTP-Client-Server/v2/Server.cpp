#include "Server.h"
#include "ServerException.h"

#include <iostream>
using namespace std;

void Server::run(){
	// Wait for new connections forever
}

Server::Server(int givenPort){
	try{
		inSocket = Socket(givenPort);
		
	}
	catch (ServerException& e) {
		 cout << "Error creating ...exiting...\n";
		 exit(EXIT_FAILURE);
	 }
}