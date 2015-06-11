#include "common.h"

bool isDivisibleBy5(long num)
{
	int lastDigit = num % 10;
	if (lastDigit == 0 || lastDigit == 5)
		return true;
	else
		return false;
}

bool isDivisibleBy3(long num)
{
	int sumOfAllDigits = 0;
	do
	{
		int digit = num % 10;
		sumOfAllDigits += digit;
		num = num / 10;
	}
	while (num > 0);

	if (sumOfAllDigits % 3 == 0)
		return true;
	else
		return false;
}

unsigned long getSumOfPrimeNumbersUpto(int limit)
{
	unsigned long sum = 17;
	int num = 11;
	for (;;)
	{
		if (!isDivisibleBy3(num) && !isDivisibleBy5(num))
		{
			if (isPrime(num))
			{
				if (num > limit)
				{
					return sum;
				}
				else
				{
					//std::cout << num << std::endl;
					sum += num;
				}
			}
		}
		num += 2;
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

