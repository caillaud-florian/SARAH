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

#include "GeneralConfig.hpp"
#include "GraphicHandler.hpp"
#include "ModelHandler.hpp"
#include "GraphicHandlerBuilder.hpp"
#include "EventBinder.hpp"

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
	template <typename _ModelHandlerType, typename _GraphicHandlerType, typename _EventBinderType>
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
			ControlerHandler():
			    gConfig(),
				m_graphicHandler(),
			    m_modelHandler(),
			    m_eventBinder(m_graphicHandler, m_modelHandler),
				m_generalClock()
			{

			}

			/*
			 * \fn 		Constructeur paramétré
			 * \detail 	Construction à partir d'une configuration générale.
			 * \param 	p_generalConfig 	Objet représentant une configuration générale 
			 *			et avec lequel on initialise le controleur.
			 */
			ControlerHandler(GeneralConfig & p_gConfig):
			    gConfig(p_gConfig),
				m_graphicHandler(p_gConfig),
			    m_modelHandler(p_gConfig),
			    m_eventBinder(m_graphicHandler, m_modelHandler),
				m_generalClock()
			{

			}

			ControlerHandler(GeneralConfigMap & p_gConfig):
			    gConfig(),
			    m_graphicHandler(),
			    m_modelHandler(),
			    m_eventBinder(m_graphicHandler, m_modelHandler),
			    m_generalClock()
			{
			    GraphicHandlerBuilder graphicBuilder;
			    graphicBuilder(p_gConfig, m_graphicHandler);    
			}

			/**
			 * \fn 		Destructeur
			 */
			~ControlerHandler(){}

			/**
			 * \fn 		Initialisation de la plateforme SARAH
			 * \return 	true si l'initialisation s'est bien passée, false sinon.
			 */
			bool Init()
			{
				m_modelHandler.AddObserver(& m_graphicHandler);

			    return (m_graphicHandler.Init() && m_modelHandler.Init());
			}

			/**
			 * \fn 		Boucle principale d'évènements
			 * \return 	true si la boucle a été quittée correctement, false sinon.
			 */
			bool MainLoop()
			{
				m_modelHandler.Draw();

			    // TODO : plutot tant qu'il y a une fenêtre d'ouverte !
			    while (GetFocusedWindow().isOpen())
			    {
			        // gère les évènements
			        m_eventBinder.Bind();

			        if(!m_eventBinder.IsPaused())
			        {

			            // Clear the color and depth buffers
			            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			            // Apply some transformations to rotate the cube
			            glMatrixMode(GL_MODELVIEW);
			            glLoadIdentity();
			            glTranslatef(0.f, 0.f, -200.f);
			            glRotatef(m_generalClock.getElapsedTime().asSeconds() * 50, 1.f, 0.f, 0.f);
			            glRotatef(m_generalClock.getElapsedTime().asSeconds() * 30, 0.f, 1.f, 0.f);
			            glRotatef(m_generalClock.getElapsedTime().asSeconds() * 90, 0.f, 0.f, 1.f);
				

			            // Draw the cube
			            glDrawArrays(GL_TRIANGLES, 0, 36);

			            // Finally, display the rendered frame on screen
			            GetFocusedWindow().display();
			        }
			    }

				return true;
			}

		protected:

			sf::Window & GetFocusedWindow()
			{
			    return m_graphicHandler.m_focusedWindow;
			}

		public:

			/**
			 * \brief 	Configuration générale de la plateforme
			 * \detail 	Mise à disposition de l'utilisateur (public) pour consultation 
			 * 			ou changement (alors ne pas oublier de faire un GeneralConfigUpdate).
			 */
			GeneralConfig gConfig;

		private:

			_GraphicHandlerType m_graphicHandler;

			_ModelHandlerType m_modelHandler;

			_EventBinderType m_eventBinder;

			/**
			 * \brief 	Horloge permettant un contexte temporel principal (de type SFML Clock).
			 */
			sf::Clock m_generalClock;

	};

}
}

#endif
