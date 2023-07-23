/* Jared Bumgardner
 * COP4635: Project 3 (Pt. 1)
 * TCPServer.cpp: Contains TCP Server Logic/Class as well as Weather Application
 * Due: 18 April 2023
 */

#define LOWEST_PORT 60001
#define HIGHEST_PORT 60099
#define MAXCONNECTS 128
#define BUFFSIZE 1024
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

int processCommandLineArguments(int argc, char** argv){
	int usingPort = -1;
	if(argc == 2){
		/* CUSTOM PORT NUMBER PROVIDED */
		cout << "Using Custom Port: " << argv[1] << endl;
		if((atoi(argv[1]) < LOWEST_PORT)||(atoi(argv[1]) > HIGHEST_PORT)){
			/* Provided port number is out of bounds */
			cout << "Error: PortNum out of bounds (low= " << LOWEST_PORT << ", high= " << HIGHEST_PORT << ")" << endl;
			cout << "Defaulting to " << LOWEST_PORT << endl;
			usingPort = LOWEST_PORT;
		} else {
			/* Provided port number is within bounds */
			usingPort = atoi(argv[1]);
		}
	} else {
		/* CUSTOM PORT NOT PROVIDED */
		cout << "Using Default Port: " << LOWEST_PORT << endl;
		usingPort = LOWEST_PORT;
	}
	return usingPort;
}

/*
void sendData(string sendMe, int currSocket){
	send(currSocket, sendMe.c_str(), strlen(sendMe.c_str()), 0);
}

string receiveData(int currSocket){
	char inBuffer[BUFFSIZE] = {0};
	read(currSocket, inBuffer, BUFFSIZE);
	cout << inBuffer << endl;
	return string(inBuffer);
}*/


class WeatherApp{
	public:
		string welcomeMssg = "\nWelcome to the Weather Application";
		int currClient;
		char inBuffer[BUFFSIZE] = {0};

		void login(){}
		void registerAcct(){}

		void quitApp(){
			cout << currClient << " disconnected." << endl;
			send(currClient, "Bye!\n", strlen("Bye!\n"), 0);
			if(shutdown(currClient, SHUT_RDWR) != 0){
				cout << "Error closing client # " << currClient << endl;
			}
			kill(currClient, SIGKILL);
		}

		void run(){
			send(currClient, welcomeMssg.c_str(), strlen(welcomeMssg.c_str()), 0);
			while(true){
				string frontpageOptions = "\n[1] Login\n[2] Register\n[3] Quit Application";
				send(currClient, frontpageOptions.c_str(), strlen(frontpageOptions.c_str()), 0);
				read(currClient, inBuffer, BUFFSIZE);

				if(atoi(inBuffer) == 3){
					quitApp();
				}
			}
		}

		WeatherApp(int c){
			currClient = c;
		}
};

class TCPServer{
	public:
		int serverFD;
		struct sockaddr_in serverAddress;
		int serverAddressLen = sizeof(serverAddress);
		char inBuffer[BUFFSIZE];

		void run(){
			while(true){
				// Accept new connection
				int clientSocket;
				if((clientSocket = accept(serverFD, (struct sockaddr*)&serverAddress, (socklen_t*)&serverAddressLen)) < 0){
					cout << "ERROR accepting new connection." << endl;
					exit(EXIT_FAILURE);
				} else {
					cout << clientSocket << " connected." << endl;
					pid_t pID = fork();
					if(pID == -1){
						cout << "ERROR forking process for new connection." << endl;
						exit(EXIT_FAILURE);
					} else if(pID > 0){
						// parent
						continue;
					} else {
						WeatherApp wa = WeatherApp(clientSocket);
						wa.run();
					}
				}
			}
		}

		TCPServer(int givenPort){
			// Create server side socket
			if((serverFD = socket(AF_INET, SOCK_STREAM, 0)) < 0){
				cout << "ERROR creating server socket." << endl;
				exit(EXIT_FAILURE);
			}

			serverAddress.sin_family = AF_INET;				// set address family
			serverAddress.sin_port = htons(givenPort);		// set service port
			serverAddress.sin_addr.s_addr = INADDR_ANY;		// set ip address

			// Binding
			int bindResult = bind(serverFD, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
			if(bindResult < 0){
				cout << "ERROR binding server socket." << endl;
				exit(EXIT_FAILURE);
			}

			// Listening
			if(listen(serverFD, MAXCONNECTS) < 0){
				cout << "ERROR while listening." << endl;
				exit(EXIT_FAILURE);
			}
		}
};

int main(int argc, char** argv){
	// Define port
	int chosenPort = processCommandLineArguments(argc, argv);

	// Start weather application
	TCPServer s = TCPServer(chosenPort);
	s.run();

    return 0;
}
