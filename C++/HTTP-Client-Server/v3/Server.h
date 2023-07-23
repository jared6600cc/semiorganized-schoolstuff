class Socket {
	private:
		int p;
		int socketFileDescriptor;
	public:
		Socket(int port){
			p = port;
		}
};

class serverSocket : public Socket {
};

class clientSocket : public Socket {
	
};

class Server {
	private:
		serverSocket inSock;
	public:
		void run(){}
		Server(int port){
			inSock = serverSocket(port);
		}
};