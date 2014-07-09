#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char * argv[])
{
	int total = 1000;
	if (argc >= 2)
	{
		total = atoi(argv[1]);
	}

	long sum = 0;
	for (int i = 1; i < total; i++)
	{
		if (i%15 == 0)
		{
			sum += i;
		}
		else if (i%3 == 0)
		{
			sum += i;	
		}
		else if (i%5 == 0)
		{
			sum += i;	
		}
	}

	std::cout << "Sum of all multiples of 3 & 5 below " << total << " = " << sum << std::endl;

	return 1;
}


