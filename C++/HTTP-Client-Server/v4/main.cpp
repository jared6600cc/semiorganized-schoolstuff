 //TCP Server (tcpServer3.c)

 
#include <stdio.h>          //Standard library
#include <stdlib.h>         //Standard library
#include <sys/socket.h>     //API and definitions for the sockets
#include <sys/types.h>      //more definitions
#include <netinet/in.h>     //Structures to store address information
#include <unistd.h>
#include <fstream>
#include <sstream>


int main() {
    char tcp_server_message[256] = "HTTP/1.1 200 \r\n\r\n <html><body><h1>Hello buddy</h1></body></html>";
	int tcp_server_socket = -1;
	tcp_server_socket = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in tcp_server_address;
	tcp_server_address.sin_family = AF_INET;
	tcp_server_address.sin_port = htons(60001);
	tcp_server_address.sin_addr.s_addr = INADDR_ANY;	// conect to 0.0.0.0
	bind(tcp_server_socket, (struct sockaddr *) &tcp_server_address, sizeof(tcp_server_address));
	listen(tcp_server_socket, 1);
	
	while(true){
		int tcp_client_socket = -1;
		tcp_client_socket = accept(tcp_client_socket, NULL, NULL);
			printf("tcp_client_socket = %d\n", tcp_client_socket);
		send(tcp_client_socket, tcp_server_message, sizeof(tcp_server_message), 0);	// Make this send a file?
		close(tcp_server_socket);
	}
	
	
    return 0;
}