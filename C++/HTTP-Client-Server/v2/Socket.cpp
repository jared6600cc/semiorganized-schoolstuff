#include "Socket.h"
#include "ServerException.h"

Socket::Socket(){}
Socket::Socket(int portNo){
	if((serverFileDescriptor = socket(AF_INET, SOCK_STREAM, 0)) == 0){
		throw new ServerException();
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(portNo);
	memset(address.sin_zero, '\0', sizeof(address.sin_zero);
}