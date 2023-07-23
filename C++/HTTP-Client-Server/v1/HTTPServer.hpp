/* Jared Bumgardner
 * COP4635: Project 1
 * Due: Sun 12Feb2023
 * HTTPServer.hpp : Contains httpRequest struct & HTTPServer class declaractions.
 */
 
 
 using namespace std;
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#define SOCKETBUFFSIZE 1024
#define MAXIMAGESIZEBYTES 5000000
#define NOTFOUNDMESSAGE "HTTP/1.1 404 \r\n\r\n <html><body><h1>404: Page not found...</h1></body></html>"


// Struct to represent 3 components of an httpMessage.
struct httpRequest{
	string requestLine;
	vector<string> headers;
	vector<string> message;
};


// Server that serves HTTP requests
class HTTPServer{
	private:
		int usingPortNo;		// Port number the server is listening on
		int serverSocket;		// Reference to the serverSocket
		sockaddr_in serverAddress;
		
	public:
		// Methods
		// send jpg fileToServe to clientSocket
		void serveJPG(int clientSocket, string fileToServe){	//NOTE TO GRADER: I cant get any single image to send.
			cout << "Serving jpg" << endl;
			string firstLine = "HTTP/1.1 200 OK\r\n";
			string contentTypeHeader = "Content-Type: image/jpg\r\n";
			string contentLengthHeader = "Content-Length: ";
			
			// read in image file
			ifstream stream;
			stream.open(fileToServe, ifstream::binary);
			if(stream.is_open()){
				char * buffer = new char[MAXIMAGESIZEBYTES];
				*buffer = {0};
				stream.read(buffer, sizeof(char)*MAXIMAGESIZEBYTES);
				int intImageSize = (int)stream.gcount();
				
				// construct & send headers
				string serverResponse;
				serverResponse = firstLine + contentTypeHeader;
				serverResponse += contentLengthHeader;
				serverResponse += to_string(intImageSize);
				serverResponse += "\r\n\r\n";
				cout<<serverResponse;
				
				// send headers then send file
				int sendResult;
				sendResult = send(clientSocket, serverResponse.c_str(), strlen(serverResponse.c_str()), 0);
				if(sendResult < 0){
					cout << "Error sending jpg file headers while serving to client..." << endl;
					exit(-1);
				}
				sendResult = send(clientSocket, buffer, strlen(buffer), 0);
				if(sendResult < 0){
					cout << "Error sending jpg data while serving to client..." << endl;
					exit(-1);
				}
				
				// cleanup area
				stream.close();
				delete buffer;
				buffer = nullptr;//.
			}
		}
			
		
		// send html fileToServe to clientSocket
		void serveHTML(int clientSocket, string fileToServe){
			cout << "Serving html" << endl;
			string line, inData, response;
			ifstream inFile(fileToServe);
			if(inFile.is_open()){
				while(getline(inFile, line)){
					inData.append(line);
				}
				response = "HTTP/1.1 200 \r\n\r\n " + inData;
				inFile.close();
			} else {
				cout << "Error opening html file while serving to client..." << endl;
				response = NOTFOUNDMESSAGE;
			}
			
			
			// send to client
			int sendResult;
			sendResult = send(clientSocket, response.c_str(), strlen(response.c_str()), 0);
			if(sendResult < 0)
				throw runtime_error("Error sending file to client.\n");	
			cout << "HMTL served successfully." << endl;
		}
		
		
		// respond to parsedRequest through clientSocket
		void reply(int clientSocket, httpRequest parsedRequest){
			// Serve index.html by default
			char * req = &parsedRequest.requestLine[0];
			cout << "request: " << req << endl;	//debug
			char * indexString = "/";
			char * mPtr = strtok(req, " ");
			mPtr = strtok(NULL, " ");
			char * fileToServe;
			if(strcmp(mPtr, indexString) == 0){
				fileToServe = "index.html";
			} else {
				// Remove leading slash
				mPtr++;
				fileToServe = mPtr;
			}
			
			cout << "Getting " << fileToServe << endl;
			// Read in file
			if(strstr(fileToServe, ".html") != NULL)
				serveHTML(clientSocket, fileToServe);
			else if(strstr(fileToServe, ".jpg") != NULL){
				serveJPG(clientSocket, fileToServe);
			} else {
				cout << "Failed to serve nonHTML file" << endl;
			}
		}
		
		
		// parse buf from clientSock into httpRequest struct
		httpRequest parse(string buf, int clientSock){
			httpRequest hr;
			// Get request line
			stringstream checkA(buf);
			string intermediate;
			getline(checkA, intermediate, '\n');
			hr.requestLine = intermediate;
			
			// Get request headers
			while(getline(checkA, intermediate, '\n')){
				if(intermediate.empty()){
					continue;
				} else {
					hr.headers.push_back(intermediate);
				}
			}
			
			// Get body/message
			while(checkA.peek() != EOF){
				getline(checkA, intermediate);
				hr.message.push_back(intermediate);
			}
		return hr;
		}
		
		
		// Assume external termination
		void run(){
			cout << "Server listening & waiting for client request" << endl;
			while(true){
				// Accept new connection
				int clientSocket = accept(serverSocket, NULL, NULL);
				if(clientSocket < 0)
					throw runtime_error("Error accepting new connection.");
				cout << "" << endl;
				
				// Read from client
				char buffer[SOCKETBUFFSIZE];
				bzero(buffer, SOCKETBUFFSIZE);
				ssize_t n = read(clientSocket, buffer, sizeof(buffer));
				if(n < 0)
					throw runtime_error("Error reading from client socket.");
				
				// Parse
				httpRequest parsedRequest;
				if(strlen(buffer) == 0){
					cout << "Null received from client." << endl;	// Todo: delete this?
					close(clientSocket);
					continue;
				} else {
					parsedRequest = parse(string(buffer), clientSocket);
				}
				
				// Reply to client & end connection
				reply(clientSocket, parsedRequest);
				close(clientSocket);
			}
			// Never executes assuming outside termination
			close(serverSocket);
		}
		
		
		// Constructor(s)
		HTTPServer(int givenPort){
			cout << "Server started" << endl;
			// Create server socket
			usingPortNo = givenPort;
			serverSocket = socket(AF_INET, SOCK_STREAM, 0);
			if(serverSocket < 0)
				throw runtime_error("Failed to create server-side socket.");
			
			// Define server address
			serverAddress.sin_family = AF_INET;				// set address family
			serverAddress.sin_port = htons(usingPortNo);	// set service port
			serverAddress.sin_addr.s_addr = INADDR_ANY;		// set ip address
			
			// Bind the socket to the IP Address & port
			int bindResult = bind(serverSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress));
			if(bindResult < 0)
				throw runtime_error("Failed to bind socket to ip address & port.");
			
			cout << "Server Ready" << endl;
			// Listen for connections
			int listenResult = listen(serverSocket, 100);
			if(listenResult < 0)
				throw runtime_error("Error occured while listening.");
			
		}
};