#ifndef OPTGETTER_COMMENTEDPARAMETER
#define OPTGETTER_COMMENTEDPARAMETER

#include "Parameter.hpp"

namespace optg
{

	class CommentedParameter : public Parameter
	{

		public:

			CommentedParameter(const char *, PType);

			CommentedParameter(const char *, PType, std::string, std::string);

			~CommentedParameter();

			std::string GetName();

			std::string GetComment();

			void Print();

		private:

			std::string mName;
			std::string mComment;

	};

}

#endif