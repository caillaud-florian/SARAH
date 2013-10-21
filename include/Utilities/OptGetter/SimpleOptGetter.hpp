#ifndef OPTGETTER_SIMPLEOPTGETTER
#define OPTGETTER_SIMPLEOPTGETTER

#include <vector>

#include "OptGetter.hpp"

namespace optg
{

	class SimpleOptGetter : public OptGetter
	{

		public:

			SimpleOptGetter(int, char **, std::vector<PType>, int pNbRequiredParam = -1);

			SimpleOptGetter(int, char **, std::vector<ParameterLabel>, int pNbRequiredParam = -1);

			~SimpleOptGetter();

			CommentedParameter GetParameter(int);

			CommentedParameter operator [](int);

			void Print();

		protected:

			std::vector<CommentedParameter *> mParameters;

	};

}

#endif