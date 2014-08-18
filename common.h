#include <iostream>
#include <sstream>
#include <string>
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
