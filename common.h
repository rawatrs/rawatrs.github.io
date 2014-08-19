#include <iostream>
#include <sstream>
#include <string>
#include <set>
using namespace std;

#define TRUE 1
#define FALSE 0

template<typename T>
string numberToString(T number)
{
	ostringstream ss;
	ss << number;
	return ss.str();
}


template<typename T>
T stringToNumber(const string& text)
{
	istringstream ss(text);
	T result;
	return ss >> result ? result : 0;
}

template<typename T, typename S>
void getPrimeFactors(T number, S& factors)
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

template<typename T>
int isPrime(T number)
{
	int flag = TRUE;
	for (T i = 2; i <= (number / 2); ++i)
	{
		if (number % i == 0)
		{
			flag = FALSE; break;
		}
	}
	return flag;
}

template<typename T, typename S>
void getAllPrimeNumbers(T number, S& factors)
{
	for (T i = 1; i <= number; ++i)
	{
		if (isPrime(i))
		{
			factors.insert(i);
		}
	}
}
