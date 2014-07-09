#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
	int total = 0;
	if (argc == 1)
	{
		total = 1000;
	}
	else if (argc >= 2)
	{
		istringstream iss(argv[1]);
		if (!(iss >> total))
		{
			std::cout << "Invalid number, assuming total 1000" << std::endl;
			total = 1000;
		}
	}

	long sum = 0;
	for (int i = 0; i < total; i++)
	{
		i += 3;
		sum += i;
	}
	for (int i = 0 ; i < total; i++)
	{
		i += 5;
		sum += i;
	}

	for (int i = 0; i < total; i++)
	{
		i += 15;
		sum -= i;
	}

	std::cout << "Sum of all multiples of 3 & 5 below " << total << " = " << sum << std::endl;

	return 1;
}


