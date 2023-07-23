#include "collatz.hpp"

std::vector<long> Collatz::getCollatzSeq()
{
	return seq;
}
void Collatz::createCollatzSeq(long n)
{
	int i=0;
	// reset member fields to calculate a new sequence
	seq.clear();
	stoppingTime = -1;

	seq.push_back(n);
	while (n != 1)
	{
		n = f(n);
		i++;
		seq.push_back(n);
	}

	stoppingTime = i;
}
long Collatz::f(long n)
{
	if ((n % 2) == 1) // n is odd
	{
		return 3*n + 1;
	}
	else
	{
		return n / 2;
	}
}

Collatz::Collatz()
{
	stoppingTime = 0;
}

int Collatz::getStoppingTime()
{
	return stoppingTime;
}
