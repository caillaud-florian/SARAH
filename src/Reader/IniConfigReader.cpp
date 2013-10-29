#include "Reader/IniConfigReader.hpp"

namespace Sarah
{
	
namespace IO
{

	IniConfigReader::IniConfigReader(std::string p_filePath):
		BaseReader(p_filePath)
	{

	}

	bool IniConfigReader::Read()
	{
		unsigned int vNumLine = 0;
		std::smatch vStrMatch;
		std::string vLine;
		std::string vCurrentSection = "undefined";
		std::vector<std::string> vPropertyLine;
		std::string vPropertyName, vPropertyValue;

		//TODO: éliminer les commentaires
		while(GetLine(vLine))
		{
			vNumLine++;

			if( ! (gu::IsComments(vLine, '#') || gu::IsComments(vLine, ';')) )
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
						msg::Msg_Spe(msg::MSG_FLAG_ENUM::ERROR, "Error : Line ", vNumLine, " : Wrong Syntax in Section Declaration");
						exit(-1);
					}
				}
				else
				{
					vLine = gu::WithoutComments(gu::WithoutComments(vLine, '#'), ';');

					vPropertyLine = gu::Split(vLine, '=');

					if(vPropertyLine.size() == 2)
					{
						vPropertyName = gu::WithoutBackSpace(vPropertyLine[0]);
						vPropertyValue = gu::WithoutFrontSpace(vPropertyLine[1]);

						m_config[vCurrentSection].insert(std::pair<std::string, std::string>(vPropertyName, vPropertyValue));
					}
					else
					{
						//TODO : peut être gérer quand même l'erreur au lieu d'exit
						msg::Msg_Spe(msg::MSG_FLAG_ENUM::ERROR, "Error : Line ", vNumLine, " : Wrong Syntax in Property Declaration");
						exit(-1);
					}
				}
			}
		}

		return HasSucceed();
	}

	Config IniConfigReader::GetConfig() const
	{
		return m_config;
	}
	
}

}