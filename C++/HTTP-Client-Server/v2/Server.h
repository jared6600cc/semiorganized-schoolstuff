#include "Socket.h"

class Server{
	private:
		Socket inSocket;
		
	public:
		void run();
		Server(int givenPort);
};