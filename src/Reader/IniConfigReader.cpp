#include "Reader/IniConfigReader.hpp"

namespace Utils
{

	IniConfigReader::IniConfigReader(std::string filePath):
		Reader(filePath)
	{

	}

	bool IniConfigReader::Read()
	{
		//TODO: écrire le parser de fichier ini
		return true;
	}

	Config IniConfigReader::GetConfig() const
	{
		return m_config;
	}
	
}