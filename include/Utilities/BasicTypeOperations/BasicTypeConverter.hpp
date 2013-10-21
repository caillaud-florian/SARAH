#ifndef GENERAL_UTLITIES_BASICTYPECONVERTER
#define GENERAL_UTLITIES_BASICTYPECONVERTER

#include <cstring>
#include <cstdio>
#include <iostream>
#include <cctype>

namespace gu
{
	//======================== char * to others ==========================

	char AtoChar(const char * pA);

	std::string AtoString(const char * pA);

	bool AtoBool(const char * pA);

	int AtoInt(const char * pA);

	unsigned int AtoUInt(const char * pA);

	short int AtoSInt(const char * pA);

	long int AtoLInt(const char * pA);

	long long int AtoLLInt(const char * pA);

	double AtoDouble(const char * pA);

	long double AtoLDouble(const char * pA);

	float AtoFloat(const char * pA);

	char * AtoLower(const char * pA);

	char * AtoUpper(const char * pA);
	
}

#endif