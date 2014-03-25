#ifndef GRAPHICHANDLER
#define GRAPHICHANDLER

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include "GeneralConfig.hpp"

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
	 * \class 	Classe GraphicHandler permettant de gérer les modules liée à l'interface de la plateforme.
	 */
	class GraphicHandler
	{
		friend class EventBinder;
		template<class M, class G, class E> friend class ControlerHandler;
		friend class GraphicHandlerBuilder;

		public:

			/*
			 * \fn 		Constructeur par défaut
			 */
			GraphicHandler();

			/*
			 * \fn 		Constructeur paramétré
			 * \detail 	Construction à partir d'une configuration générale.
			 * \param 	p_generalConfig 	Objet représentant une configuration générale 
			 *			et avec lequel on initialise le handler.
			 */
			GraphicHandler(GeneralConfig &);

			/**
			 * \fn 		Destructeur
			 */
			~GraphicHandler();

			/**
			 * \fn 		Initialisation de l'interface de la plateforme
			 * \return 	true si l'initialisation s'est bien passée, false sinon.
			 */
			virtual bool Init();

			void WindowUpdate();

		public:

			/**
			 * \brief 	Configuration générale l'interface de la plateforme
			 * \detail 	Mise à disposition de l'utilisateur (public) pour consultation 
			 * 			ou changement (alors ne pas oublier de faire un GeneralConfigUpdate).
			 */
			GeneralConfig gConfig;

		protected:

			/**
			 * \brief 	Fenêtre principale (de type SFML Window).
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
