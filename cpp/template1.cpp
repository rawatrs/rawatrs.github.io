#include <iostream>
#include <sstream>
#define TRUE 1
#define FALSE 0
using namespace std;

int main(int argc, char **argv)
{
	std::cout << "" << std::endl;

	int value = 0;
	if (argc == 1)
	{
		value = 4000000;
	}
	else if (argc >= 2)
	{
		istringstream iss(argv[1]);
		if (!(iss >> value))
		{
			std::cout << "Invalid number, assuming value 4 million" << std::endl;
			value = 4000000;
		}
	}
	
	return 1;
}

