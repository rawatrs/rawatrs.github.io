#include "common.h"

int main(int argc, char** argv)
{
	int limit = 0;
	if (argc == 1)
	{
		limit = 10001;
	}
	else if (argc >= 2)
	{
		istringstream iss(argv[1]);
		if (!(iss >> limit))
		{
			std::cout << "Invalid number, assuming limit 10001" << std::endl;
			limit = 10001;
		}
	}

	int no = 2;
	int flag = TRUE;
	int primeth = 0;
	long primeNumber = 1;
	while (flag)
	{
		if (isPrime(no))
		{
			++primeth;
			if (primeth == limit)
			{
				primeNumber = no;
				flag = FALSE; break;
			}
		}
		++no;
	}
	std::cout << limit << "th prime number is " << primeNumber << std::endl;

	return 1;
}

