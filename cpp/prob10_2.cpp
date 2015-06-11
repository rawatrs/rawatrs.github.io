#include <iostream>
#include <sstream>
#include <vector>
//#include <iterator>
//#include <algorithm>

using namespace std;

//Uses sieve of eratosthenes algorithm for marking primes
unsigned long getSumOfPrimeNumbersUpto(int limit)
{
	std::vector<int> primes;

	for (int i = 2; i < limit; i++)
	{
		primes.push_back(i);
	}

	for (int i = 0; i < primes.size(); i++)
	{
		int v = primes[i];

		if (v != 0)
		{
			//mark all multiples of v, excluding v itself, as '0'
			int x = i + v;
			while (x < primes.size())
			{
				primes[x] = 0;
				x = x + v;
			}
		}
	}

	//std::copy(primes.begin(), primes.end(), std::ostream_iterator<int>(std::cout, "\n"));

	unsigned long sum = 0;
	for (int i = 0; i < primes.size(); i++)
	{
		//the remaining numbers which are not marked as 0 are primes
		if (primes[i] != 0)
			sum += primes[i];
	}

	return sum;
}

int main(int argc, char** argv)
{
	std::cout << "" << std::endl;

	int limit = 0;
	if (argc == 1)
	{
		limit = 2000000;
	}
	else if (argc >= 2)
	{
		istringstream iss(argv[1]);
		if (!(iss >> limit))
		{
			std::cout << "Invalid number, assuming limit 2 million" << std::endl;
			limit = 2000000;
		}
	}

	unsigned long sum = getSumOfPrimeNumbersUpto(limit);
	std::cout << "Sum of first 2 million prime numbers is " << sum << std::endl;
	return 1;
}

