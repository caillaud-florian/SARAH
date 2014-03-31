/**
 * \file		GeneralConfig.hpp
 * \author		fcaillaud
 * \version 	0.1
 * \date     	28 Octobre 2013
 * \brief     	Fichier implémentant un contener de configuration.
 * \details		Classe principale de gestion de toutes les configurations différentes associées à un objet 
 * 				(e.g. GraphicHandler ou ModelHandler)
 */

#ifndef GENERALCONFIG
#define GENERALCONFIG

#include <string>
#include <map>
#include <vector>
#include <utility>

#include "Config.hpp"

/**
 * \namespace 	Sarah 	
 * \brief 		Nom de domaine principal.
 */
namespace Sarah
{

/**
 * \namespace 	Kernel	
 * \brief 		Nom de domaine secondaire, partie coeur.
 */
namespace Kernel
{

	/**
	 * \class 	GeneralConfig
	 * \brief 	Classe représentant un conteneur de configuration 
	 * 			qui permet une centralisation des données.
	 */
	class GeneralConfig
	{

		public:
			
			/**
			 * Constructeur par défaut.
			 */
			GeneralConfig();

			/**
			 * Constructeur paramétré.
			 * \param 	p_configMap 	Conteneur pré-rempli de configuration.
			 */
			GeneralConfig(std::map<std::string, BaseConfig *>);

			/**
			 * Constructeur paramétré.
			 * \param 	p_configVect 	Conteneur pré-rempli de configuration.
			 */
			GeneralConfig(std::vector<BaseConfig *>);

			/**
			 * Destructeur.
			 */
			~GeneralConfig();

			/**
			 * Récupération d'une configuration à l'aide de son nom.
			 * \param 	p_configName 	Nom de la configuration à récupérer.
			 * \return 	La configuration nommée p_ConfigName si elle existe, nullptr sinon.
			 */
			BaseConfig * GetConfig(std::string);

			/**
			 * Ajout d'une configuration au conteneur.
			 * \param 	p_config 	La configuration à ajouter.
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
