/* Jared Bumgardner
 * COP4635: Project 2
 * Due: 
 * HTTPClient.c
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
//#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#define BUFFERSIZE 1028



/* MAIN */
// Takes exactly 2 command line arguments: the server's IP Address & the port number the server is using for communication.
 int main(int argc, char *argv[]){
	 int socketfd, portNum;
	 char buff[BUFFERSIZE];					// User interaction buffer (filename to retrieve)
	 char * getRequest;						// GET Request string to send to server
	 struct sockaddr_in serverAddress;		// Server Address
	 struct hostent * server;				// Server Symbolic Name
	 
	 if(argc < 3){
		 // missing expected command line argument(s)
		 fprintf(stderr, "Please enter the server address and the file name: \nusage: ./client <ServerIpAddress> <PortNumber>");
		 exit(-1);
	 } else {
		 while(1){
			 // Expected command line arguments found
			 portNum = atoi(argv[2]);
			 socketfd = socket(AF_INET, SOCK_STREAM, 0);
			 if(socketfd < 0){
				 //Socket failed to open
				 fprintf(stderr, "Error: socket failed to open");
				 exit(-1);
			 } else {
				 //Socket created successfully
				 server = gethostbyname(argv[1]);
				 if(server == NULL){
					 // Server is not visible on the given IP/Port combo
					 fprintf(stderr, "Error: Specified host does not exist");
					 exit(-1);
				 } else {
					 // Server found
					 memset(&serverAddress, '0', sizeof(struct sockaddr_in));
					 serverAddress.sin_family = AF_INET;
					 bcopy((char *)server->h_addr, (char *)&serverAddress.sin_addr,server->h_length);
					 serverAddress.sin_port = htons(portNum);
					 serverAddress.sin_addr.s_addr = INADDR_ANY;
					 // Connect to remote socket
					 if(connect(socketfd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0){
						 // Report connection error
						 fprintf(stderr, "Error: Connecting to socket\nIs the server On?");
						 exit(-1);
					 } else {
						 printf("Successful connection to remote socket\n");
					 }
					 // Compose message to send
					 printf("Please enter file name to GET: ");
					 memset(&buff, '\0', BUFFERSIZE);
					 fgets(buff, BUFFERSIZE-1, stdin);
					 buff[strlen(buff)-1] = '\0'; // remove newline from filename
					 getRequest = (char *)malloc(BUFFERSIZE);
					 strcat(getRequest, "GET /");
					 strcat(getRequest, buff);
					 strcat(getRequest, " HTTP/1.1\n");
					 printf("\nSending request to server:\n%s", getRequest);
					 if((write(socketfd, getRequest, strlen(getRequest))) < 0){
						 // Data sending error
						 fprintf(stderr, "Error writing to socket");
						 exit(-1);
					 }
					 memset(&buff, '\0', BUFFERSIZE);
					 if((read(socketfd, buff, BUFFERSIZE)) < 0){
						 // Reading server data error
						 fprintf(stderr, "Error reading from socket");
						 exit(-1);
					 }
					 // Print message from server to console
					 printf("\nServer Replied:\n%s\n\n", buff);
				 }
			 }
		 }
	 }
	 // cleanup
	 free(getRequest);
	 close(socketfd);
	 return 0;
 }
