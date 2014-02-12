/**
 * \file		ControlerHandler.hpp
 * \author		fcaillaud
 * \version 	0.1
 * \date     	28 Octobre 2013
 * \brief     	Fichier implémentant le controleur de la plateforme SARAH.
 * \detail		Cet objet représente la partie CONTROLLEUR au sein de la plateforme lors de l'execution
 *				sert à gérer les différents modules de la plateforme.
 */

#ifndef CONTROLERHANDLER
#define CONTROLERHANDLER

#include <map>

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include "Kernel/GeneralConfig.hpp"
#include "Kernel/GraphicHandler.hpp"
#include "Kernel/ModelHandler.hpp"
#include "Kernel/GraphicHandlerBuilder.hpp"

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
	 * \typedef	\a Kernel::GeneralConfig devient \a GeneralConfig pour plus de simplicité pour l'utilisateur.
	 */
	typedef Kernel::GeneralConfig GeneralConfig;

	/**
	 * \class 	Classe ControlerHandler permettant de gérer tous les modules de la plateforme.
	 */
	class ControlerHandler
	{
		public:

			/**
			 * \typedef 	Un dictionnaire de noms associés à des valeur est une \a Section
			 */
			typedef std::map<std::string, std::string> 	ConfigMap;
			/**
			 * \typedef 	Un dictionnaire de noms associés à une section est une \a Config décrite par le fichier INI
			 */
			typedef std::map<std::string, ConfigMap>  	GeneralConfigMap;

		public:

			/*
			 * \fn 		Constructeur par défaut
			 */
			ControlerHandler();

			/*
			 * \fn 		Constructeur paramétré
			 * \detail 	Construction à partir d'une configuration générale.
			 * \param 	p_generalConfig 	Objet représentant une configuration générale 
			 *			et avec lequel on initialise le controleur.
			 */
			ControlerHandler(GeneralConfig &);

			ControlerHandler(GeneralConfigMap &);

			/**
			 * \fn 		Destructeur
			 */
			~ControlerHandler();

			/**
			 * \fn 		Initialisation de la plateforme SARAH
			 * \return 	true si l'initialisation s'est bien passée, false sinon.
			 */
			bool Init();

			/**
			 * \fn 		Boucle principale d'évènements
			 * \return 	true si la boucle a été quittée correctement, false sinon.
			 */
			bool MainLoop();

		protected:

			sf::Window & GetWindow();

		public:

			/**
			 * \brief 	Configuration générale de la plateforme
			 * \detail 	Mise à disposition de l'utilisateur (public) pour consultation 
			 * 			ou changement (alors ne pas oublier de faire un GeneralConfigUpdate).
			 */
			GeneralConfig gConfig;

		private:

			GraphicHandler m_graphicHandler;

			ModelHandler m_modelHandler;
			/**
			 * \brief 	Horloge permettant un contexte temporel principal (de type SFML Clock).
			 */
			sf::Clock m_generalClock;

	};

}
}

#endif