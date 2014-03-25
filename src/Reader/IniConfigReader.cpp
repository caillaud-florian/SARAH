#include "IniConfigReader.hpp"

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
		boost::smatch vMatches;
		const boost::regex vSectRegex("\\s*\\[.+\\]\\s*");
		std::string vLine;
		std::string vCurrentSection = "undefined";
		std::vector<std::string> vPropertyLine;
		std::string vPropertyName, vPropertyValue;

		while(GetLine(vLine))
		{
			vNumLine++;
			//Si la ligne n'est pas un commentaire (# .... ou ; ....)
			if( ! (gu::IsComments(vLine, '#') || gu::IsComments(vLine, ';')) )
			{				
				if(boost::regex_match(vLine, vMatches, vSectRegex))
				{
					if(vMatches.size() == 1)
					{
						vCurrentSection = gu::WithoutChar(gu::WithoutChar(vMatches[0], ']'), '[');
						vCurrentSection = gu::WithoutFrontSpace(gu::WithoutBackSpace(vCurrentSection));
						m_config.insert(std::pair<std::string, Section>(vCurrentSection, Section()));
					}
					else
					{
						msg::Msg_Spe(msg::MSG_FLAG_ENUM::ERROR, "Error in IniConfigReader.Read : Line ", vNumLine, " -> Wrong Syntax in Section Declaration");
						exit(-1);
					}
				}
				else
				{
					vLine = gu::WithoutComments(gu::WithoutComments(vLine, '#'), ';');

					vPropertyLine = gu::Split(vLine, '=');

					if(vPropertyLine.size() == 2)
					{
						vPropertyName = gu::WithoutFrontSpace(gu::WithoutBackSpace(vPropertyLine[0]));
						vPropertyValue = gu::WithoutFrontSpace(gu::WithoutBackSpace(vPropertyLine[1]));

						m_config[vCurrentSection].insert(std::pair<std::string, std::string>(vPropertyName, vPropertyValue));
					}
					else
					{
						//TODO : peut être gérer quand même l'erreur au lieu d'exit
						msg::Msg_Spe(msg::MSG_FLAG_ENUM::ERROR, "Error in IniConfigReader.Read : Line ", vNumLine, " -> Wrong Syntax in Property Declaration");
						exit(-1);
					}
				}
			}
		}

		return HasSucceed();
	}

	IniConfigReader::Config IniConfigReader::GetConfig() const
	{
		return m_config;
	}
	
}
}
