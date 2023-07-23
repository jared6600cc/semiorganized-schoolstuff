#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#define SENDBUFFSIZE 1024

using namespace std;

class Server{
	private:
		int serverSocket;
		sockaddr_in serverAddress;
		char serverMessage[256] = "HTTP/1.1 200 \r\n\r\n <html><body><h1>I love Bushraaa</h1></body></html>" ;;
		
	public:
		// Methods
		void sendJPGFile(char * sendMe, int outSocket){
			FILE *fp;
			char data[SENDBUFFSIZE] = {0};
			
			// Remove leading slash
			sendMe++;
			
			// Open and send
			fp = fopen(sendMe, "rb");
			if(fp == NULL){
				exit(-1);	// exit error
			} else {
				while(fgets(data, SENDBUFFSIZE, fp) != NULL){
					if(send(outSocket, data, sizeof(data), 0) == -1){
						cout << "ERROR sending file " << sendMe << endl;
					}
				bzero(data, SENDBUFFSIZE);
				}	
			}
			
		}
		
		string getFileContents(char * message){
			string line, outPut;
			char *indexString = "/";
			if(strcmp(message, indexString) == 0){
				message = "index.html";
			} else {
				// remove leading slash
				message++;
			}
			
			ifstream openedFile(message);
			if(openedFile.is_open()){
				while(getline(openedFile, line)){
					outPut.append(line);
				}
				openedFile.close();
			} else {
				cout << "Error opening file" << endl;
			}
			
			cout << "Exiting file io func" << endl;
			return outPut;
		}
		string getResource(char * message, int clientSocket){	// returns empty string if resource not found
			string resourceContents;
			char delim[] = " ";
			char *mPtr = strtok(message, delim);
			mPtr = strtok(NULL, delim);
			printf("getting %s now...\n", mPtr);
			if(strstr(mPtr, ".jpg")){
				sendJPGFile(mPtr, clientSocket);
				resourceContents = "jpg";
			} else{
				resourceContents = getFileContents(mPtr);
			}
			return resourceContents;
		}
		
		void parseHTTP(char * message, int clientSock){
			cout << "*Parsing!~*" << endl;
			cout << "*message = \n" << message << endl;
			// get first line
			char delim[] = "\r\n\r\n";
			int initialSize = strlen(message);
			char *mPtr = strtok(message, delim);
			printf("line[0] = %s\n", mPtr);
			char *isGetReq = NULL;
			isGetReq = strstr(mPtr, "GET");
			if(isGetReq){
				// define
				string notFound =  "HTTP/1.1 404 \r\n\r\n <html><body><h1>404: Page not found...</h1></body></html>";
				string wasFound =  "HTTP/1.1 200 \r\n\r\n ";
				// send resource if possible
				string sendingMessage = getResource(mPtr, clientSock);
				if(sendingMessage.empty()){
					sendingMessage = notFound;
				}else {
					sendingMessage = wasFound + sendingMessage;
					cout << "sending reply = \n" << sendingMessage << endl;
				}
				int sendResult;
				sendResult = send(clientSock, sendingMessage.c_str(), strlen(sendingMessage.c_str()), 0);
				if(sendResult < 0){		// Error checking
					exit(EXIT_FAILURE);
				}
			}
			// Get rest of request
			while(mPtr != NULL){
				//printf("***>   %s\n", mPtr);
				mPtr = strtok(NULL, delim);
			}
		}
		
		void run(){
			// assuming user termination using CTR-C
			while(true){
				// Accept new connection
				int clientSocket;
				clientSocket = accept(serverSocket, NULL, NULL);
				if(clientSocket < 0)	// Error checking
					throw new ServerException("Error accepting new connection");
					
				// Read from client & parse
				int n;
				char buffer[1024];
				bzero(buffer, 1024);
				n = read(clientSocket, buffer, sizeof(buffer));
				if(n < 0){	// Error checking
					throw new ServerException("Error reading from client socket");
				}
				if(strlen(buffer) == 0){
					cout << "Null received...doing nothing..." << endl;
				} else {
					parseHTTP(buffer, clientSocket);
				}
				
				// Reply to client
				//int sendResult;
				//sendResult = send(clientSocket, serverMessage, strlen(serverMessage), 0);
				//if(sendResult < 0){		// Error checking
				//	exit(EXIT_FAILURE);
				//}
				
				// Close connection
				close(clientSocket);
			}
			close(serverSocket);	// never executes (but good practice to include i think)
		}
		
		// Constructor(s)
		Server(int givenPort){
			// Create server socket
			serverSocket = socket(AF_INET, SOCK_STREAM, 0);
			if(serverSocket < 0)	// Error checking
				throw new ServerException("Error creating server socket");
				
			// Define server address
			serverAddress.sin_family = AF_INET;				// set address family
			serverAddress.sin_port = htons(givenPort);		// set service port
			serverAddress.sin_addr.s_addr = INADDR_ANY;		// set ip address
			
			// Bind the socket to the IP Address and Port
			int bindResult = bind(serverSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress));
			if(bindResult < 0)		// Error checking
				throw new ServerException("Error binding");

			// Listen for connections
			int listenResult = listen(serverSocket, 5);
			if(listenResult < 0)	// Error checking
				throw new ServerException("Error listening");
		}
};