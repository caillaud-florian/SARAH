#include "Kernel/GeneralConfig.hpp"

namespace Sarah
{
namespace Kernel
{
	
	GeneralConfig::GeneralConfig():
		m_configMap()
	{

	}

	GeneralConfig::GeneralConfig(std::map<std::string, Config *> p_configMap):
		m_configMap(p_configMap)
	{

	}

	GeneralConfig::GeneralConfig(std::vector<Config *> p_configVect)
	{
		for(Config * c : p_configVect)
			m_configMap.insert(std::pair<std::string, Config *>(c->GetName(), c));
	}

	GeneralConfig::~GeneralConfig()
	{

	}

	Config * GeneralConfig::GetConfig(std::string p_str)
	{	
		std::map<std::string, Config *>::iterator it;
		if( (it = m_configMap.find(p_str)) != m_configMap.end() )
			return it->second;
		return nullptr;
	}

	bool GeneralConfig::AddConfig(Config * p_config)
	{
		return m_configMap.insert(std::pair<std::string, Config *>(p_config->GetName(), p_config))
			.second;
	}

}	
}