#include "CommentedParameter.hpp"

namespace optg
{

	CommentedParameter::CommentedParameter(const char * pValue, PType pType):
		Parameter(pValue, pType),
		mName("undefined"),
		mComment("undefined")
	{
		//EMPTY
	}

	CommentedParameter::CommentedParameter(const char * pValue, PType pType, std::string pName, std::string pComment):
		Parameter(pValue, pType),
		mName(pName),
		mComment(pComment)
	{
		//EMPTY
	}

	CommentedParameter::~CommentedParameter()
	{
		//EMPTY
	}


	std::string CommentedParameter::GetName()
	{
		return mName;
	}

	std::string CommentedParameter::GetComment()
	{
		return mComment;
	}

	void CommentedParameter::Print()
	{
		if(mName.compare("undefined"))
			std::cout << mName << " : ";

		std::cout << mStrValue;

		if(mComment.compare("undefined"))
			std::cout << " --> " << mComment;
	}

}
