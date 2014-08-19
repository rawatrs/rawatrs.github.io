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

template<typename T>
void getPrimeFactors(T number, std::set<int>& factors)
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

