#include "common.h"
#include <set>

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

