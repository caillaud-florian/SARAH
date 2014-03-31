/**
 * \file		GraphicHandler.hpp
 * \author		fcaillaud
 * \version 	1.0
 * \date     	28 Mars 2014
 * \brief     	Fichier décrivant la classe GraphicHandler.
 * \details		Classe utilisée comme base de la stratégie MVC au sein de SARAH. Elle permet
 *				de gérer/regrouper les différentes fenêtres ou IHM. Il est conseillé d'hériter 
 *				de cette classe pour personnalisé son fonctionnement tout en usant de la 
 *				structure qu'il forme avec ModelHandler et ControlerHandler.
 */

#ifndef GRAPHICHANDLER
#define GRAPHICHANDLER

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include "GeneralConfig.hpp"

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
	 * \class 	GraphicHandler
	 * \brief	Classe GraphicHandler permettant de gérer les modules liée à l'interface de la plateforme SARAH.
	 * \see 	ModelHandler ControlerHandler
	 */
	class GraphicHandler
	{

		/**
		 * \brief 	La classe EventBinder est en ami pour pouvoir accéder librement à GraphicHandler et ses fenêtres.
		 * \todo 	Voir comment ne plus avoir besoin de cette amitié plus ou moins anormale.
		 */
		friend class EventBinder;

		/**
		 * \brief 	La classe GraphicHandlerBuilder est en ami pour pouvoir accéder librement à GraphicHandler.
		 * \todo 	Voir comment ne plus avoir besoin de cette amitié plus ou moins anormale.
		 */
		friend class GraphicHandlerBuilder;

		/**
		 * \brief 	La classe ControlerHandler est en ami pour pouvoir accéder librement à GraphicHandler.
		 * \todo 	Voir comment ne plus avoir besoin de cette amitié plus ou moins anormale.
		 */
		template<class M, class G, class E> friend class ControlerHandler;

		public:

			/**
			 * Constructeur par défaut.
			 */
			GraphicHandler();

			/**
			 * Constructeur paramétré.
			 * \details	Construction à partir d'une configuration générale.
			 * \param 	p_gConfig 	Objet représentant une configuration générale 
			 *						et avec lequel on initialise le handler.
			 */
			GraphicHandler(GeneralConfig &);

			/**
			 * Destructeur.
			 */
			~GraphicHandler();

			/**
			 * Initialisation de l'interface de la plateforme (virtuelle).
			 * \return 	true si l'initialisation s'est bien passée, false sinon.
			 */
			virtual bool Init();

			/**
			 * Mise à jour de la fenêtre sélectionnée à l'aide de gConfig.
			 */
			void WindowUpdate();

		public:

			/**
			 * \brief 	Configuration générale l'interface de la plateforme.
			 * \details	Mise à disposition de l'utilisateur (public) pour consultation 
			 * 			ou changement (alors ne pas oublier de faire un GeneralConfigUpdate).
			 */
			GeneralConfig gConfig;

		protected:

			/**
			 * \brief 	Fenêtre sélectionnée (de type SFML Window).
			 */
			sf::Window m_focusedWindow;

			/**
			 * \brief 	Horloge permettant un contexte temporel principal (de type SFML Clock).
			 */
			sf::Clock m_generalClock;

	};

}
}

#endif
