#ifndef OPTGETTER_TAGGEDOPTGETTER
#define OPTGETTER_TAGGEDOPTGETTER

#include <map>
#include <vector>
#include <utility>

#include "OptGetter.hpp"

namespace optg
{

	class TaggedOptGetter : public OptGetter
	{

		public:

			TaggedOptGetter(int, char **, std::vector<std::pair<std::string, PType> >);

			TaggedOptGetter(int, char **, std::vector<TaggedParameterLabel>);

			~TaggedOptGetter();

			CommentedParameter GetParameter(int);

			CommentedParameter GetParameter(std::string);

			CommentedParameter operator [](int);

			CommentedParameter operator [](std::string);			

			void Print();

		protected:

			std::map<std::string, CommentedParameter *> mParameters;

	};

}

#endif
