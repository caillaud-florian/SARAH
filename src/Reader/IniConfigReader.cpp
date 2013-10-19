#include "Reader/IniConfigReader.hpp"

namespace Utils
{

	IniConfigReader::IniConfigReader(std::string filePath):
		Reader(filePath)
	{

	}

	bool IniConfigReader::Read()
	{
		std::string vCurrentSection = "undefined";

		while(m_file.good())
		{
			//On lit une ligne avec un fonction getLine(pointer sur fonction de détection de commentaire, ou caractère(s) de commentaire)
			std::cout << "lecture" << std::endl;
		}

		if(!m_file.good()){
			//TODO : faire une fonction dans Reader pour répertorier les erreurs survenus
			std::cout << "pas ok" << std::endl;
		}

		return true;
	}

	Config IniConfigReader::GetConfig() const
	{
		return m_config;
	}
	
}