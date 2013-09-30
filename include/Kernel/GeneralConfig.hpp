#ifndef GENERAL_CONFIG
#define GENERAL_CONFIG

#include <string>
#include <map>
#include <vector>
#include <utility>

#include "Kernel/Config.hpp"

namespace Sarah
{
namespace Kernel
{

	typedef Sarah::Kernel::Config 		Config;

	class GeneralConfig
	{

		public:

			GeneralConfig();

			GeneralConfig(std::map<std::string, Config *>);

			GeneralConfig(std::vector<Config *>);

			~GeneralConfig();

			Config * GetConfig(std::string);

			bool AddConfig(Config *);

		private:

			std::map<std::string, Config *> m_configMap;

	};

}
}

#endif