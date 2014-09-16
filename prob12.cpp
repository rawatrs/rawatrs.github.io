#include <iostream>
#include <sstream>
using namespace std;

#define MAX_FACTORS 500

/**
 * Returns number of factors for a given number
 * Algorithm Based On: if n = (p1^e1)*(p1^e2)*(p3^e3)*...
 * then no of factors = (e1+1)*(e2+1)*(e3+1)
 *
 * @returns no of factors
 */
int getNumOfFactors(long tNum)
{
	long initial_tNum = tNum;
	int nFactors = 1;
	int power = 0;

	for (int i = 2; i* i <= initial_tNum; i++)
	{
		power = 0;
		while (tNum % i == 0)
		{
			tNum = tNum / i;
			++power;
		}
		nFactors = nFactors * (power + 1);
	}

	if (tNum > 1)
	{
		nFactors = nFactors * 2;
	}

	return nFactors;
}

int main(int argc, char** argv)
{
	int num = 1;
	long triangleNum = 1;
	int nFactors = 0;

	while (1)
	{
		nFactors = getNumOfFactors(triangleNum);
		if (nFactors > MAX_FACTORS)
			break;

		triangleNum = triangleNum + ++num;
	}

	std::cout << "First triangular number with over " << MAX_FACTORS << " divisors is " << triangleNum << std::endl;

	return 1;
}

