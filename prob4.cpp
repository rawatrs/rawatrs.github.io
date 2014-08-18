#include "common.h"
#include <utility>

int isPalindrome(string ss)
{
	int n = ss.length();

	for (int i = 0; i < (n / 2) + 1; ++i)
	{
		if (ss[i] != ss[n - i - 1])
		{
			return FALSE;
		}
	}
	return TRUE;
}

int isPrime(int number, std::pair<int, int>& factors)
{
	int flag = TRUE;
	for (int i = 2; i < number / 2; ++i)
	{
		if (number % i == 0)
		{
			factors = std::make_pair(i, (number / i));
			flag = FALSE; //oops, not prime
			break;
		}
	}

	return flag;
}

int is3Digit(int number)
{
	return ((number > 99) && (number < 1000));
}

int main(int argc, char** argv)
{
	std::cout << "Largest palindrome product" << std::endl;
	std::cout << "--------------------------" << std::endl;

	int largest3DigitProduct = 999 * 999;
	int largest2DigitProduct = 99 * 99;
	int largestPrimeNumber = 0;

	std::pair<int, int> factors;
	for (int num = largest3DigitProduct; num > largest2DigitProduct; num--)
	{
		string ss(numberToString(num));
		if (isPalindrome(ss))
		{
			//cout << ss << ':' << num << endl;
			if (!isPrime(num, factors))
			{
				if (is3Digit(factors.first) && is3Digit(factors.second))
				{
					largestPrimeNumber = num;
					break;
				}
			}
		}
	}


	std::cout << "Largest palindrome product of two 3 digit numbers is :" << largestPrimeNumber << std::endl;
	std::cout << "The factors are: " << factors.first << ", " << factors.second << endl;

	return 1;
}

