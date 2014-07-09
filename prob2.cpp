#include <iostream>
#include <sstream>
#define TRUE 1
#define FALSE 0
using namespace std;

int main(int argc, char **argv)
{
	std::cout << "" << std::endl;	
	
	int x = 1;
	int y = 2;
	int z = 0;
	int largest = 0;
	int sum = 2;
	int apple;
	int toBreak = FALSE;

	if (argc == 1)
	{
		largest = 4000000;
	}
	else if (argc >= 2)
	{
		istringstream iss(argv[1]);
		if (!(iss >> largest))
		{
			std::cout << "Invalid number, assuming largest 4 million" << std::endl;
			largest = 4000000;
		}	
	}
	
	while (!toBreak)
	{
		z = x + y;
		x = y;
		y = z;
		
		if (z > largest)
		{
			toBreak = TRUE;
		}
		else if (z%2 == 0)
		{
			sum += z;
		} 
	}
	std::cout << "Sum of fibonacci sequence even numbers below " << largest << " = " << sum << std::endl;	

	return 1;
}
