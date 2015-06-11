#include "common.h"
#include <map>      //for std::map
#include <iterator>     //for std::ostream_iterator
#include <algorithm>    //for std::copy

typedef std::multiset<int> NUMBERLIST;

std::ostream& operator<<(std::ostream& o, const NUMBERLIST& factors)
{
	std::copy(factors.begin(), factors.end(), std::ostream_iterator<int>(o, " "));
	return o;
}

long getProduct(NUMBERLIST div)
{
	long prod = 1;
	NUMBERLIST::iterator it;
	for (it = div.begin(); it != div.end(); ++it)
	{
		prod *= *it;
	}
	return prod;
}

int main(int argc, char** argv)
{
	//std::cout << "Smallest Multiple" << std::endl;

	std::map<int, NUMBERLIST> primeFactors;

	for (int i = 2; i < 20; i++)
	{
		NUMBERLIST factors;
		getPrimeFactors(i, factors);
		primeFactors[i] = factors;
		//cout << i << " : " << factors << endl;
	}

	NUMBERLIST div;
	long product = 1;
	std::map<int, NUMBERLIST>::iterator itMap;
	for (itMap = primeFactors.begin(); itMap != primeFactors.end(); ++itMap)
	{
		int n = (*itMap).first;
		if (isPrime(n))
		{
			//cout << "Inserting prime :" << n << endl;
			div.insert(n);
			product = getProduct(div);
		}
		else
		{
			NUMBERLIST factors;
			getPrimeFactors(n, factors);
			NUMBERLIST::iterator it;
			//cout << "For non prime " << n << ", inserting prime ";
			for (it = factors.begin(); it != factors.end(); ++it)
			{
				if (product % n != 0)
				{
					//cout << *it << " ";
					div.insert(*it);
					product = getProduct(div);
				}
			}
			//cout << endl;
		}
	}

	std::cout << "Smallest Multiple equally divisible by all numbers 1-20 is : " << getProduct(div) << std::endl;
	std::cout << "Multiples are : " << div << endl;

	return 1;
}

