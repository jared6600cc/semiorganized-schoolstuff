#include <exception>

struct ServerException : public std::exception{
	const char * what () const throw (){
		return "Server Exception";
	}
};