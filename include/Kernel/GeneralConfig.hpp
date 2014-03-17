/**
 * \file		GeneralConfig.hpp
 * \author		fcaillaud
 * \version 	0.1
 * \date     	28 Octobre 2013
 * \brief     	Fichier implémentant un contener de configuration.
 */

#ifndef GENERAL_CONFIG
#define GENERAL_CONFIG

#include <string>
#include <map>
#include <vector>
#include <utility>

#include "Kernel/Config.hpp"

/**
 * \namespace 	Nom de domaine principal.
 */
namespace Sarah
{
/**
 * \namespace 	Nom de domaine secondaire, partie coeur.
 */
namespace Kernel
{

	/**
	 * \class 	Classe représentant un conteneur de configuration 
	 * 			qui permet une centralisation des données.
	 */
	class GeneralConfig
	{
		
			typedef Sarah::Kernel::BaseConfig 		BaseConfig;

		public:
			
			/**
			 * \fn 		Constructeur par défaut
			 */
			GeneralConfig();

			/**
			 * \fn 		Constructeur paramétré
			 * \param 	p_mapConfig 	Conteneur prérempli de configuration
			 */
			GeneralConfig(std::map<std::string, BaseConfig *>);

			/**
			 * \fn 		Constructeur paramétré
			 * \param 	p_vecConfig 	Conteneur prérempli de configuration
			 */
			GeneralConfig(std::vector<BaseConfig *>);

			/**
			 * \fn 		Destructeur
			 */
			~GeneralConfig();

			/**
			 * \fn 		Accesseur permettant de récupérer une configuration à l'aide de son nom
			 * \param 	p_configName 	Nom de la configuration à récupérer
			 * \return 	La configuration nommée \a p_ConfigName si elle existe, nullptr sinon.
			 */
			BaseConfig * GetConfig(std::string);

			/**
			 * \fn 		Fonction ajoutant une configuration au conteneur
			 * \param 	p_Config 	La configuration à ajouter
			 * \return 	true si elle n'existait pas déjà, false sinon.
			 */
			bool AddConfig(BaseConfig *);

		private:

			/**
			 * \brief 	Le conteneur de configuration de type générique BaseConfig.
			 */
			std::map<std::string, BaseConfig *> m_configMap;

	};

}
}

#endif
