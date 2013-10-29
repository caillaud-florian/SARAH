#include "Utilities/BasicTypeOperations/BasicNumberOperation.hpp"

#define BNO_QUASI_NULL 0.00000001

namespace gu
{

	int Sign(double pNumber)
	{
		return (pNumber > 0)? 1 : -1;
	}

	unsigned int NbFractDigit(double pNumber)
	{
		int vIntDust, i = 0;
		double vIntPart, vFractPart;
		vFractPart = modf(pNumber, &vIntPart);

		if(vFractPart == 0.0)
			return 0;

		modf(vFractPart, &vIntPart);

		while(fabs(vFractPart - vIntPart) > BNO_QUASI_NULL){
			vFractPart *= 10;
			//Get the possible IntPart due to convertion
			vIntDust = modf(vFractPart, &vIntPart) + BNO_QUASI_NULL * Sign(pNumber);
			vIntPart += vIntDust;
			++i;
		}

		return i;
	}

	unsigned int NbIntDigit(int pNumber)
	{
		if(pNumber == 0)
			return 1;

		int i = 0;
		while(pNumber != 0){
			pNumber /= 10;
			++i;
		}

		return i;
	}

	unsigned int NbDigit(double pNumber)
	{
		return NbIntDigit(pNumber) + NbFractDigit(pNumber);
	}

	unsigned int NbAlpha(double pNumber)
	{
		std::string vStr;
		std::ostringstream vOss;

		vOss << pNumber;
		vStr = vOss.str();

		return vStr.size();
	}

	double Truncate(double pNumber, unsigned int pNbLeftFractDigit)
	{
		double vIntPart, vFractPart;
		vFractPart = modf(pNumber, &vIntPart);

		if(pNbLeftFractDigit == 0)
			return pNumber;

		if(pNbLeftFractDigit > NbDigit(vFractPart) - 1)
			Truncate(pNumber, NbDigit(vFractPart) - 1);

		vFractPart *= pow(10, pNbLeftFractDigit);
		vFractPart = floor(vFractPart);
		vFractPart /= pow(10, pNbLeftFractDigit);

		return vIntPart + vFractPart;
	}

}