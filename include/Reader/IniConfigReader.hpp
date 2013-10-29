#ifndef INICONFIGREADER
#define INICONFIGREADER

#include <map>
#include <vector>
#include <string>

#include "Reader/Reader.hpp"

typedef std::map<std::string, std::string> 	Section;
typedef std::map<std::string, Section>  	Config;

namespace Sarah
{
	
namespace IO
{

	class IniConfigReader : public Reader
	{

		public:

			IniConfigReader(std::string);

			virtual bool Read();

			Config GetConfig() const;

		private:

			Config m_config;

	};
	
}

}

#endif