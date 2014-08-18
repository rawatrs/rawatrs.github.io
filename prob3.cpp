#include "common.h"
#include <set>

void getPrimeFactors(long number, std::set<int>& factors)
{
	int div = 2;
	while (number != 0)
	{
		if (number % div != 0)
		{
			div = div + 1;
		}
		else
		{
			number = (number / div);
			factors.insert(div);
			if (number == 1)
				break;
		}
	}
}

int main(int argc, char** argv)
{
	std::cout << "" << std::endl;

	long value = 0;
	if (argc == 1)
	{
		value = 600851475143;
	}
	else if (argc >= 2)
	{
		istringstream iss(argv[1]);
		if (!(iss >> value))
		{
			std::cout << "Invalid number, assuming value 600851475143" << std::endl;
			value = 600851475143;
		}
	}

	std::set<int> factors;
	getPrimeFactors(value, factors);
	cout << "Prime factors of the number " << value << " are : " << endl;
	std::set<int>::iterator it;
	for (it = factors.begin(); it != factors.end(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;
	cout << "Largest prime factor of the number " << value << " is : " << *factors.rbegin() << endl;

	return 1;
}

