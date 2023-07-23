#include <exception>
#include <string>

// TODO: Change everything in this
struct ServerException : public std::exception{
	public:
	std::string reason;
	ServerException(string message){
		this->reason = message;
	}
};
