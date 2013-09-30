#ifndef CONFIG
#define CONFIG

#include <string>

namespace Sarah
{
namespace Kernel
{
	
	class Config
	{

		public:

			virtual std::string GetName() const = 0;

	};

}
}

#endif

//TODO : faire une config pour la fenêtre ! et ainsi mieux définir la class Config !