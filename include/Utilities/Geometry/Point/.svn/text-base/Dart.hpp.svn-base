//TODO : opération sur les brin alphaO, alpha1, alpha2, ...
//		 PLUS la partie v['x', 'z', 'y'] .....
#ifndef GEOMETRY_DART
#define GEOMETRY_DART

#include <iostream>

namespace geo
{

	template<int DIM = 3>
	class Dart
	{

		public:

			Dart()
			{
				for(int i = 0; i < DIM + 1; ++i)
					rel[i] = nullptr;
			}

			template <typename ...PDART >
			Dart(PDART ... pTail)
			{
				
			}

		private:

			Dart * rel[DIM + 1];
			
	};

}

#endif