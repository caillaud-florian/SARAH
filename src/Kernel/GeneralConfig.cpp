#include "Kernel/GeneralConfig.hpp"

namespace Sarah
{
namespace Kernel
{
	
	GeneralConfig::GeneralConfig():
		m_configMap()
	{

	}

	GeneralConfig::GeneralConfig(std::map<std::string, BaseConfig *> p_configMap):
		m_configMap(p_configMap)
	{

	}

	GeneralConfig::GeneralConfig(std::vector<BaseConfig *> p_configVect)
	{
		for(BaseConfig * c : p_configVect)
			m_configMap.insert(std::pair<std::string, BaseConfig *>(c->GetName(), c));
	}

	GeneralConfig::~GeneralConfig()
	{

	}

	BaseConfig * GeneralConfig::GetConfig(std::string p_str)
	{	
		std::map<std::string, BaseConfig *>::iterator it;
		if( (it = m_configMap.find(p_str)) != m_configMap.end() )
			return it->second;
		return nullptr;
	}

	bool GeneralConfig::AddConfig(BaseConfig * p_config)
	{
		return m_configMap.insert(std::pair<std::string, BaseConfig *>(p_config->GetName(), p_config))
			.second;
	}

}	
}