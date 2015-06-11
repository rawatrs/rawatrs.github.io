#include <iostream>

int main(int argc, char** argv)
{
	//std::cout << "Special Pythagorean triplet" << std::endl;
	// a^2 + b^2 = c^2 , find a*b*c, where a+b+c = 1000

	unsigned long constNum = 5 * 100000;
	int a;
	int b;
	for (a = 1; a < 1000; a++)
	{
		for (b = 1; b < 1000; b++)
		{
			//got this after I reduced the equation a^2 + b^2 = (1000-a-b)^2
			unsigned long lhs = 1000 * (a + b);
			unsigned long rhs = (constNum + a * b);
			if (lhs == rhs)
			{
				goto stop;
			}
		}
	}

stop:
	std::cout << "Special Pythagorean triplet is : " << a << " , " << b << " , " << 1000 - a - b << std::endl;
	std::cout << "Special Pythagorean triplet product is : " << a* b*(1000 - a - b) << std::endl;
	return 1;
}

