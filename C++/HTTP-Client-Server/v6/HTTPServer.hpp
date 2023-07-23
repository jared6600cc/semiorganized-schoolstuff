#include <vector>
#include <fstream>
#include <cstring>
#include <sstream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
using namespace std;

class UNIX_Socket{
	private:
	public:
		// Fields
		int id;
		sockaddr_in address;
		// Methods
		// Constructor(s)
		UNIX_Socket(int portNo){
			id = socket(AF_INET, SOCK_STREAM, 0);
			if(id < 0)
				throw runtime_error("Failed to create server-side socket.");
			
			// Define server address
			address.sin_family = AF_INET;				// set address family
			address.sin_port = htons(portNo);	// set service port
			address.sin_addr.s_addr = INADDR_ANY;		// set ip address
			
		}
};

class HTTPServer{
	private:		
	public:
		// Fields
		// Methods
		void run(){
			while(true){
				// Accept new connection
				// Read from client
				// Reply to client
				// End connection
				
			}
		}
		
		// Constructor(s)
		HTTPServer(int portNo){
			// Create server socket
			UNIX_Socket serverSock(portNo);			
			
			// Bind the socket to the IP Address & port
			if(bind(serverSock.id, (struct sockaddr*) &serverSock.address, sizeof(serverSock.address)) < 0)
				throw runtime_error("Failed to bind socket to ip address & port.");
			
			// Listen for connections
			if((listen(serverSock.id, 100)) < 0)
				throw runtime_error("Error occured while listening.");
		}
};