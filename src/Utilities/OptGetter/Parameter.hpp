#ifndef OPTGETTER_PARAMETER
#define OPTGETTER_PARAMETER

#include <string>
#include "../BasicTypeOperations/BasicTypeConverter.hpp"

namespace optg
{

	enum PType{
		VOID,
		CHAR,
		PCHAR,
		STRING,
		BOOL,
		INT,
		UINT,
		SINT,
		LINT,
		LLINT,
		DOUBLE,
		LDOUBLE,
		FLOAT
	};

	class Parameter
	{

		public:

			Parameter(const char *, PType);

			~Parameter();

			template<typename ParamType>
			ParamType GetValue() const
			{
				return *((ParamType *)mValue);
			}

			std::string GetStrValue();

			PType GetType();

			template<typename ParamType>
			void operator >> (ParamType & pValue)
			{
				pValue = *((ParamType *)mValue);
			}

		protected:

			void * mValue;
			std::string mStrValue;
			PType mType;

	};

	std::string GetTypeName(PType);

}

#endif
