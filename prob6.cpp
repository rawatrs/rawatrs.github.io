#include <iostream>
#include <sstream>
#define TRUE 1
#define FALSE 0
using namespace std;

int main(int argc, char** argv)
{
	std::cout << "Sum square difference" << std::endl;

	int value = 0;
	if (argc == 1)
	{
		value = 100;
	}
	else if (argc >= 2)
	{
		istringstream iss(argv[1]);
		if (!(iss >> value))
		{
			std::cout << "Invalid number, assuming value 100" << std::endl;
			value = 100;
		}
	}

	long sumOfSquare = 0; // 1*2 + 2*2 + .... + 10*2 = 385
	long long squareOfSum = 0; // (1+2+ ..+10)*2 = 55*2 = 3025

	sumOfSquare = (value * (value + 1) * (2 * value + 1)) / 6;
	long sums = (value * (value + 1)) / 2;
	squareOfSum = sums * sums;
	long long diff = (squareOfSum > sumOfSquare) ? (squareOfSum - sumOfSquare) : (sumOfSquare - squareOfSum);

	std::cout << "Sum of square of first " << value << " natural numbers : " << sumOfSquare << std::endl;
	std::cout << "Square of sum of first " << value << " natural numbers : " << squareOfSum << std::endl;
	std::cout << "Sum square difference of first " << value << " natural numbers : " << diff << std::endl;

	return 1;
}

