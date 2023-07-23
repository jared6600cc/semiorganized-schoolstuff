#include <sys/socket.h>
#include <netinet/in.h>

class Socket{
	private:
		int serverFileDescriptor;
		struct sockaddr_in address;
	public:
		Socket();
		Socket(int portNo);
};