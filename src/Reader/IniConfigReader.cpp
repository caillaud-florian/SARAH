#include "Reader/IniConfigReader.hpp"

namespace Utils
{

	IniConfigReader::IniConfigReader(std::string filePath):
		Reader(filePath)
	{

	}

	bool IniConfigReader::Read()
	{
		std::smatch vStrMatch;
		std::string vLine;
		std::string vCurrentSection = "undefined";

		//TODO: éliminer les commentaires
		while(GetLine(vLine))
		{
			if(std::regex_match(vLine, vStrMatch, std::regex("[(.+)]") ))
			{
				if(vStrMatch.size() == 1)
				{
					vCurrentSection = vStrMatch[0];
					m_config.insert(std::pair<std::string, Section>(vCurrentSection, Section()));
				}
				else
				{
					std::cout << "erreur" << std::endl;
				}
			}
			else
			{
				//Faire un split de la ligne
				//Faire un nettoyage du premier terme par la droite
				//Faire un nettoyage du deuxième terme par la gauche
				//m_config[vCurrentSection].insert(pair(gauche, droite));
			}
		}

		return HasSucceed();
	}

	Config IniConfigReader::GetConfig() const
	{
		return m_config;
	}
	
}