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

int main(int argc, char** argv)
{
	std::cout << "Largest palindrome product" << std::endl;
	std::cout << "--------------------------" << std::endl;

	int result = 0;
	int product = 0;
	std::pair<int, int> factors;
	for (int i = 999; i > 99; --i)
	{
		for (int j = 999; j > 99; --j)
		{
			product = i * j;
			if (isPalindrome(numberToString(product)))
			{
				if (product > result)
				{
					result = product;
					factors = std::make_pair(i, j);
				}
			}
		}
	}

	std::cout << "Largest palindrome product of two 3 digit numbers is :" << result << std::endl;
	std::cout << "The factors are: " << factors.first << ", " << factors.second << endl;

	return 1;
}

