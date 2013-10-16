#ifndef INICONFIGREADER
#define INICONFIGREADER

#include <map>
#include <string>

#include "Reader/Reader.hpp"

typedef std::map<std::string, std::string> 	Properties;
typedef std::map<std::string, Properties>  	Config;

namespace Utils
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

#endif