#ifndef GENERAL_UTLITIES_BASICNUMBEROPERATION
#define GENERAL_UTLITIES_BASICNUMBEROPERATION

#include <iostream>
#include <sstream>
#include <cmath>

namespace gu
{

	int Sign(double);

	//TODO : to be reviewed cause it do not detect over 16 fract digit (due to the int/double convertion)
	unsigned int NbFractDigit(int);

	unsigned int NbIntDigit(int);

	unsigned int NbDigit(double);

	unsigned int NbAlpha(double);

	double Truncate(double, unsigned int);

}

#endif
