#ifndef COLLATZ_HPP
#define COLLATZ_HPP

#include "histogram.hpp"
#include <iostream>
#include <vector>

class Collatz
{
	private:
		std::vector<long> seq;
		int stoppingTime;

		long f(long n);
	public:
		Collatz();

		std::vector<long> getCollatzSeq();
		void createCollatzSeq(long n);
		int getStoppingTime();
};



#endif
