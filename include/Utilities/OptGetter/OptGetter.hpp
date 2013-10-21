#ifndef OPTGETTER_OPTGETTER
#define OPTGETTER_OPTGETTER

#include "CommentedParameter.hpp"

#define VERBOSE_OPT

namespace optg
{

	struct ParameterLabel
	{
		std::string mName;
		PType 		mPType;
		std::string mComment;
	};

	struct TaggedParameterLabel
	{
		std::string mName;
		std::string mTag;
		PType 		mPType;
		bool		mRequire;
		std::string mComment;
	};

	class OptGetter
	{

		public:

			OptGetter(){}

			~OptGetter(){}

			virtual CommentedParameter GetParameter(int) = 0;

			virtual CommentedParameter operator [](int) = 0;

			virtual void Print() = 0;

	};

}

#endif